# Season 4 - Week 2

### 1. Implement Stack using Queues
- Problem: https://leetcode.com/problems/implement-stack-using-queues

```go
package main

import "fmt"

type Queue struct {
	data []int
}

func NewQueue() Queue {
	return Queue{data: make([]int, 0)}
}

func (q *Queue) Enqueue(x int) {
	q.data = append(q.data, x)
}

func (q *Queue) Dequeue() int {
	if q.Size() == 0 {
		return 0
	}
	first := q.data[0]
	q.data = q.data[1:]
	return first
}

func (q *Queue) Size() int {
	return len(q.data)
}

func (q *Queue) IsEmpty() bool {
	return q.Size() == 0
}

type MyStack struct {
	MainQueue Queue
	TempQueue Queue
}

/** Initialize your data structure here. */
func Constructor() MyStack {
	return MyStack{
		MainQueue: NewQueue(),
		TempQueue: NewQueue(),
	}
}

/** Push element x onto stack. */
func (this *MyStack) Push(x int) {
	for this.MainQueue.Size() > 0 {
		this.TempQueue.Enqueue(this.MainQueue.Dequeue())
	}

	this.MainQueue.Enqueue(x)
	for this.TempQueue.Size() > 0 {
		this.MainQueue.Enqueue(this.TempQueue.Dequeue())
	}
}

/** Removes the element on top of the stack and returns that element. */
func (this *MyStack) Pop() int {
	return this.MainQueue.Dequeue()
}

/** Get the top element. */
func (this *MyStack) Top() int {
	last := this.MainQueue.Dequeue()
	this.Push(last)
	return last
}

/** Returns whether the stack is empty. */
func (this *MyStack) Empty() bool {
	return this.MainQueue.IsEmpty()
}
```

### 2. Implement Queue by Stacks
- Problem: https://leetcode.com/problems/implement-queue-using-stacks
``` go
type Stack struct {
	data []int
}

func NewStack() Stack {
	return Stack{data: make([]int, 0)}
}

func (s *Stack) Push(x int) {
	s.data = append(s.data, x)
}

func (s *Stack) Pop() int {
	size := s.Size()
	if size == 0 {
		return 0
	}
	last := s.data[size-1]
	s.data = s.data[0 : size-1]
	return last
}

func (s *Stack) Size() int {
	return len(s.data)
}

func (s *Stack) IsEmpty() bool {
	return s.Size() == 0
}

type MyQueue struct {
	MainStack Stack
	TempStack Stack
}

/** Initialize your data structure here. */
func Constructor() MyQueue {
	return MyQueue{
		MainStack: NewStack(),
		TempStack: NewStack(),
	}
}

/** Push element x onto queue. */
func (this *MyQueue) Push(x int) {
	for this.MainStack.Size() > 0 {
		this.TempStack.Push(this.MainStack.Pop())
	}

	this.MainStack.Push(x)
	for this.TempStack.Size() > 0 {
		this.MainStack.Push(this.TempStack.Pop())
	}
}

/** Removes the element on front of the queue and returns that element. */
func (this *MyQueue) Pop() int {
	return this.MainStack.Pop()
}

/** Get the front element. */
func (this *MyQueue) Peek() int {
	last := this.MainStack.Pop()
	this.MainStack.Push(last)
	return last
}

/** Returns whether the queue is empty. */
func (this *MyQueue) Empty() bool {
	return this.MainStack.IsEmpty()
}
```

### 3. Reveal Cards in increasing orders
- Problem:  https://leetcode.com/problems/reveal-cards-in-increasing-order
```go
func deckRevealedIncreasing1(deck []int) []int {
	length := len(deck)
	sort.Ints(deck)
	newCards := make([]int, length)

	index := 0
	i := 0
	for {
		if index == length {
			break
		}
		newCards[i] = deck[index]
		index += 1

		hasBlank := false
		for i = i + 1; index < length; i++ {
			if i > length-1 {
				i = i % length
			}

			if hasBlank && newCards[i] == 0 {
				break
			}

			if newCards[i] == 0 {
				hasBlank = true
			}
		}

		fmt.Println(newCards)
	}

	return newCards
}

// [17]
// [13, 17]
// [11, 17,13] // 13 end
// [7,  13,11,17] // 13 first, 17 end
// [5,  17,7,13,11] // 17first, 11 end
// [3,  11,5,17,7,13]// 11first, 13 end
// [2,  13,3,11,5,17,7]// 13first, 7 end

func deckRevealedIncreasing2(deck []int) []int {
	sort.Slice(deck, func(i, j int) bool {
		return deck[i] > deck[j]
	})

	length := len(deck)
	newCards := make([]int, length)

	count := 0
	newCards[count] = deck[0]
	for {
		lastItem := newCards[count]
		count += 1

		if count >= length {
			break
		}

		temp := newCards[0 : count-1]
		newCards = append([]int{deck[count]}, lastItem)
		newCards = append(newCards, temp...)

		fmt.Println(newCards)
	}

	return newCards
}

// Use queue

type Queue struct {
	data []int
}

func NewQueue() Queue {
	return Queue{data: make([]int, 0)}
}

func (q *Queue) Enqueue(x int) {
	q.data = append(q.data, x)
}

func (q *Queue) Dequeue() int {
	if q.Size() == 0 {
		return 0
	}
	first := q.data[0]
	q.data = q.data[1:]
	return first
}

func (q *Queue) Size() int {
	return len(q.data)
}

func deckRevealedIncreasing3(deck []int) []int {
	sort.Ints(deck)

	length := len(deck)
	newCards := make([]int, length)

	queue := NewQueue()
	for i := 0; i < length; i++ {
		queue.Enqueue(i)
	}

	for i := 0; i < length; i++ {
		newCards[queue.Dequeue()] = deck[i]
		queue.Enqueue(queue.Dequeue())
		fmt.Println(newCards)
	}

	return newCards
}
```

### 4. Design Circular Queue
- Problem: https://leetcode.com/problems/design-circular-queue
```go
type MyCircularQueue struct {
	size  int
	front int
	rear  int
	data  []int
}

func Constructor(k int) MyCircularQueue {
	return MyCircularQueue{
		size: 0,
		rear: -1,
		data: make([]int, k, k),
	}
}

func (this *MyCircularQueue) EnQueue(value int) bool {
	if this.IsFull() {
		return false
	}

	this.rear = (this.rear + 1) % len(this.data)
	this.data[this.rear] = value
	this.size += 1
	return true
}

func (this *MyCircularQueue) DeQueue() bool {
	if this.IsEmpty() {
		return false
	}

	this.front = (this.front + 1) % len(this.data)
	this.size -= 1
	return true
}

func (this *MyCircularQueue) Front() int {
	if this.IsEmpty() {
		return -1
	}

	return this.data[this.front]
}

func (this *MyCircularQueue) Rear() int {
	if this.IsEmpty() {
		return -1
	}

	return this.data[this.rear]
}

func (this *MyCircularQueue) IsEmpty() bool {
	return this.size == 0
}

func (this *MyCircularQueue) IsFull() bool {
	return this.size == len(this.data)
}
```
