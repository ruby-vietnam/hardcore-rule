# Week 18

## Problem 1:
https://leetcode.com/problems/min-stack/description/

```go

type MinStack struct {
	Min   *int
	Value int
	Next  *MinStack
}

/** initialize your data structure here. */
func Constructor() MinStack {
	return MinStack{}
}

func (this *MinStack) Push(x int) {	
	minValue := x
	if this.Min != nil && *this.Min < minValue {
		minValue = *this.Min
	}
	s := MinStack{
		Min:   &minValue,
		Value: x,
	}

	if this.Min != nil {
		cp := *this
		s.Next = &cp
	}

	*this = s
}

func (this *MinStack) Pop() {
	if this.Next != nil {
		*this = *this.Next
	} else {
		// Clean stack
		this.Min = nil
		this.Value = 0
		this.Next = nil
	}
}

func (this *MinStack) Top() int {
	return this.Value
}

func (this *MinStack) GetMin() int {
	return *this.Min
}
```
