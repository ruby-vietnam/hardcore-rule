## Problem 1

```go
package main

import "fmt"

func hammingDistance(x int, y int) int {
	result := 0
	for i := 0; i < 32; i++ {
		if x%2 != y%2 {
			result += 1
		}
		x = x / 2
		y = y / 2
	}
	return result
}

func main() {
	fmt.Println(hammingDistance(1, 4))
}
```