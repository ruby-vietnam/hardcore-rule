# Problem 1 - [Path Sum III](https://leetcode.com/problems/path-sum-iii/description/)

## Solution

```go
/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */

func pathSum(root *TreeNode, sum int) (total int) {
    if root == nil {
        return 0
    }
    return dfs(root, sum) + pathSum(root.Left, sum) + pathSum(root.Right, sum)
}
 func dfs(root *TreeNode, sum int) (total int) {
    if root == nil {
        return 0
    }
    
    if root.Val == sum {
        total++
    }
    total += dfs(root.Left, sum - root.Val) + dfs(root.Right, sum - root.Val)
    
    return
}
```

# Problem 2 - [Search a 2D Matrix II](https://leetcode.com/problems/search-a-2d-matrix-ii/description/)

## Solution

```go
func searchMatrix(matrix [][]int, target int) bool {
    m := len(matrix)
    if m == 0 {
        return false
    }
    n := len(matrix[0])
    if n == 0 {
        return false
    }
    r, c := 0, n - 1
    for r < m && c >= 0 {
        if target == matrix[r][c] {
            return true
        } 
        if target < matrix[r][c] {
            c--
        } else {
            r++
        }
    }
    return false
}
```

# Problem 3 - [Daily Temperatures](https://leetcode.com/problems/daily-temperatures/description/)

## Solution

Using Stack to define one list which is descending order list and all elements in stack are greater than tempertures[i]
- Time complexity: O(N)
- Space complexity: O(N)

```go
func dailyTemperatures(temperatures []int) []int {
    n := len(temperatures)
    
    res, st, top := make([]int, n), make([]int, n), 0
    for i := 0; i < n; i++ {
        for top > 0 && temperatures[i] > temperatures[st[top-1]] {
            res[st[top-1]] = i - st[top-1]
            top--
        }
        st[top] = i
        top++
    }
    return res
}
```