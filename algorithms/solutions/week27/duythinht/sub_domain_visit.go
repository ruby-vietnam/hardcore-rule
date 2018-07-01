package duythinht

import (
	"fmt"
	"strconv"
	"strings"
)

func subdomainVisits(cpdomains []string) []string {
	count := make(map[string]int)
	for _, cpdomain := range cpdomains {
		countVisit(count, cpdomain)
	}
	return formatResult(count)
}

func formatResult(count map[string]int) []string {
	result := make([]string, 0)
	for k, v := range count {
		result = append(result, fmt.Sprintf("%d %s", v, k))
	}
	return result
}

func countVisit(count map[string]int, cpdomain string) {
	nextSliceIndex := strings.IndexByte(cpdomain, ' ')
	num, _ := strconv.Atoi(cpdomain[:nextSliceIndex])
	for {
		cpdomain = cpdomain[nextSliceIndex+1:]
		count[cpdomain] += num
		nextSliceIndex = strings.IndexByte(cpdomain, '.')
		if nextSliceIndex == -1 {
			break
		}
	}
}
