# Easy: two-sum
https://leetcode.com/problems/two-sum/

##mSubmission details:
```
53 / 53 test cases passed.
Status: Accepted
Runtime: 4 ms
Memory Usage: 3.2 MB
```
## implement
```Go
func twoSum(nums []int, target int) []int {
	m := make(map[int] int)

	for i := 0; i < len(nums); i++ {
		j, found := m[target - nums[i]]
		if found {
			return []int{i, j}
		}
		m[nums[i]] = i
	}
	return  []int{-1, -1}
}
```

# Easy: valid-parentheses
https://leetcode.com/problems/valid-parentheses/

## Submission details:
```
```
## Implement
```Go

```