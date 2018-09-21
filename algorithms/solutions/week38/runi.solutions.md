## Problem 1

https://leetcode.com/problems/path-sum-iii

```go
 func pathSum(root *TreeNode, sum int) int {
	if root == nil {
		return 0
	}
 	return pathSumSubstract(root, sum) + pathSum(root.Left, sum) + pathSum(root.Right, sum)
}
 func pathSumSubstract(root *TreeNode, sum int) int {
	if root == nil {
		return 0
	}

 	if root.Val == sum {
        return 1 + pathSumSubstract(root.Left, sum - root.Val) +  pathSumSubstract(root.Right, sum - root.Val)
	}
     return pathSumSubstract(root.Left, sum - root.Val) +  pathSumSubstract(root.Right, sum - root.Val)
}
```
