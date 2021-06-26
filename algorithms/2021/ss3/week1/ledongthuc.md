# 1. Toeplitz Matrix

https://leetcode.com/problems/toeplitz-matrix

## 1.1. First approach: Summary

 - Go through items of first rows and first column
 - With each item, check next diagonal items [ (+1,+1), (+2, +2), ... ] are match with it. If any item is not match with first item, the matrix is not toeplitz

![](https://raw.githubusercontent.com/ledongthuc/notes/master/leetcode/toeplitz-matrix/1_col.png)
![](https://raw.githubusercontent.com/ledongthuc/notes/master/leetcode/toeplitz-matrix/1_row.png)

## 1.2. First approach: Code

```go
func isToeplitzMatrix(matrix [][]int) bool {
    rowL := len(matrix)
    colL := len(matrix[0])
    
    for i := 0; i < colL; i++ {
        if !isValidDiagonalLine(matrix, 0, i, rowL-1, colL-1) {
           return false 
        }
    }

    for i := 0; i < rowL; i++ {
        if !isValidDiagonalLine(matrix, i, 0, rowL-1, colL-1) {
           return false 
        }
    }
    
    return true
}

func isValidDiagonalLine(matrix [][]int, row, col, maxRow, maxCol int) bool {
    v := matrix[row][col]
    for {
        if row > maxRow || col > maxCol {
            return true
        }
        if matrix[row][col] != v {
            return false
        }
        row++
        col++
    }
} */
```

## 1.3. Second approach: Summary

 - Go through items of matrix, one by one from start to end.
 - With each item, it should match with previous diagonal item (-1,-1)

## 1.4. Second approach: Code

```go
func isToeplitzMatrix(matrix [][]int) bool {
    rowL := len(matrix)
    colL := len(matrix[0])
    for row := 0; row < rowL; row++ {
        for col := 0; col < colL; col++ {
            if row > 0 && col > 0 && matrix[row-1][col-1] != matrix[row][col] {
                return false
            }
        }
    }

    return true
}
```

# 2. Group Anagrams

https://leetcode.com/problems/group-anagrams

## 2.1. Summary

 - Use hash map to store anagrams
 - With each item in input array, we sort it as key of hash map
 - Collect all anagrams from hash map

## 2.2. Code

```go
func groupAnagrams(strs []string) [][]string {
    r := map[string][]string{}
    for _, str := range strs {
        k := SortString(str)
        r[k] = append(r[k], str)
    }
    
    result := make([][]string, 0, len(r))
    for _, arr := range r {
        result = append(result, arr)
    }
    return result
}

type sortRunes []rune

func (s sortRunes) Less(i, j int) bool {
    return s[i] < s[j]
}

func (s sortRunes) Swap(i, j int) {
    s[i], s[j] = s[j], s[i]
}

func (s sortRunes) Len() int {
    return len(s)
}

func SortString(s string) string {
    r := []rune(s)
    sort.Sort(sortRunes(r))
    return string(r)
}
```

# 3. Partition List

https://leetcode.com/problems/partition-list

## 3.1. Summary

We need pointers:
 - `current` is current item checking
 - `previous` is previous item of current checking item
 - `lastFirstPartition` is last item of first part (aka. partition of item that's less than x)

Go through item from linked list, action depends on scenario:

### 3.1.1.  Value is greater than or equal x
- Do nothing

### 3.1.2. Value is less than x, and it's head
- Track current item is `lastFirstPartition`

### 3.1.3. Value is less than x, and previous is first partition (aka. partition of item that's less than x)
 - Move `lastFirstPartition` to current item

### 3.1.4. Value is less than x, and didn't see any item that's less than x yet
 - Move current item to head. Last head will be second.
 - Track current item (now is head) is `lastFirstPartition`

### 5. Value is less than x, and we have any items that's less than x already
 - Move current item to next of `lastFirstPartition`. Current item will be new `lastFirstPartition`

## 3.2. Code

```go
/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func partition(head *ListNode, x int) *ListNode {
    current := head
    var lastFirstPartition *ListNode
    var previous *ListNode
    
    for current != nil {
        switch {
            case current.Val >= x:
                // do nothing here
            case previous == nil, lastFirstPartition != nil && lastFirstPartition.Next == current:
                lastFirstPartition = current
            case lastFirstPartition == nil:
                previous.Next = current.Next
                previousHead := head
                head = current
                head.Next = previousHead
                lastFirstPartition = current
            case lastFirstPartition != nil:
                previous.Next = current.Next
                current.Next = lastFirstPartition.Next
                lastFirstPartition.Next = current
                lastFirstPartition = current
                current = previous
        }
        
        previous = current
        current = current.Next
    }
    return head
}
```
