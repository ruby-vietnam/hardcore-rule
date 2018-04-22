## Problem 1

```go
type MinStack struct {
	a []int
}

/** initialize your data structure here. */
func Constructor() MinStack {
	return MinStack{}
}

func (this *MinStack) Push(x int) {
	this.a = append(this.a, x)

}

func (this *MinStack) Pop() {
	if len(this.a) == 0 {
		return
	}

	this.a = this.a[:len(this.a)-1]
}

func (this *MinStack) Top() int {
	if len(this.a) == 0 {
		return 0
	}

	return this.a[len(this.a)-1]
}

func (this *MinStack) GetMin() int {
	if len(this.a) == 0 {
		return 0
	}

	min := this.a[0]
	for i := range this.a {
		if min > this.a[i] {
			min = this.a[i]
		}
	}

	return min
}

/**
 * Your MinStack object will be instantiated and called as such:
 * obj := Constructor();
 * obj.Push(x);
 * obj.Pop();
 * param_3 := obj.Top();
 * param_4 := obj.GetMin();
 */
```
