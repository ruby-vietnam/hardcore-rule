package actions

import (
	"fmt"
	"strings"
	"time"
)

func ReportWeeklyResult(p params, issueNumber int, result map[string]int) error {
	newContent := strings.Builder{}
	newContent.WriteString("**Scores:** \n")
	for user, score := range result {
		newContent.WriteString("\n- ")
		newContent.WriteString(user)
		newContent.WriteString(": ")
		newContent.WriteString(fmt.Sprintf("%d", score))
	}
	newContent.WriteString("\n\nReported at ")
	newContent.WriteString(time.Now().Format("2006/01/02"))
	return addIssueComment(p, issueNumber, newContent.String())
}
