package main

import "fmt"

var maxInt32 = 1<<31 - 1
var minInt32 = -1 << 31

func reverse(x int) int {
	var r int
	for x != 0 {
		r = (r * 10) + (x % 10)
		x = x / 10
	}

	if r > maxInt32 || r < minInt32 {
		return 0
	}

	return r
}

func main() {
	fmt.Println(reverse(-123) == -321)
}
