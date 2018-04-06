## Problem 1

```golang
func swap(arr []int, i, j int) {
  arr[i], arr[j] = arr[j], arr[i]
}

func moveZeroes(nums []int) {
  var idx int
  for i := 0; i < len(nums); i++ {
    if nums[i] != 0 {
      swap(nums, i, idx)
      idx++
    }
  }
}
```

## Problem 2

```golang
func min(a, b int) int {
  if a < b {
    return a
  }
  return b
}

func nthUglyNumber(n int) int {
  var ugly = make([]int, n)
  var i2, i3, i5 int
  var next_multiple_of_2 = 2
  var next_multiple_of_3 = 3
  var next_multiple_of_5 = 5
  var next_ugly_no = 1

  ugly[0] = 1
  for i := 1; i < n; i++ {
    next_ugly_no = min(next_multiple_of_2, min(next_multiple_of_3, next_multiple_of_5))
    ugly[i] = next_ugly_no
    if next_ugly_no == next_multiple_of_2 {
      i2 = i2 + 1
      next_multiple_of_2 = ugly[i2] * 2
    }
    if next_ugly_no == next_multiple_of_3 {
      i3 = i3 + 1
      next_multiple_of_3 = ugly[i3] * 3
    }
    if next_ugly_no == next_multiple_of_5 {
      i5 = i5 + 1
      next_multiple_of_5 = ugly[i5] * 5
    }
  }
  return next_ugly_no
}
```
