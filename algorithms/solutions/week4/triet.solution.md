## Problem 2
```
func sortColors(nums []int) {
	m := map[int]int{}

	for _, num := range nums {
		m[num] += 1
	}

	colorIndex := 0
	for i, _ := range nums {
		count, exists := m[colorIndex]
		if exists && count > 0 {
			m[colorIndex] -= 1
		} else {
			for {
				colorIndex += 1
				if _, exists := m[colorIndex]; exists {
					m[colorIndex]--
					break
				}
			}
		}
		nums[i] = colorIndex
	}
}
```
