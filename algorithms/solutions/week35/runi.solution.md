## Problem 3

https://leetcode.com/contest/weekly-contest-97/problems/possible-bipartition/
```go

func possibleBipartition(N int, dislikes [][]int) bool {
	flags := make([][]bool, N)
	for i := 0; i < N; i++ {
		flags[i] = make([]bool, N)
	}

	for _, v := range dislikes {
		flags[v[0]-1][v[1]-1] = true
		flags[v[1]-1][v[0]-1] = true
	}

	arr := make([]int, N)

	for i := 0; i < N; i++ {
		if arr[i] == 0 && !dfs(i, arr, flags, 1) {
			return false
		}
	}

	return true
}

func dfs(index int, arr []int, flags [][]bool, group int) bool {
	if arr[index] != 0 {
		return arr[index] == group
	}

	arr[index] = group

	for i := range arr {
		if flags[index][i] && !dfs(index, arr, flags, -group) {
			return false
		}
	}

	return true
}
```
