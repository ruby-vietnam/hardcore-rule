Problem 1:

https://leetcode.com/problems/move-zeroes

```go
func moveZeroes(nums []int) {
    if len(nums) == 0 {
		return
	}
    
    var notZero int
    for i, _ := range nums {
        if nums[i] != 0 {
            nums[notZero] = nums[i]
            notZero++
        }
    }
    
    for notZero < len(nums) {
        nums[notZero] = 0
        notZero++
    }
	
}

```
