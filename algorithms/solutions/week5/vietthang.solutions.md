# Problem set #1

```go
func getRow(rowIndex int) []int {
    collection := []int{}
    for i := 0; i <= rowIndex; i++ {
        collection = append(collection, 1)
        for j := len(collection) - 2; j > 0; j-- {
            collection[j] = collection[j] + collection[j - 1]
        }
    }
    return collection
}
```

____