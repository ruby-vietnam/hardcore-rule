package main

import (
	"fmt"
	"strings"

	log "github.com/sirupsen/logrus"

	"github.com/ruby-vietnam/hardcore-rule/algorithms/collector/actions"
)

const (
	mappingUsersURL   = "https://raw.githubusercontent.com/ruby-vietnam/hardcore-rule/master/algorithms/PARTICIPANTS.md"
	reportIssueNumber = 1408 // https://github.com/ruby-vietnam/hardcore-rule/issues/1408
)

func main() {
	p, err := actions.GetParams()
	if err != nil {
		panic(err)
	}

	pullRequests, err := actions.GetPullRequests(p)
	if err != nil {
		panic(err)
	}
	log.Infof("Prepare to process %d PR(s)", len(pullRequests))

	userMapping, err := actions.GetUserMapping(mappingUsersURL)
	if err != nil {
		panic(err)
	}

	problemScores, err := actions.GetProblemScoresThisWeek(p, reportIssueNumber)
	if err != nil {
		panic(err)
	}
	log.Infof("Problem score mapping this week: %+v", problemScores)

	result := map[string]int{}
	for _, pr := range pullRequests {
		if pr == nil || pr.Title == nil || pr.Body == nil {
			continue
		}

		if p.GetPRPrefix() != "" && !strings.HasPrefix(pr.GetTitle(), p.GetPRPrefix()) {
			continue
		}

		if pr.GetMerged() || pr.GetDraft() {
			continue
		}

		log.WithField("pr_user", pr.GetUser().GetLogin()).Info(" - Start process")

		userScore, err := actions.CalculateUserScore(pr, problemScores)
		if err != nil {
			err := actions.CommentPR(p, pr, err.Error())
			if err != nil {
				log.WithFields(log.Fields{"pr_user": pr.GetUser().GetLogin(), "action": "Reject PR: missing problems in description"}).Error(err)
			}
			continue
		}

		log.WithFields(log.Fields{"pr_user": pr.GetUser().GetLogin(), "score": userScore}).Info("   Processed")

		displayName := *pr.User.Login
		slackAccount, exist := userMapping[*pr.User.Login]
		if exist {
			displayName = "@" + slackAccount
		}

		err = actions.CommentPR(p, pr, fmt.Sprintf("🏅 You got %d point(s) this week!", userScore))
		if err != nil {
			log.WithField("action", "Comment PR: update score").Error(err)
			continue
		}
		result[displayName] = userScore

		err = actions.MergePR(p, pr)
		if err != nil {
			log.WithField("action", "Merge PR: failed. Please merge it manually").Error(err)
		}
	}

	log.WithFields(log.Fields{"total_user_report": len(result)}).Info("Final report")

	if len(result) == 0 {
		return
	}

	err = actions.ReportWeeklyResult(p, reportIssueNumber, result)
	if err != nil {
		log.WithField("action", "Report").Error(err)
		return
	}
}
