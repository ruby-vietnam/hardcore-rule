# Problem 2

```go
func binarySearchRow(arr []int, target int) bool {
    left, right := 0, len(arr) -1

    for left <= right {
        mid := (left + right) / 2
        if arr[mid] == target {
            return true
        }
        
        if arr[mid] < target {
            left = mid + 1
        } else {
            right = mid -1
        }
    }

    if left >= 0 && left < len(arr) && arr[left] == target {
        return true
    }

    return false
}

func searchMatrix(matrix [][]int, target int) bool {
  for i := 0; i < len(matrix); i++ {
     if len(matrix[i]) != 0 && matrix[i][0] > target {
      return false
    }

    if binarySearchRow(matrix[i], target) {
      return true
    }
  }
  
  return false
}
```
