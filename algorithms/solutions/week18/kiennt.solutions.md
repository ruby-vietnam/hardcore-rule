## Problem 1

```go
// Node in MinStack
type Node struct {
	value int
	min   int
	next  *Node
}

// MinStack - stack with min
type MinStack struct {
	top *Node
}

// Constructor - initialize
func Constructor() MinStack {
	return MinStack{}
}

// Push - push new element to stack
func (s *MinStack) Push(x int) {
	node := &Node{x, x, s.top}
	if s.top != nil && s.top.min < x {
		node.min = s.top.min
	}
	s.top = node
}

// Pop - remove the top element
func (s *MinStack) Pop() {
	if s.top != nil {
		s.top = s.top.next
	}
}

// Top - get the top element
func (s *MinStack) Top() int {
	return s.top.value
}

// GetMin - return the min element in stack
func (s *MinStack) GetMin() int {
	return s.top.min
}
```

## Problem 2