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

Problem 3:

https://leetcode.com/problems/daily-temperatures/description/

```go
func dailyTemperatures(temperatures []int) []int {
    processing := make([]int, len(temperatures))
    stack := make([]int, len(temperatures))
    top := -1
    for i := range temperatures {
        for top >= 0 && temperatures[stack[top]] < temperatures[i] {
            processing[stack[top]] = i - stack[top]
            top--
        }
        top++
        stack[top] = i
    }
    return processing
}
```
