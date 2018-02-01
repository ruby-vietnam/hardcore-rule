Problem 1:

https://play.golang.org/p/VzzBzjOa9RB

```go
func firstUniqChar(s string) int {
	var charCounting [256]int
	for _, rune := range s {
		charCounting[int(rune)] += 1
	}
	for index, rune := range s {
		if charCounting[int(rune)] == 1 {
			return index
		}
	}
	return -1
}
```

Problem 2:

```go
func isSymmetric(root *TreeNode) bool {
	if root == nil {
		return true
	}
	return isMirror(root.Left, root.Right)
}

func isMirror(left *TreeNode, right *TreeNode) bool {
	if left == nil && right == nil {
		return true
	}
	if left == nil || right == nil {
		return false
	}
	return (left.Val == right.Val) && isMirror(left.Left, right.Right) && isMirror(left.Right, right.Left)
}

```
