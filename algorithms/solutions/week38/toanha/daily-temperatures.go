package main

import "fmt"

func dailyTemperatures(temperatures []int) []int {
	var l = len(temperatures)
	var top = -1
	var stack = make([]int, l)
	var result = make([]int, l)

	for i := 0; i < l; i++ {
		for top > -1 && temperatures[i] > temperatures[stack[top]] {
			result[stack[top]] = i - stack[top]
			top--
		}
		top++
		stack[top] = i
	}

	return result
}

func main() {
	// [1,1,4,2,1,1,0,0]
	fmt.Println(dailyTemperatures([]int{73, 74, 75, 71, 69, 72, 76, 73}))
}
