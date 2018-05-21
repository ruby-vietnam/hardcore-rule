## Problem 1

```golang
func majorityElement(nums []int) int {
	count := make(map[int]int)
	for _, num := range nums {
		_, ok := count[num]
		if ok {
			count[num]++
		} else {
			count[num] = 1
		}
	}

	size := len(nums)
	for k, v := range count {
		if v > size/2 {
			return k
		}
	}

	return -1
}
```