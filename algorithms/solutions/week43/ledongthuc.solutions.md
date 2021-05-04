# Problem 3 

https://leetcode.com/problems/range-sum-query-immutable/

```go
type NumArray struct {
    s []int
}


func Constructor(nums []int) NumArray {
    cur := 0
    temp := []int{}
    for _, n := range nums {
        cur += n
        temp = append(temp, cur)
    }
    
    return NumArray{
        s: temp,
    }
}


func (this *NumArray) SumRange(i int, j int) int {
    prev := 0
    if i > 0 {
        prev = this.s[i-1]
    }
    
    return this.s[j] - prev
}
```
