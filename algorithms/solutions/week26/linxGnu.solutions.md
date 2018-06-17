## Problem 1 - [Find the Difference](https://leetcode.com/problems/find-the-difference/description/)

```go
func findTheDifference(s string, t string) byte {
    counter := make([]int, 27)
    for _, c := range s {
        counter[c - 'a']++
    }
    
    for _, c := range t {
        counter[c - 'a']--
    }
    
    for i := range counter {
        if counter[i] != 0 {
            return byte(i) + 'a'
        }
    }
    
    return 0
}
```

## Problem 2 - [Binary Tree Level Order Traversal](https://leetcode.com/problems/binary-tree-level-order-traversal/description/)

```go
/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func levelOrder(root *TreeNode) (level [][]int) {
    level = make([][]int, 0, 10000)
    if root == nil {
        return
    }
    
    return travel(root, 0, level)
}

func travel(root *TreeNode, currentLevel int, level [][]int) [][]int {
    if len(level) <= currentLevel {
        level = append(level, make([]int, 0, 20))
    }
    
    if root.Left != nil {
        level = travel(root.Left, currentLevel + 1, level)
    }
    
    if root.Right != nil {
        level = travel(root.Right, currentLevel + 1, level)
    }
    
    level[currentLevel] = append(level[currentLevel], root.Val)
    return level
}
```

## Problem 3 - [Similar String Groups](https://leetcode.com/problems/similar-string-groups/description/)

```go
func numSimilarGroups(A []string) int {
    group := make([]int, len(A))
    for i := range group {
        group[i] = -1
    }
    
    var i, j int
    tmp := make([]int, 2)
    for i = 0; i < len(A); i++ {
        for j = i + 1; j < len(A); j++ {
            if isSimilar(A[i], A[j], tmp) {
                union(i, j, group)
            }
        }
    }
    
    counter := 0
    for i := range group {
        if group[i] == -1 {
            counter++
        }
    }
    return counter
}

func union(u, v int, group []int) {
    rootU, rootV := walkToRoot(u, group), walkToRoot(v, group)
    if rootU == rootV {
        return
    }
    
    group[rootV] = rootU
    compress(v, group, rootU)
}

func walkToRoot(u int, group []int) int {
    for group[u] != -1 {
        u = group[u]
    }
    return u
}

func compress(u int, group []int, root int) {
    var tmp int
    for group[u] != root {
        tmp = group[u]
        group[u] = root
        u = tmp
    }
}

func isSimilar(a, b string, c []int) bool {
    if len(a) != len(b) {
        return false
    }
    
    n := 0
    for i := range a {
        if a[i] != b[i] {
            if n > 1 {
                return false
            }
            c[n] = i
            n++
        }
    }
    
    return n == 0 || (n == 2 && a[c[0]] == b[c[1]] && a[c[1]] == b[c[0]])
}
```

## Problem 4 - [Arithmetic Slices II - Subsequence](https://leetcode.com/problems/arithmetic-slices-ii-subsequence/description/)

```go
func numberOfArithmeticSlices(A []int) (total int) {
    total = int(zeroRound(A))
    
    n := len(A)
    
    f1, f2 := make([]map[int]int, n), make([]map[int]int, n)
    for i := range f1 {
        f1[i], f2[i] = make(map[int]int, n), make(map[int]int, n)
    }
    
    var i, j, d, variant int
    for i = 0; i < n; i++ {
        for j = i + 1; j < n; j++ {
            if d = A[i] - A[j]; d != 0 {
                f1[i][d]++
            }
        }
    }
    
    for i = n - 3; i >= 0; i-- {
        for j = i + 1; j < n; j++ {
            if d = A[i] - A[j]; d != 0 {
                variant = f1[j][d] + f2[j][d]
                f2[i][d] += variant
                total += variant
            }
        }
    }
    
    return
}

func zeroRound(A []int) (sum uint) {
    counter := make(map[int]uint, len(A))
    for i := range A {
        counter[A[i]]++
    }
    
    for _, v := range counter {
        if v >= 3 {
            sum += (1 << v) - 1 - ((v * (v + 1)) >> 1);
        }
    }
    
    return sum
}
```
