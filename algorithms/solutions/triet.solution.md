Problem 1:

```
func getRow(rowIndex int) []int {
	k := rowIndex + 1
	resp := make([]int, k)
	if k == 1 {
		resp[0] = 1
		return resp
	}
	if k == 2 {
		resp[0] = 1
		resp[1] = 1
		return resp
	}

	// init for k > 2, start from row 2
	resp[0] = 1
	resp[1] = 1

	index := 2
	for i := index; i < k; i++ {
		first := 1
		second := resp[1]
		for j := 1; j < i+1; j++ {
			t := resp[j]
			resp[j] = first + second
			first = t
			if j+1 < i {
				second = resp[j+1]
			} else {
				second = 0
			}
		}
		resp[i] = 1
	}

	return resp
}
```

