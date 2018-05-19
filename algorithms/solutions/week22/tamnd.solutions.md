### Problem 1

```go
func majorityElement(nums []int) int {
    val := 0
    count := 0
    for i := 0; i < len(nums); i++ {
        if count == 0 {
            val = nums[i]
        }
        if nums[i] == val {
            count++
        } else {
            count--
        }
      
    }
    return val
}
```
