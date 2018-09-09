Problem 1:

https://leetcode.com/problems/path-sum-iii/description/

```go
func pathSum(root *TreeNode, sum int) int {
	if root == nil {
		return 0
	}
	return pathSumFrom(root, sum) + pathSum(root.Left, sum) + pathSum(root.Right, sum)
}

func pathSumFrom(root *TreeNode, sum int) int  {
	if root == nil {
		return 0
	}
	count := 0
	if root.Val == sum {
		count++
	}
	if root.Left != nil {
		count += pathSumFrom(root.Left, sum - root.Val)
	}
	if root.Right != nil {
		count += pathSumFrom(root.Right, sum - root.Val)
	}
	return count
}
```
