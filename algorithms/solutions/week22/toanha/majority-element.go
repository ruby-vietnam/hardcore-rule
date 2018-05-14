package main

func majorityElement(nums []int) int {
	n := len(nums) / 2
	m := make(map[int]int)
	for i := 0; i < len(nums); i++ {
		m[nums[i]]++
		if value, ok := m[nums[i]]; ok {
			if value > n {
				return nums[i]
			}
		}
	}

	return -1
}
