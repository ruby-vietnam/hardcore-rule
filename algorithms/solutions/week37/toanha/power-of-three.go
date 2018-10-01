package main

import (
	"fmt"
	"math"
)

// recursion solution
// func isPowerOfThree(n int) bool {
//   if n == 0 {
//     return false
//   }

//   if n == 1 {
//     return true
//   }

//   i := n % 3

//   if i > 0 {
//     return false
//   }

//   return isPowerOfThree(n/3)
// }

// Non recursion solution
func isPowerOfThree(n int) bool {
	return n > 0 && int64(math.Pow(3, 19))%int64(n) == 0
}

func main() {
	fmt.Println(isPowerOfThree(27) == true)
}
