# Problem 1: [Majority Element](https://leetcode.com/problems/majority-element/description/)

## Solution 1:
```go
func majorityElement(nums []int) int {
	count, result, max := make(map[int]int), 0, 0

	for _, v := range nums {
		count[v]++
	}

	for k, v := range count {
		if v > len(nums)/2 && v > max {
			result = k
			max = v
		}
	}
	return result
}
```

## Solution 2:
```go
func majorityElement(nums []int) int {
	data, count := 0, 0
	for i := 0; i < len(nums); i++ {
		if count == 0 {
			data = nums[i]
		}

		if nums[i] == data {
			count++
		} else {
			count--
		}
	}
	return data
}
```

# Problem 2: [Bulb Switcher](https://leetcode.com/problems/bulb-switcher/description/)

```go
func bulbSwitch(n int) int {
    return int(math.Sqrt(float64(n)))
}
```
