# 136. Single Number

```go
func singleNumber(nums []int) int {
    a := 0
    for _, n := range nums {
        a = a ^ n
    }
    return a
}
```
