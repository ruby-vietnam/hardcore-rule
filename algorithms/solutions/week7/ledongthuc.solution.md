Problem 1:

https://play.golang.org/p/VzzBzjOa9RB

```go
func firstUniqChar(s string) int {
	var charCounting [256]int
	for _, rune := range s {
		charCounting[int(rune)] += 1
	}
	for index, rune := range s {
		if charCounting[int(rune)] == 1 {
			return index
		}
	}
	return -1
}
```

Problem 2:

```go
func isSymmetric(root *TreeNode) bool {
	if root == nil {
		return true
	}
	return isMirror(root.Left, root.Right)
}

func isMirror(left *TreeNode, right *TreeNode) bool {
	if left == nil && right == nil {
		return true
	}
	if left == nil || right == nil {
		return false
	}
	return (left.Val == right.Val) && isMirror(left.Left, right.Right) && isMirror(left.Right, right.Left)
}

```

Bonus 1:

https://play.golang.org/p/C41max1tgP1

```
type LRUCache struct {
	Capacity int
	Length   int
	Table    map[int]*DoublyLinkedNode
	List     DoublyLinkedList
}

type DoublyLinkedList struct {
	Head *DoublyLinkedNode
	Tail *DoublyLinkedNode
}

type DoublyLinkedNode struct {
	Previous *DoublyLinkedNode
	Next     *DoublyLinkedNode

	Key   int
	Value int
}

func Constructor(capacity int) LRUCache {
	return LRUCache{
		Table:    make(map[int]*DoublyLinkedNode, capacity),
		List:     newEmptyDoublyLinkedList(),
		Capacity: capacity,
		Length:   0,
	}
}

func (this *LRUCache) Get(key int) int {
	node, isExisted := this.Table[key]
	if !isExisted || node == nil {
		return -1
	}
	this.List.MoveToHead(node)
	return node.Value
}

func (this *LRUCache) Put(key int, value int) {
	if node, isExisted := this.Table[key]; isExisted {
		node.Value = value
		this.List.MoveToHead(node)
		return
	}

	node := DoublyLinkedNode{
		Key:   key,
		Value: value,
	}
	if this.Length < this.Capacity {
		this.List.AddAtHead(&node)
		this.Table[key] = &node
		this.Length++
	} else {
		removed := this.List.PopAtTail()
		delete(this.Table, removed.Key)
		this.List.AddAtHead(&node)
		this.Table[key] = &node		
	}

}

func newEmptyDoublyLinkedList() DoublyLinkedList {
	list := DoublyLinkedList{
		Head: &DoublyLinkedNode{},
		Tail: &DoublyLinkedNode{},
	}
	list.Head.Next = list.Tail
	list.Tail.Previous = list.Head
	return list
}

func (l *DoublyLinkedList) AddAtHead(node *DoublyLinkedNode) {
	oldAfterNext := l.Head.Next
	l.Head.Next.Previous = node
	l.Head.Next = node

	node.Previous = l.Head
	node.Next = oldAfterNext
}

func (l *DoublyLinkedList) PopAtTail() *DoublyLinkedNode {
	node := l.Tail.Previous
	l.Remove(node)
	return node
}

func (l *DoublyLinkedList) Remove(node *DoublyLinkedNode) {
	node.Previous.Next = node.Next
	node.Next.Previous = node.Previous
	node.Previous = nil
	node.Next = nil
}

func (l *DoublyLinkedList) MoveToHead(node *DoublyLinkedNode) {
	l.Remove(node)
	l.AddAtHead(node)
}
```
