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

Problem 3:

https://play.golang.org/p/u_Bmk_fxdFb

```
func candy(ratings []int) int {
    candies := make([]int, len(ratings))
    candies[0] = 1
    
    for i := 1; i < len(ratings); i++ {
        if ratings[i - 1] < ratings[i] {
            
        
            candies[i] = candies[i - 1] + 1
        } else {
            candies[i] = 1
            }
    }
    
    noCandies :=   candies[len(ratings) - 1]
    for i:=len(ratings)-2;i>=0;i--{
        if ratings[i+1] < ratings[i] && candies[i] < candies[i+1] + 1 {
            candies[i] = candies[i+1] + 1
        }
        noCandies += candies[i]
    }
    return noCandies
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

Bonus 2:

https://play.golang.org/p/fPFBkVlE4FZ

```go
type RandomizedSet struct {
	m map[int]int
	l []int
}

/** Initialize your data structure here. */
func Constructor() RandomizedSet {
	return RandomizedSet{
		m: make(map[int]int),
		l: []int{},
	}
}

/** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
func (this *RandomizedSet) Insert(val int) bool {
	if _, ok := this.m[val]; ok {
		return false
	}
	this.m[val] = len(this.l)
	this.l = append(this.l, val)
	return true
}

/** Removes a value from the set. Returns true if the set contained the specified element. */
func (this *RandomizedSet) Remove(val int) bool {
	index, ok := this.m[val]
	if !ok {
		return false
	}
	
	
	if len(this.l) > 1 {
        // Move last item to removed location
		this.l[index] = this.l[len(this.l)-1]
		this.l = this.l[:len(this.l)-1]
		this.m[last] = index
	} else {
		this.l = this.l[:0]
	}
	
	delete(this.m, val)
	return true
}

/** Get a random element from the set. */
func (this *RandomizedSet) GetRandom() int {
	return this.l[rand.Intn(len(this.l))]
}
```
