### Problem 1

https://leetcode.com/problems/min-stack/description/#
```
type MinStack struct {
    top *StackItem
    min *StackItem
}

type StackItem struct {
    next *StackItem
    val int
}

/** initialize your data structure here. */
func Constructor() MinStack {
    return MinStack{
        nil,
        nil,
    }
}


func (this *MinStack) Push(x int)  {
    top := &StackItem{this.top, x}
    this.top = top
    if this.min == nil || x < this.min.val {
        this.min = &StackItem{this.min, x}
    } else {
        this.min = &StackItem{this.min, this.min.val}   
    }
}


func (this *MinStack) Pop()  {
    this.top = this.top.next
    this.min = this.min.next
}


func (this *MinStack) Top() int {
    return this.top.val;
}


func (this *MinStack) GetMin() int {
    return this.min.val
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
