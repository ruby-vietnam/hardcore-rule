## Problem 2

```golang
package main

import "fmt"

func visit(i int, isVisit []bool, M [][]int, size int) {
	isVisit[i] = true
	for j := 0; j < size; j++ {
		if M[i][j] == 1 && !isVisit[j] {
			visit(j, isVisit, M, size)
		}
	}
}

func findCircleNum(M [][]int) int {
	count := 0
	size := len(M)
	isVisit := make([]bool, size)
	for i := 0; i < size; i++ {
		if isVisit[i] {
			continue
		}
		count++
		visit(i, isVisit, M, size)
	}

	return count
}

func main() {
	fmt.Println(findCircleNum([][]int{
		[]int{1, 1, 0},
		[]int{1, 1, 0},
		[]int{0, 0, 1},
	}))
	fmt.Println(findCircleNum([][]int{
		[]int{1, 1, 0},
		[]int{1, 1, 1},
		[]int{0, 1, 1},
	}))
}

```