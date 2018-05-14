Problem 1: 

Use counter:
```go
func majorityElement(nums []int) int {
    var maybeMajor, count int
    for _, num := range nums {
        if 0 == count {
            maybeMajor = num
            count++
        } else if maybeMajor == num {
            count++
        } else {
            count --
        }
    }
    return maybeMajor
}
```

Use map:
```go
func majorityElement(nums []int) int {
    n := len(nums) / 2
    m := make(map[int]int)
    for _, num := range nums {
        m[num] = m[num] + 1
        if m[num] > n {
            return num
        }
    }
    return -1
}
```
