## Problem 1

```go
type MinStack struct {
	a   []int
	min *int
}

/** initialize your data structure here. */
func Constructor() MinStack {
	return MinStack{}
}

func (this *MinStack) Push(x int) {
	this.a = append(this.a, x)
	if this.min == nil {
		this.min = &x
		return
	}
	if *this.min > x {
		this.min = &x
	}

}

func (this *MinStack) Pop() {
	if len(this.a) == 0 {
		return
	}

	x := this.a[len(this.a)-1]
	if this.min != nil && x == *this.min {
		min := this.a[0]
		for i := range this.a {
			if i == len(this.a)-1 {
				break
			}

			if min > this.a[i] {
				min = this.a[i]
			}
		}

		this.min = &min
	}

	this.a = this.a[:len(this.a)-1]
	if len(this.a) == 0 {
		this.min = nil
	}
}

func (this *MinStack) Top() int {
	if len(this.a) == 0 {
		return 0
	}

	x := this.a[len(this.a)-1]

	return x
}

func (this *MinStack) GetMin() int {
	if this.min != nil {
		return *this.min
	}
	return 0
}
```
