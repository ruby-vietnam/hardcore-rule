## Problem 1 - [Min Stack](https://leetcode.com/problems/min-stack/description/)

```go
type Entry struct {
    index int    
    value int
}

type MinHeap []*Entry

func (pq MinHeap) Len() int { return len(pq) }

func (pq MinHeap) Less(i, j int) bool {
	return pq[i].value < pq[j].value
}

func (pq MinHeap) Swap(i, j int) {
	pq[i], pq[j] = pq[j], pq[i]
	pq[i].index, pq[j].index = i, j
}

func (pq *MinHeap) Push(x interface{}) {
	n := len(*pq)
	item := x.(*Entry)
	item.index = n
	*pq = append(*pq, item)
}

func (pq *MinHeap) Pop() interface{} {
	old := *pq
	n := len(old)
	item := old[n-1]
	item.index = -1 // for safety
	*pq = old[0 : n-1]
	return item
}

type MinStack struct {
    heap MinHeap
    stack []*Entry
}

/** initialize your data structure here. */
func Constructor() MinStack {
    return MinStack{heap: make(MinHeap, 0), stack: []*Entry{}}    
}


func (this *MinStack) Push(x int)  {
    entry := &Entry{value: x}
    
    // push to stack
    this.stack = append(this.stack, entry)
    
    // push to heap
    heap.Push(&this.heap, entry)
}


func (this *MinStack) Pop()  {
    n := len(this.stack)
    if n <= 0 {
        return
    }

    entry := this.stack[n - 1]
    this.stack = this.stack[:n-1]
    
    heap.Remove(&this.heap, entry.index)
}


func (this *MinStack) Top() int {
    n := len(this.stack)
    if n <= 0 {
        return 0
    }
    return this.stack[n - 1].value
}


func (this *MinStack) GetMin() int {
    n := len(this.heap)
    if n <= 0 {
        return 0
    }
    
    return this.heap[0].value
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