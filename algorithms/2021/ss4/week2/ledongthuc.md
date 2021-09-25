# 1. Implement Stack using Queues

https://leetcode.com/problems/implement-stack-using-queues/

## 1.1.Summary

 - Use 2 internal queue, called main queue and support queue.
 - When push to the stack, we push it to the main queue.
 - When pop from the stack, we pull all items from main queue and push to support queue. Last item of main queue is popped stack, we don't need to push it to support queue. Now, support queue become to be a main queue.

## 1.2. Code

```go
type MyStack struct {
    mainQueue    MyQueue
    supportQueue MyQueue
}

/** Initialize your data structure here. */
func Constructor() MyStack {
    return MyStack{
        mainQueue: QueueConstructor(),
        supportQueue: QueueConstructor(),
    }
}

/** Push element x onto stack. */
func (this *MyStack) Push(x int)  {
    this.mainQueue.Push(x)
}

/** Removes the element on top of the stack and returns that element. */
func (this *MyStack) Pop() int {
    var v int
    for {
        v = this.mainQueue.Pop()
        if this.mainQueue.Empty() {
            break
        }
        this.supportQueue.Push(v)
    }
    this.mainQueue, this.supportQueue = this.supportQueue, this.mainQueue
    return v
}

/** Get the top element. */
func (this *MyStack) Top() int {
    var v int
    for !this.mainQueue.Empty() {
        v = this.mainQueue.Pop()
        this.supportQueue.Push(v)
    }
    this.mainQueue, this.supportQueue = this.supportQueue, this.mainQueue
    return v
}

/** Returns whether the stack is empty. */
func (this *MyStack) Empty() bool {
    return this.mainQueue.Empty()
}


/********* Implement Queue **********/

type MyQueue struct {
    inner []int
}

/** Initialize your data structure here. */
func QueueConstructor() MyQueue {
    return MyQueue {
        inner: make([]int, 0),
    }
}

/** Push element x to the back of queue. */
func (this *MyQueue) Push(x int)  {
    this.inner = append(this.inner, x)
}

/** Removes the element from in front of queue and returns that element. */
func (this *MyQueue) Pop() int {
    popValue := this.inner[0]
    this.inner = this.inner[1:]
    return popValue
}

/** Get the front element. */
func (this *MyQueue) Peek() int {
    return this.inner[0]
}

/** Returns whether the queue is empty. */
func (this *MyQueue) Empty() bool {
    return len(this.inner) == 0
}
```

# 2 Implement Queue using Stacks

https://leetcode.com/problems/implement-queue-using-stacks/

## 2.1. Summary

 - Use 2 internal stacks, called main stack and support stack.
 - When push to the queue, we push it to the main stack.
 - When pop from the queue, we pull all items from main stack and push to support stack. Last item of main stack is popped queue, we don't need to push it to support stack. Finally, we need to pull all items from support stack, and push them to main stack to keep the order.

## 2.2. Code

```go
type MyQueue struct {
    mainStack    MyStack
    supportStack MyStack
}

/** Initialize your data structure here. */
func Constructor() MyQueue {
    return MyQueue {
        mainStack: StackConstructor(),
        supportStack: StackConstructor(),
    }
}

/** Push element x to the back of queue. */
func (this *MyQueue) Push(x int)  {
    this.mainStack.Push(x)
}

/** Removes the element from in front of queue and returns that element. */
func (this *MyQueue) Pop() int {
    var v int
    for {
        v = this.mainStack.Pop()
        if this.mainStack.Empty() {
            break
        }
        this.supportStack.Push(v)
    }
    this.swapSupportToMain()
    return v
}

/** Get the front element. */
func (this *MyQueue) Peek() int {
    var v int
    for !this.mainStack.Empty() {
        v = this.mainStack.Pop()
        this.supportStack.Push(v)
    }
    this.swapSupportToMain()
    return v
}

func (this *MyQueue) swapSupportToMain() {
    for !this.supportStack.Empty() {
        this.mainStack.Push(this.supportStack.Pop())
    }
}

/** Returns whether the queue is empty. */
func (this *MyQueue) Empty() bool {
    return this.mainStack.Empty()
}

/********* Implement Stack **********/

type MyStack struct {
    inner []int
}

/** Initialize your data structure here. */
func StackConstructor() MyStack {
    return MyStack {
        inner: make([]int, 0),
    }
}

/** Push element x onto stack. */
func (this *MyStack) Push(x int)  {
    this.inner = append(this.inner, x)
}

/** Removes the element on top of the stack and returns that element. */
func (this *MyStack) Pop() int {
    v := this.inner[len(this.inner) - 1]
    this.inner = this.inner[0:len(this.inner) - 1]
    return v
}

/** Get the top element. */
func (this *MyStack) Top() int {
    return this.inner[len(this.inner) - 1]
}

/** Returns whether the stack is empty. */
func (this *MyStack) Empty() bool {
    return len(this.inner) == 0
}
```

# 3. Reveal Cards In Increasing Order

https://leetcode.com/problems/reveal-cards-in-increasing-order/

## 3.1. Summary

 - Create a simulate sorted deck index, use it to map to sorted deck.
 - Go to loop with each step:
	 - Reveale top card
	 - Check next card and move it to bottom
- Use a Queue to simulate sorted deck index and managed index.
- Index from queue pop card is index of reveale card.

## 3.2. Code

```go
func deckRevealedIncreasing(deck []int) []int {
    // Sort the deck
    sort.Ints(deck)
    
    // Simulate with sorted deck
    queue := QueueConstructor() 
    for i := 0; i < len(deck); i++ {
        queue.Push(i)
    }
    
    // Reveale top card, check next card and move to bottom 
    result := make([]int, len(deck))
    for index, card := range deck {
        result[queue.Pop()] = card
        if index != len(deck) - 1 {
            queue.Push(queue.Pop())
        }
    }
    return result
}

type MyQueue struct {
    inner []int
}

/** Initialize your data structure here. */
func QueueConstructor() MyQueue {
    return MyQueue {
        inner: make([]int, 0),
    }
}

/** Push element x to the back of queue. */
func (this *MyQueue) Push(x int)  {
    this.inner = append(this.inner, x)
}

/** Removes the element from in front of queue and returns that element. */
func (this *MyQueue) Pop() int {
    popValue := this.inner[0]
    this.inner = this.inner[1:]
    return popValue
}

/** Get the front element. */
func (this *MyQueue) Peek() int {
    return this.inner[0]
}

/** Returns whether the queue is empty. */
func (this *MyQueue) Empty() bool {
    return len(this.inner) == 0
}
```

# 4. Design Circular Queue

https://leetcode.com/problems/design-circular-queue/

## 4.1. Summary

 - Use an internal array as data storage, 2 pointers to track the starting and ending of queue items.
 - Implement a method that allows to circularly increase if the pointer is reach capacity of the internal array. It will move back to starting of array (index = 0)
 - Enqueuing an item: increase the actual size of queue, circularly increase the ending pointer (increase one item) and set new value to ending pointer. Enqueuing is failed if actual size of the queue equals capacity of the internal array.
 - Dequeuing an item, decrease the actual size of queue, circularly increase the starting pointer (remove first item). Dequeuing is failed if actual size of the queue equals 0.

## 4.2. Code

```go
type MyCircularQueue struct {
    size int
    capacity int
    inner []int
    startIndex int
    endIndex int
}


func Constructor(k int) MyCircularQueue {
    return MyCircularQueue{
        size: 0,
        capacity: k,
        inner: make([]int, k),
        startIndex: 0,
        endIndex: -1, // to make first element will be in 0
    }
}


func (this *MyCircularQueue) EnQueue(value int) bool {
    if this.IsFull() {
        return false
    }
    
    this.size++
    this.endIndex = this.CircularIncreasement(this.endIndex)
    this.inner[this.endIndex] = value
    return true
}


func (this *MyCircularQueue) DeQueue() bool {
    if this.IsEmpty() {
        return false
    }
    
    this.size--
    this.startIndex = this.CircularIncreasement(this.startIndex)
    return true
}


func (this *MyCircularQueue) Front() int {
    if this.size == 0 {
        return -1
    }
    return this.inner[this.startIndex]
}


func (this *MyCircularQueue) Rear() int {
    if this.size == 0 {
        return -1
    }
    return this.inner[this.endIndex]
}


func (this *MyCircularQueue) IsEmpty() bool {
    return this.size == 0
}


func (this *MyCircularQueue) IsFull() bool {
    return this.size == this.capacity
}

func (this *MyCircularQueue) CircularIncreasement(i int) int {
    if i == this.capacity-1{
        return 0
    }
    return i+1
}
```

