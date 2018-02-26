## Problem 1

```go
func validPalindrome(s string) bool {
	return check(s, false)
}

func check(s string, isDeleted bool) bool {
	left, right := 0, len(s)-1
	for left < right {
		if s[left] != s[right] {
			// Check and try to delete one character
			if !isDeleted {
				isDeleted = true
				if left+1 <= right && s[left+1] == s[right] {
					if check(s[left+1:right+1], true) {
						return true
					}
				}

				if right-1 >= left && s[right-1] == s[left] {
					if check(s[left:right], true) {
						return true
					}
				}
			}
			return false
		}
		left++
		right--
	}

	return true
}
```

## Problem 2

```go
func flatten(root *TreeNode)  {
	if root == nil {
		return
	}

	var stack []*TreeNode
	stack = append(stack, root)

	for len(stack) > 0 {
		current := stack[len(stack)-1]
		stack = stack[0 : len(stack)-1]

		if current.Right != nil {
			stack = append(stack, current.Right)
		}

		if current.Left != nil {
			stack = append(stack, current.Left)
		}

		current.Left = nil
		if len(stack) > 0 {
			current.Right = stack[len(stack)-1]
		}
	}
}
```

## Problem 3

```go
func isSubsequence(s string, t string) bool {
    if s == "" {
        return true
    }
    
    i := 0
    for j := 0; j < len(t); j++ {
        if s[i] == t[j] {
            i++
            
            if i == len(s) {
                return true
            }
        }  
    }
    
    return false
}
```
