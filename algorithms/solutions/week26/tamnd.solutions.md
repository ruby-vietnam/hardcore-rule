## Problem 1

```go
func findTheDifference(s string, t string) byte {
    n := len(s)
    var ret byte = 0
    for i := 0; i < n; i++ {
        ret = ret ^ s[i] ^ t[i]
    }
    ret ^= t[n]
    return ret
}
```

## Problem 2

```go
/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func levelOrder(root *TreeNode) [][]int {
    return traverse(root, 0, [][]int{})
}

func traverse(root *TreeNode, depth int, result [][]int) [][]int {
    if root == nil {
        return result
    }
    if len(result) == depth {
        result = append(result, []int{})
    }
    result[depth] = append(result[depth], root.Val)
    result = traverse(root.Left, depth + 1, result)
    result = traverse(root.Right, depth + 1, result)
    return result
}
```

## Problem 3

```go
func numSimilarGroups(A []string) int {
    parent := make(map[string]string)
    n := len(A)
    for i := 0; i < n; i++ {
        if _, found := parent[A[i]]; found {
            continue
        }
        parent[A[i]] = A[i]
        for j := 0; j < i; j++ {
            if similar(A[i], A[j]) && parent[A[j]] != A[i] {
                root := getRoot(A[j], parent)
                parent[root] = A[i]
            }
        }
    }
    count := 0
    for k, v := range parent {
        if k == v {
            count++
        }
    }
    return count
}

func getRoot(j string, parent map[string]string) string {
    if j != parent[j] {
        return getRoot(parent[j], parent)
    }
    return parent[j]
}

func similar(a string, b string) bool {
    n := len(a)
    if len(b) != n {
        return false
    }
    count := 0
    for i := 0; i < n; i++ {
        if a[i] != b[i] {
            count++
        }
    }
    return count == 2
}
```

## Problem 4

```go
func numberOfArithmeticSlices(A []int) int {
    ret := 0
    n := len(A)
    m := make([]map[int]int, n)
    for i := 0; i < n; i++ {
        m[i] = make(map[int]int)
        for j := 0; j < i; j++ {
            d := A[i] - A[j]
            ret += m[j][d]
            m[i][d] = m[i][d] + m[j][d] + 1
        }
    }
    return ret
}
```
