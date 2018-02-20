Problem 1: https://leetcode.com/problems/longest-harmonious-subsequence

```go
func findLHS(nums []int) int {
	length := len(nums)
	if length < 2 {
		return 0
	}
	lengthOfSub := 0
	searching := make(map[int]int)
	for _, num := range nums {
		searching[num]++

	}
    
    for num := range searching {
        currentValue := searching[num]
        nextValue := searching[num+1]
        sum := currentValue + nextValue
        if currentValue >0 && nextValue > 0 && sum > lengthOfSub {
            lengthOfSub = sum
        }
    }
    
	return lengthOfSub
}
```
