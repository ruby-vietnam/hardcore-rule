package actions

import (
	"fmt"
	"sort"
	"strings"
	"time"
)

// ReportWeeklyResult build report content and add a comment to algorithm issue
func ReportWeeklyResult(p params, issueNumber int, result map[string]int) error {
	return addIssueComment(p, issueNumber, buildWeeklyReportContent(result))
}

type resultItem struct {
	name  string
	score int
}

// buildWeeklyReportContent sorts the result, and compose report
func buildWeeklyReportContent(result map[string]int) string {
	var oResult []resultItem
	for name, score := range result {
		oResult = append(oResult, resultItem{
			name:  name,
			score: score,
		})
	}
	sort.SliceStable(oResult, func(i, j int) bool {
		return oResult[i].score > oResult[j].score
	})

	newContent := strings.Builder{}
	newContent.WriteString("Weekly Report:\n")
	for _, item := range oResult {
		newContent.WriteString("\n- ")
		newContent.WriteString(item.name)
		newContent.WriteString(": ")
		newContent.WriteString(fmt.Sprintf("%d", item.score))
	}
	newContent.WriteString("\n\nReported at ")
	newContent.WriteString(time.Now().Format("2006/01/02"))
	return newContent.String()
}
