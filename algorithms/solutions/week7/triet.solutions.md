## Problem 1
User hashmap

```go
func firstUniqChar(s string) int {
    if len (s) == 0 {
        return -1
    }
    m := map[rune]int{}
    for _, r := range s {
        if _, exists := m[r]; exists {
            m[r] = 2
        } else {
            m[r] = 1
        }
    }

    for i, r := range s {
        if m[r] == 1 {
            return i
        }
    }
    return -1
}
```


User array char

```go
func firstUniqChar(s string) int {
    if len (s) == 0 {
        return -1
    }
    arrIndex := make([]int, 26)
    for _, c := range s {
        arrIndex[int(c)-97] += 1
    }

    for i, c := range s {
        if arrIndex[int(c)-97] == 1 {
            return i
        }
    }
    return -1
}
```

## Problem 2

Recursive

```go
func compare(left, right *TreeNode) bool {
	if left == nil && right == nil {
		return true
	}
	if (left == nil && right != nil) || (left != nil && right == nil) {
		return false
	}
	if left.Val != right.Val {
		return false
	}
	if compare(left.Left, right.Right) == false {
		return false
	}
	if compare(left.Right, right.Left) == false {
		return false
	}

	return true
}

func isSymmetric(root *TreeNode) bool {
    	if root == nil {
		return true
	}

	return compare(root.Left, root.Right)
}
```

Iteratively

```
func isSymmetricIterate(root *TreeNode) bool {
	if root == nil {
		return true
	}
	leftQueue, rightQueue := []*TreeNode{root.Left}, []*TreeNode{root.Right}
	for len(leftQueue) > 0 && len(rightQueue) > 0 {
		// pop and compare
		leftNode, rightNode := leftQueue[0], rightQueue[0]
		leftQueue, rightQueue = leftQueue[1:], rightQueue[1:]

		if leftNode == nil && rightNode == nil {
			continue
		}

		if (leftNode == nil && rightNode != nil) ||
			(leftNode != nil && rightNode == nil) {
			return false
		}

		if leftNode.Val != rightNode.Val {
			return false
		}

		// push left & right to stack
		leftQueue = append(leftQueue, leftNode.Left)
		leftQueue = append(leftQueue, leftNode.Right)
		rightQueue = append(rightQueue, rightNode.Right)
		rightQueue = append(rightQueue, rightNode.Left)
	}

	return len(leftQueue) == len(rightQueue)
}
```

