package actions

import (
	"reflect"
	"testing"
)

func Test_getUserMappingFromRaw(t *testing.T) {
	userMappingRaw := `
Wrong raw will be skipped
ledongthuc - @ledongthuc
 - huy - @huytd
thanh - thanh`

	want := map[string]string{
		"ledongthuc": "ledongthuc",
		"huy":        "huytd",
		// thanh is skipped because missing '@'
	}
	if got := getUserMappingFromRaw(userMappingRaw); !reflect.DeepEqual(got, want) {
		t.Errorf("getUserMappingFromRaw() = %v, want %v", got, want)
	}
}

func Test_getLevelScoreMapping(t *testing.T) {
	levelScoreMapping := `
Every week, we pick algorithm problems to solve and post them to this ticket.
At 00:00 on Sunday (VN time), we run an automation tool to merge solution PRs and collect scores. The score report will follow the problems.

Mapping of GitHub account and slack account is defined in https://github.com/ruby-vietnam/hardcore-rule/blob/master/algorithms/PARTICIPANTS.md

The source code of the automation tool is in https://github.com/ruby-vietnam/hardcore-rule/tree/master/algorithms/collector

Mapping of problem's level and the score is defined in this issue content.

*** Score mapping ***
Easy: 1
  Medium: 2
Hard:3
*** End score mapping ***
`

	want := map[string]int{
		"easy":   1,
		"medium": 2,
		"hard":   3,
	}
	if got := getLevelScoreMapping(levelScoreMapping); !reflect.DeepEqual(got, want) {
		t.Errorf("getLevelScoreMapping() = %v, want %v", got, want)
	}
}
