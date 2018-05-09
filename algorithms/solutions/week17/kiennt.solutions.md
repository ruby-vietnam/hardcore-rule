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

## Problem 3

```go
// findMaxIndex return an array m in which
// m[i] = index of the tallest height from 0 -> i
// in case there are many item with the same height
// m[i] will be the maximum index
// e.g: h := {10, 20, 40, 30, 40}
// m[0] = 0, m[1] = 1, m[2] = 2, m[3] = 2, m[4] = 4
func findMaxIndex(height []int) []int {
	size := len(height)
	m := make([]int, size)
	for i := 0; i < size; i++ {
		if i == 0 {
			m[i] = 0
			continue
		}
		if height[i] >= height[m[i-1]] {
			m[i] = i
		} else {
			m[i] = m[i-1]
		}
	}
	return m
}

// calculateTrap - calculate all water could be store from
// height[i] to height[j], with the condition is that
// all k in [i, j]: height[k] <= heigh[i] && height[k] <= height[j]
func calculateTrap(height []int, i, j int) int {
	result := 0
	h := height[i]
	if height[j] < height[i] {
		h = height[j]
	}
	for ii := i + 1; ii < j; ii++ {
		result += h - height[ii]
	}
	return result
}

// findLastIndexGE - find the last index k in which height[k] >= height[i]
func findLastIndexGE(height []int, i int) int {
	for ii := i - 1; ii >= 0; ii-- {
		if height[ii] >= height[i] {
			return ii
		}
	}
	return -1
}

func trap(height []int) int {
	size := len(height)
	if size == 0 {
		return 0
	}

	m := findMaxIndex(height)
	// tr[i] = total trap from 0 -> i
	tr := make([]int, size)
	for i := 1; i < size; i++ {
		// i is the tallest height from 0 -> i
		if m[i] == i {
			tr[i] = tr[m[i-1]] + calculateTrap(height, m[i-1], i)
		} else {
			j := findLastIndexGE(height, i)
			tr[i] = tr[j] + calculateTrap(height, j, i)
		}
	}
	fmt.Println(tr)
	return tr[size-1]
}
```