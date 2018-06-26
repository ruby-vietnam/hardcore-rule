func xorGame(nums []int) bool {
    if (len(nums) % 2 == 0) {
		return true
	}

	x := 0
	for _, num := range nums {
		x ^= num
	}

	return x == 0
}
