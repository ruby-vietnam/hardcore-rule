## Problem 1

```go
func shiftArray(nums []int, i, lastPosition int) {
	value := nums[i]
	for j := i; j < lastPosition; j++ {
		nums[j] = nums[j+1]
	}
	nums[lastPosition] = value
}

func moveZeroes(nums []int) {
	size := len(nums)
	lastPosition := size - 1
	for i := size - 1; i >= 0; i-- {
		if nums[i] == 0 {
			shiftArray(nums, i, lastPosition)
			lastPosition--
		}
	}
}
```


### Problem 2

We have a[n] = x * a[i] where x in (2, 3, 5)
So, to find a[n], we only need to store 3 values a[i] which is used to create
a[n - 1], a[n - 2], a[n - 3]

```
func min2(a, b int) int {
	if a < b {
		return a
	}
	return b
}

func min(a, b, c int) int {
	return min2(a, min2(b, c))
}

func nthUglyNumber(n int) int {
	u := 1
	nums := []int{1}
	i1, i2, i3 := 0, 0, 0
	for i := 0; i < n; i++ {
		u1, u2, u3 := nums[i1]*2, nums[i2]*3, nums[i3]*5
		u = min(u1, u2, u3)
		if u == u1 {
			i1++
		}
		if u == u2 {
			i2++
		}
		if u == u3 {
			i3++
		}
		nums = append(nums, u)
	}
	return nums[n-1]
}
```