Problem 1:

https://leetcode.com/problems/min-stack

bianry heap:

```go

type BinaryHeap struct {
    internalHeap []int
}

func NewBinaryHeap() BinaryHeap {
    return BinaryHeap {
        internalHeap: []int{0},
    }
}

func (h *BinaryHeap) UpHeap(index int) int {
    var parentIndex int = (index) / 2
    if index == 1 || h.internalHeap[index] >= h.internalHeap[parentIndex] {
        return index
    }
    h.internalHeap[index], h.internalHeap[parentIndex] = h.internalHeap[parentIndex], h.internalHeap[index]
    return h.UpHeap(parentIndex)
}

func (h *BinaryHeap) DownHeap(index int) {
    childrenIndex := (index) * 2
    if childrenIndex >= len(h.internalHeap) -1 {
        return
    }
    if childrenIndex + 1 < len(h.internalHeap) -1 && h.internalHeap[childrenIndex] > h.internalHeap[childrenIndex + 1] {
        childrenIndex = childrenIndex + 1
    }
    if h.internalHeap[index] > h.internalHeap[childrenIndex] {
        h.internalHeap[index], h.internalHeap[childrenIndex] = h.internalHeap[childrenIndex], h.internalHeap[index]
        h.DownHeap(childrenIndex)
    }
}

func (h *BinaryHeap) Push(value int) int {
    h.internalHeap = append(h.internalHeap, value)
    newIndex := len(h.internalHeap) - 1
    return h.UpHeap(newIndex)
}

func (h *BinaryHeap) Pop(index int) int {
    pop := h.internalHeap[index]
    
    h.internalHeap[index] = h.internalHeap[len(h.internalHeap)-1]
    h.UpHeap(index)
    h.DownHeap(index)
    h.internalHeap = h.internalHeap[:len(h.internalHeap)-1]
    return pop
}

func (h *BinaryHeap) Get(index int) int {
    return h.internalHeap[index]
}

type StackItem struct {
    Value int
    Index int
}

type MinStack struct {
    InternalStack []StackItem
    Heap BinaryHeap
}


/** initialize your data structure here. */
func Constructor() MinStack {
    return MinStack{
        Heap: NewBinaryHeap(),
    }
}


func (this *MinStack) Push(x int)  {
    this.InternalStack = append(this.InternalStack, StackItem{
        Value: x,
        Index: this.Heap.Push(x),
    })
}


func (this *MinStack) Pop()  {
    this.Heap.Pop(this.InternalStack[len(this.InternalStack)-1].Index)
    this.InternalStack = this.InternalStack[:len(this.InternalStack) - 1]
}


func (this *MinStack) Top() int {
	if len(this.InternalStack) == 0 {
		return 0
	}
    return this.InternalStack[len(this.InternalStack)-1].Value
}


func (this *MinStack) GetMin() int {
    return this.Heap.Get(1)
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
 
Stack:
```
type StackItem struct {
    Value int
    MinItemInThisTime int
}

type MinStack struct {
    InternalStack []StackItem
}

/** initialize your data structure here. */
func Constructor() MinStack {
    return MinStack{}
}

func (this *MinStack) Push(x int)  {
    if len(this.InternalStack) == 0 {
        this.InternalStack = append(this.InternalStack, StackItem{ Value: x, MinItemInThisTime: x })
    } else {
        currentMin := this.GetMin()
        if currentMin < x {
            this.InternalStack = append(this.InternalStack, StackItem{ Value: x, MinItemInThisTime: currentMin })
        } else {
            this.InternalStack = append(this.InternalStack, StackItem{ Value: x, MinItemInThisTime: x })
        }
    }
}

func (this *MinStack) Pop()  {
    if len(this.InternalStack) == 0 {
        return
    }
    this.InternalStack = this.InternalStack[:len(this.InternalStack) - 1]
}

func (this *MinStack) Top() int {
    if len(this.InternalStack) == 0 {
        return 0
    }
	return this.InternalStack[len(this.InternalStack) - 1].Value
}


func (this *MinStack) GetMin() int {
    if len(this.InternalStack) == 0 {
        return 0
    }
    return this.InternalStack[len(this.InternalStack) - 1].MinItemInThisTime
}
```
