## Problem 1

https://leetcode.com/problems/longest-harmonious-subsequence/description/

Just count the apperances of all numbers in the array. The result is the max of apperances of k plus appearances of k + 1

```golang
func findLHS(nums []int) int {
    counts := map[int]int{};
    for _, value := range nums {
        _, exist := counts[value]
        if exist {
            counts[value] += 1;
        } else {
            counts[value] = 1;
        }
    }
    max := 0
    for _, value := range nums {
        count, exist := counts[value + 1]
        if exist {
            if counts[value] + count > max {
                max = counts[value] + count
            }
        }
    }
    return max
}
```

## Problem 2

https://leetcode.com/problems/merge-two-binary-trees/description/

Recursively merge left and right.

```golang
/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func mergeTrees(t1 *TreeNode, t2 *TreeNode) *TreeNode {
    if t1 == nil && t2 == nil {
        return nil;
    } else if t1 == nil {
        return t2;
    } else if t2 == nil {
        return t1;
    } 
    newNode := &TreeNode{
        Val: t1.Val + t2.Val,
    }
    newNode.Left = mergeTrees(t1.Left, t2.Left);
    newNode.Right = mergeTrees(t1.Right, t2.Right);
    return newNode;
}
```

## Problem Bonus

https://leetcode.com/problems/number-of-longest-increasing-subsequence/description/

This is an advance of LIS problem. We'll have 1 extra array `M` to store the number of longest subsequence ending ending at i. Then, we got recursive equation:

```
T[i] = T[j] + 1
M[i] += M[j]
```

```golang
func findNumberOfLIS(nums []int) int {
    T := make([]int, len(nums))
    M := make([]int, len(nums))
    for i := range nums {
        T[i] = 1
        M[i] = 1
        for j := i - 1; j >= 0; j-- {
            if nums[j] < nums[i] {
                if T[i] < T[j] + 1 {
                    T[i] = T[j] + 1
                    M[i] = M[j]
                } else if T[i] == T[j] + 1 {
                    M[i] += M[j]
                }
            }
        }
    }
    max := 0
    maxCount := 0
    fmt.Println(T)
    fmt.Println(M)
    for i := range nums {
        if max < T[i] {
            max = T[i]
            maxCount = M[i]
        } else if max == T[i] {
            maxCount += M[i]
        }
    }
    return maxCount
}
```
