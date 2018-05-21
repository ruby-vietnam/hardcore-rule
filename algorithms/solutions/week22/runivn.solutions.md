## Problem 1

https://leetcode.com/problems/majority-element/description/

```go
func majorityElement(nums []int) int {
	var a int
	count := 0
	for i := range nums {
		if count == 0 {
			a = nums[i]
			count++
		} else if a == nums[i] {
			count++
		} else {
			count--
		}
	}

	return a
}
```

## Problem 2
https://leetcode.com/problems/bulb-switcher/description/

- bulb i will be on if the number of divisor of i is odd.
- the number of divisor of i always %2 == 0 (prime number also has 1 and it self), unless it is a square number. It has sqrt()* sqrt() counted as 1 divisor.

=> Only bulb i which is square number can be able to be on.

```go
func bulbSwitch(n int) int {
    return int(math.Sqrt(float64(n)))
}
```
