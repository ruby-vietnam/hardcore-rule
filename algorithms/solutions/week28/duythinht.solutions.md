#### Problem 2

https://leetcode.com/problems/permutations/description/

```Go
func permute(nums []int) [][]int {
    if len(nums) == 1 {
        return [][]int{nums}
    }
    
    result := make([][]int,0)
    
	for i := 0; i < len(nums); i++ {
		nums[0], nums[i] = nums[i], nums[0]
		for _, per := range permute(nums[1:]) {
			result = append(result, append([]int{nums[0]}, per...))
		}
		nums[0], nums[i] = nums[i], nums[0]
	}
	return result
}
```
