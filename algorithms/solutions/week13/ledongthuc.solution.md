Problem 1:

https://leetcode.com/problems/maximum-product-of-three-numbers

```go
func maximumProduct(nums []int) int {
    arrLength := len(nums)
    if arrLength == 3 {
        return nums[0] * nums[1] * nums[2]
    }
    
    sort.Ints(nums)
    if nums[1] < 0  && (-nums[1]) * (-nums[0]) > nums[arrLength-2] * nums[arrLength-3] {
        return nums[arrLength-1] * nums[0] * nums[1]
    }
    
    return nums[arrLength-1] * nums[arrLength-2] * nums[arrLength-3]
}
```
