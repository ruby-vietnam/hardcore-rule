# Problem 1

```go
func singleNumber(nums []int) int {
    var r = 0
    for i := 0; i < len(nums); i++ {
        r ^= nums[i]
    }
    return r
}
```
