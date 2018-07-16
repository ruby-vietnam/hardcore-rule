package duythinht

matchingStrings(strings []string, queries []string) []int32 {
	c := make(map[string]int32)
	result := make([]int32,0)

	for _, s := range strings {
		c[s]++
	}

	for _, q := range queries {
		result = append(result, c[q])
	}
	return result
}
