## Problem 1 - [Path Sum III](https://leetcode.com/problems/path-sum-iii/description/)

```go
func pathSum(root *TreeNode, sum int) (total int) {
    if root == nil {
        return 0
    }
    return pathSumFrom(root, sum) + pathSum(root.Left, sum) + pathSum(root.Right, sum)
}

func pathSumFrom(root *TreeNode, sum int) (total int) {
    if root == nil {
        return 0
    }
    
    if root.Val == sum {
        total++
    }
    total += pathSumFrom(root.Left, sum - root.Val) + pathSumFrom(root.Right, sum - root.Val)
    
    return
}
```

## Problem 2 - [Search a 2D Matrix II](https://leetcode.com/problems/search-a-2d-matrix-ii/description/)

```go
func searchMatrix(matrix [][]int, target int) bool {
    if matrix == nil {
        return false
    }
    
    // check number of rows
    m := len(matrix)
    if m == 0 {
        return false
    }
    if matrix[0] == nil {
        return false
    }
    
    // check number of columns
    n := len(matrix[0])    
    if n == 0 {
        return false
    }
    
    i, j := 0, n-1
    for i < m && j >= 0 {
        if matrix[i][j] == target {
            return true
        }
        
        if matrix[i][j] < target {
            i++
        } else {
            j--
        }
    }
    
    return false
}
```

## Problem 3 - [Daily Temperatures](https://leetcode.com/problems/daily-temperatures/description/)

```java
class Solution {
    public int[] dailyTemperatures(int[] temperatures) {
        int[] stack = new int[temperatures.length];
        int top = -1;
        int[] ret = new int[temperatures.length];
        for(int i = 0; i < temperatures.length; i++) {
            while(top > -1 && temperatures[i] > temperatures[stack[top]]) {
                int idx = stack[top--];
                ret[idx] = i - idx;
            }
            stack[++top] = i;
        }
        return ret;
    }
}
```
