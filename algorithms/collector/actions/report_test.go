package actions

import (
	"testing"
	"time"
)

func Test_buildWeeklyReportContent(t *testing.T) {
	rawResult := map[string]int{
		"ledongthuc": 10,
		"huytd":      11,
	}
	want := `Weekly Report:

- huytd: 11
- ledongthuc: 10

Reported at ` + time.Now().Format("2006/01/02")
	if got := buildWeeklyReportContent(rawResult); got != want {
		t.Errorf("buildWeeklyReportContent() = %v, want %v", got, want)
	}
}
