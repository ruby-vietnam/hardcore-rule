package actions

import (
	"fmt"
	"io"
	"net/http"
	"strconv"
	"strings"

	"github.com/google/go-github/v37/github"
)

/*GetUserMapping makes a HTTP request to get user mapping file content.
The file contains key-value pairs of <github-account> - <slack-acount>, that's used to showing in weekly report */
func GetUserMapping(mappingUsersURL string) (map[string]string, error) {
	response, err := http.Get(mappingUsersURL)
	if err != nil {
		return map[string]string{}, err
	}
	defer response.Body.Close()

	raw, err := io.ReadAll(response.Body)
	if err != nil {
		return map[string]string{}, err
	}
	return getUserMappingFromRaw(string(raw)), nil
}

/*getUserMappingFromRaw goes through lines of user mapping file content, parse mappings between <github-account> and <slack-account> and finally put them to hash map.
Mapping between <github-account> and <slack-account> has structure:

<github-account> - @<slack-account>
ledongthuc - @ledongthuc
huy - @huytd

We accept the line that starts with ` - ` (bullet point)
*/
func getUserMappingFromRaw(mappingRaw string) map[string]string {
	result := map[string]string{}
	for _, line := range strings.Split(strings.TrimRight(mappingRaw, "\n"), "\n") {

		parts := strings.Split(line, " - @")
		if len(parts) != 2 {
			continue
		}

		githubAccount := strings.Trim(parts[0], " -")
		slackAccount := strings.Trim(parts[1], " -")
		result[githubAccount] = slackAccount
	}
	return result
}

/*GetProblemScoresThisWeek go to algorithm issue, get 2 main things:
- Level-score mapping: from first comment of algorithm issue
- Raw problems of latest week: from latest comment of algorithm issue
With them, the method calculate problem-score of this week.*/
func GetProblemScoresThisWeek(p params, issueNumber int) ([]int, error) {
	issue, err := getIssue(p, issueNumber)
	if err != nil {
		return []int{}, err
	}

	levelScoreMapping := getLevelScoreMapping(issue.GetBody())
	latestComment, err := getLatestIssueComment(p, issue)
	if err != nil {
		return []int{}, err
	}

	return getProblemScoreThisWeek(latestComment, levelScoreMapping), nil
}

/*getLevelScoreMapping go through lines of raw of level-score mapping, parsing it to hash map of <level> and <score>.
Structure of pair of <level>-score> is

<level>: <score>
hard: 3
medium: 2

The block's covered by

*** score mapping ***
<level>: <score>
<level>: <score>
<level>: <score>
*** end score mapping ***
*/
func getLevelScoreMapping(mappingRaw string) map[string]int {
	isScoreMappingArea := false
	result := map[string]int{}
	for _, line := range strings.Split(strings.TrimRight(mappingRaw, "\n"), "\n") {
		line = strings.TrimSpace(strings.ToLower(line))
		if line == "*** score mapping ***" {
			isScoreMappingArea = true
			continue
		}
		if line == "*** end score mapping ***" {
			break
		}
		if !isScoreMappingArea {
			continue
		}

		parts := strings.Split(line, ":")
		if len(parts) != 2 {
			continue
		}
		level := strings.TrimSpace(parts[0])
		score, _ := strconv.ParseInt(strings.TrimSpace(parts[1]), 10, 64)
		result[level] = int(score)
	}
	return result
}

/*getProblemScoreThisWeek go through lines of raw of weekly problem, check its level in level-score mapping to extract list weeklyscore.
Order of weekly score matches with order of weekly problems.*/
func getProblemScoreThisWeek(commentOfProblem *github.IssueComment, levelScoreMapping map[string]int) []int {
	problemScores := []int{}
	for _, line := range strings.Split(strings.TrimRight(commentOfProblem.GetBody(), "\n"), "\n") {
		line = strings.TrimSpace(strings.ToLower(line))
		for level, score := range levelScoreMapping {
			if strings.Contains(line, fmt.Sprintf("%s:", level)) {
				problemScores = append(problemScores, score)
				break
			}
		}

	}
	return problemScores
}

/*CalculateUserScore read the pull request description, parse problems and mapping their order with problem scores of this week.
Finally sum checked problem score. */
func CalculateUserScore(pr *github.PullRequest, problemScores []int) (int, error) {
	if pr.Body == nil {
		return 0, nil
	}
	indexProblemScores := 0
	score := 0

	for _, line := range strings.Split(strings.TrimRight(pr.GetBody(), "\n"), "\n") {
		line = strings.TrimSpace(strings.ToLower(line))
		if indexProblemScores >= len(problemScores) {
			break
		}

		if strings.Contains(line, "[x]") {
			score += problemScores[indexProblemScores]
			indexProblemScores++
			continue
		}
		if strings.Contains(line, "[]") || strings.Contains(line, "[ ]") {
			indexProblemScores++
			continue
		}
	}

	// We don't need to validate number of checkbox in PR compare to number of problems of the week
	// Someone frequently uses default PR template without changing
	// if indexProblemScores != len(problemScores) {
	// 	return score, fmt.Errorf("This week, we have %d problems. Could you update description with %d checkboxes [ ] or [x]. Currently they are only %d checkboxes", len(problemScores), len(problemScores), indexProblemScores)
	// }
	return score, nil
}
