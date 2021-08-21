# Easy: Check If String Is a Prefix of Array

https://leetcode.com/problems/check-if-string-is-a-prefix-of-array/

### Approach

Keep concatening items in `words` and compare with `s` per concatenation. If the concat string is equal to `s` then return true, otherwise keep looping and return false if no match found.

### Code

```go
func isPrefixString(s string, words []string) bool {
	res := ""
	for _, w := range words {
		res += w
		if res == s {
			return true
		}
	}
	return false
}
```

Time complexity: O(words.length), space complexity: O(s.length).

### Submission Detail

```
349 / 349 test cases passed.
Status: Accepted
Runtime: 0 ms
Memory Usage: 3.7 MB
```

# Medium: Array With Elements Not Equal to Average of Neighbors

https://leetcode.com/problems/array-with-elements-not-equal-to-average-of-neighbors/

### Code

```go
import "sort"

func rearrangeArray(nums []int) []int {
	sort.Ints(nums)
	res := []int{}
	l, r := 0, len(nums)-1
	for len(res) != len(nums) {
		res = append(res, nums[l])
		l += 1
		if l <= r {
			res = append(res, nums[r])
			r -= 1
		}
	}
	return res
}
```

Time complexity: O(nlogn).

### Submission Detail

```
249 / 249 test cases passed.
Status: Accepted
Runtime: 493 ms
Memory Usage: 11.6 MB
```
