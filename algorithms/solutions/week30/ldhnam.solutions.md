```go
func miniMaxSum(arr []int32) {
	var sum int64
	var a []int64
	for _, value := range arr {
		sum += int64(value)
		a = append(a, int64(value))
	}

	n := len(a)
	for i := 0; i < n-1; i++ {
		min := i
		for j := i + 1; j < n; j++ {
			if a[j] < a[min] {
				min = j
			}
		}

		a[i], a[min] = a[min], a[i]
	}

	result := fmt.Sprintf("%d %d", sum-int64(a[len(a)-1]), sum-int64(a[0]))
	fmt.Println(result)
}
```