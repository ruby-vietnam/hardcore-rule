package main

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

func rob(nums []int) int {
	length := len(nums)
	if length == 0 {
		return 0
	}

	if length == 1 {
		return nums[0]
	}

	arr := make([]int, length)
	arr[0] = nums[0]
	arr[1] = max(nums[0], nums[1])

	for i := 2; i < length; i++ {
		arr[i] = max(arr[i-1], arr[i-2]+nums[i])
	}

	return arr[length-1]
}

func main() {

}
