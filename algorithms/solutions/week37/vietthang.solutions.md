# Problem 1

```go
func isPowerOfThree(n int) bool {
    return n > 0 && 1162261467 % n == 0
}
```

#Problem 2

```go
func findIndex(arr []int , k int) int {
  l, r := 0, len(arr) - 1

  for l <= r {
    mid := (l + r) / 2

    if arr[mid] < k {
      l = mid + 1
    } else {
      r = mid - 1
    }
  }

  if arr[l] == k {
    return l
  } else {
    if l < r {
      return l
    } else {
      return r
    }
  }
}

func findClosestElements(arr []int, k int, x int) []int {
    res := []int{}
    idx := findIndex(arr, x)
    lo, hi := 1, 1

    for i := 0; lo + hi <= k; i++ {
      l := idx - lo
      h := idx + hi

      if arr[l] - x <= arr[h] - x || h > len(arr) - 1 {
        res = append(res, arr[l])
        lo++
      }
      if arr[h] - x >= arr[l] - x || l < 0 {
        res = append(res, arr[h])
        hi++
      }
    }

    sort.Slice(res, func(i, j int) bool {
      return res[i] < res[j]
    })

    return res
}
```
