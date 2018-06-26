Problem 1:

https://leetcode.com/problems/non-decreasing-array/description/

```go
func checkPossibility(nums []int) bool {
    if len(nums) < 3 {
        return true
    }
    
    isFirst := false
    for index := 0; index < len(nums); index++ {
        if index >= len(nums) - 1 || nums[index] <= nums[index + 1] {
            continue
        }
        if isFirst {
            return false
        }
        isFirst = true
        if (index < len(nums) - 2 && nums[index] > nums[index + 2]) && 
            (index > 0 && nums[index - 1] > nums[index + 1]) {
            return false
        }
    }
    return true
}
```
