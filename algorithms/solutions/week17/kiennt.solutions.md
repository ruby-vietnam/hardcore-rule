## Problem 1

```go
func isIsomorphicBytes(s, t []byte, size int, isChanged []bool) bool {
	if size == len(s) {
		return true
	}
	if s[size] != t[size] && isChanged[size] {
		return false
	}

	if !isChanged[size] {
		currentChar := s[size]
		for i := size; i < len(s); i++ {
			if s[i] == currentChar && !isChanged[i] {
				s[i] = t[size]
				isChanged[i] = true
			}
		}
	}
	return isIsomorphicBytes(s, t, size+1, isChanged)
}

func isIsomorphic(s, t string) bool {
	if len(s) != len(t) {
		return false
	}
	size := len(s)
	isChangedS := make([]bool, size)
	isChangedT := make([]bool, size)
	return isIsomorphicBytes([]byte(s), []byte(t), 0, isChangedS) && isIsomorphicBytes([]byte(t), []byte(s), 0, isChangedT)
}
```

### Problem 2

```go
func makeCircleList(head *ListNode) int {
	node := head
	size := 1
	for node.Next != nil {
		size++
		node = node.Next
	}
	node.Next = head
	return size
}

func rotateRight(head *ListNode, k int) *ListNode {
	if head == nil {
		return head
	}
	size := makeCircleList(head)
	index := size - k%size - 1
	node := head
	for i := 0; i < index; i++ {
		node = node.Next
	}
	result := node.Next
	node.Next = nil
	return result
}
```