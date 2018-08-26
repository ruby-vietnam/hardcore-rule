package main

import "fmt"

func climbStairs(n int) int {
	if n < 2 {
		return n
	}

	var n1, n2 = 1, 2

	for i := 2; i < n; i++ {
		n1, n2 = n2, n2+n1
	}

	return n2
}

func main() {
	fmt.Println(climbStairs(1) == 1)
	fmt.Println(climbStairs(2) == 2)
	fmt.Println(climbStairs(3) == 3)
	fmt.Println(climbStairs(4) == 5)
}
