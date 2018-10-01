## Problem 2
https://leetcode.com/problems/longest-substring-without-repeating-characters/description/

```go
func lengthOfLongestSubstring(s string) int {
	m := map[rune]int{} // char and last index
	max := 0
	sIndex := 0
	for i, c := range s {
		if mI, ok := m[c]; ok {
			// if exists and value < sIndex then skip
			if mI >= sIndex {
				// duplicated = end substring
				// Reset sIndex to the next index to last duplicated
				sIndex = mI + 1
			}
		}
		if max < i-sIndex+1 {
			max = i - sIndex + 1
		}

		m[c] = i
	}
  
	return max
}
```
