# Season 4 - Week 3

### 1. Tree post-order traversal
- Problem: https://leetcode.com/problems/n-ary-tree-postorder-traversal/

```go
func postorder(root *Node) []int {
	result := make([]int, 0, 1)
	stack := make([]*Node, 0, 1)
	if root == nil {
		return result
	}

	stack = append(stack, root)
	for len(stack) > 0 {
		length := len(stack)
		temp := stack[length-1]
		stack = stack[:length-1]

		result = append(result, temp.Val)
		if temp.Children == nil {
			continue
		}
		for _, node := range temp.Children {
			stack = append(stack, node)
		}
	}

	for i, j := 0, len(result)-1; i < j; i, j = i+1, j-1 {
		result[i], result[j] = result[j], result[i]
	}

	return result
}
```

### 2. Tree pre-order traversal
- Problem: https://leetcode.com/problems/n-ary-tree-preorder-traversal/

``` go
func preorder(root *Node) []int {
	result := make([]int, 0, 1)
	stack := make([]*Node, 0, 1)

	if root == nil {
		return result
	}

	stack = append(stack, root)

	for len(stack) > 0 {
		length := len(stack)
		node := stack[length-1]
		stack = stack[:length-1]

		result = append(result, node.Val)

		if node.Children == nil {
			continue
		}

		for i := len(node.Children) - 1; i >= 0; i-- {
			stack = append(stack, node.Children[i])
		}
	}

	return result
}
```

### 3. Binary tree level order traversal
- Problem: https://leetcode.com/problems/binary-tree-level-order-traversal/

```go
func levelOrder(root *TreeNode) [][]int {
	result := make([][]int, 0, 1)
	if root == nil {
		return result
	}

	queue := make([]*TreeNode, 0, 1)
	level := 0
	levels := []int{1}
	queue = append(queue, root)

	for len(queue) > 0 {
		node := queue[0]
		queue = queue[1:]

		if len(result) <= level {
			result = append(result, make([]int, 0, 1))
		}
		result[level] = append(result[level], node.Val)
		levels[level] -= 1

		if node.Left != nil {
			if len(levels) <= level+1 {
				levels = append(levels, 0)
			}
			levels[level+1] += 1
			queue = append(queue, node.Left)
		}
		if node.Right != nil {
			if len(levels) <= level+1 {
				levels = append(levels, 0)
			}
			levels[level+1] += 1
			queue = append(queue, node.Right)
		}

		if levels[level] == 0 {
			level += 1
		}
	}

	return result
}
```
