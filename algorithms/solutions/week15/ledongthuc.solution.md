Problem 1:

https://leetcode.com/problems/move-zeroes

```go
func moveZeroes(nums []int) {
    if len(nums) == 0 {
		return
	}
    
    var notZero int
    for i, _ := range nums {
        if nums[i] != 0 {
            nums[notZero] = nums[i]
            notZero++
        }
    }
    
    for notZero < len(nums) {
        nums[notZero] = 0
        notZero++
    }
	
}

```

Problem 2:

https://leetcode.com/problems/ugly-number-ii

```go
func nthUglyNumber(n int) int {
	list := make([]int, n, n)
	list[0] = 1
	factorIndex2, factorIndex3, factorIndex5 := 0, 0, 0

	for i := 1; i < n; i++ {
		var min int
		nextFactor2, nextFactor3, nextFactor5 := list[factorIndex2]*2, list[factorIndex3]*3, list[factorIndex5]*5
		if nextFactor2 <= nextFactor3 && nextFactor2 <= nextFactor5 {
			min = nextFactor2
			factorIndex2++
		}
		if nextFactor3 <= nextFactor2 && nextFactor3 <= nextFactor5 {
			min = nextFactor3
			factorIndex3++
		}
		if nextFactor5 <= nextFactor3 && nextFactor5 <= nextFactor2 {
			min = nextFactor5
			factorIndex5++
		}
		// fmt.Println(i, min, nextFactor2, nextFactor3, nextFactor5)
		list[i] = min
	}
	// fmt.Println(list)
	return list[n-1]
}
```
