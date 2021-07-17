package actions

import (
	"fmt"
	"io"
	"net/http"
	"strconv"
	"strings"

	"github.com/google/go-github/v37/github"
)

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

func GetProblemScoresThisWeek(p params, issueNumber int) ([]int, error) {
	issue, err := getIssue(p, issueNumber)
	if err != nil {
		return []int{}, err
	}

	levelScoreMapping := getLevelScoreMapping(issue.GetBody())
	latestComment, err := getLatestIssueCommentOfIssue(p, issue)
	if err != nil {
		return []int{}, err
	}

	return getProblemScoreThisWeek(latestComment, levelScoreMapping), nil
}

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

func getProblemScoreThisWeek(commentOfProblem *github.IssueComment, levelScoreMapping map[string]int) []int {
	problemScores := []int{}
	for _, line := range strings.Split(strings.TrimRight(commentOfProblem.GetBody(), "\n"), "\n") {
		line = strings.TrimSpace(strings.ToLower(line))
		for level, score := range levelScoreMapping {
			if strings.HasPrefix(line, fmt.Sprintf("%s:", level)) {
				problemScores = append(problemScores, score)
				break
			}
		}

	}
	return problemScores
}

func CalculateUserScore(pr *github.PullRequest, problemScores []int) (int, error) {
	if pr.Body == nil {
		return 0, nil
	}
	indexProblemScores := 0
	score := 0

	for _, line := range strings.Split(strings.TrimRight(getStrFromPtr(pr.Body), "\n"), "\n") {
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
