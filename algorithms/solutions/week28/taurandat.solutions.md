# permutations

```go
func permute(num []int) [][]int{
    var helper func([]int, int)
    res := [][]int{}

    helper = func(num []int, n int){
        if n == 1{
            tmp := make([]int, len(num))
            copy(tmp, num)
            res = append(res, tmp)
        } else {
            for i := 0; i < n; i++{
                helper(num, n - 1)
                if n % 2 == 1{
                    tmp := num[i]
                    num[i] = num[n - 1]
                    num[n - 1] = tmp
                } else {
                    tmp := num[0]
                    num[0] = num[n - 1]
                    num[n - 1] = tmp
                }
            }
        }
    }

	helper(num, len(num))
    return res
}
```