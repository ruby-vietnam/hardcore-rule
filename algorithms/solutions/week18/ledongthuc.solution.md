Problem 1:

https://leetcode.com/problems/min-stack

Bianry heap:
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
 ```
 
Stack:
```go
type StackItem struct {
    Value int
    MinItemInThisTime int
}

type MinStack struct {
    InternalStack []StackItem
}

/** initialize your data structure here. */
func Constructor() MinStack {
    return MinStack{InternalStack: make([]StackItem,0,999999)}
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

Problem 2:

https://leetcode.com/problems/restore-ip-addresses

```
func restoreIpAddresses(s string) []string {
    var results []string
	analyze(&results, "", s, 0)
	return results
}

func analyze(results *[]string, processing string, remaining string, noPart int) {
	remainingLen := len(remaining)
	if noPart == 4 && remainingLen == 0 {
		*results = append(*results, processing[1:])
		return
	}
	if noPart == 4 || remainingLen == 0 {
		return
	}


	maxCharsNextPart := remainingLen
	if remainingLen >= 4 {
		maxCharsNextPart = 3
	}
	
	
	for i := 1; i <= maxCharsNextPart; i++ {
		appending := remaining[0:i]
		number, _ := strconv.Atoi(appending)
        if number > 255 || (len(appending) > 1 && appending[0] == '0') {
			continue
		}
		nextProcessing := processing + "." + appending
		nextRemaining := remaining[i:]
		analyze(results, nextProcessing, nextRemaining, noPart+1)
	}
}
```
