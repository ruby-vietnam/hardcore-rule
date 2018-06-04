package main

import (
	"fmt"
	"math"
)

func judgeSquareSum(c int) bool {
	a, b := 0, int(math.Sqrt(float64(c)))

	for a <= b {
		if a*a+b*b == c {
			return true
		} else if a*a+b*b < c {
			a++
		} else if a*a+b*b > c {
			b--
		}
	}
	return false
}

func main() {
	fmt.Println(judgeSquareSum(25) == true)
	fmt.Println(judgeSquareSum(15) == false)
}
