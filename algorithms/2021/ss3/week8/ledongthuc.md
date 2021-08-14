# 1. Valid Anagram

https://leetcode.com/problems/valid-anagram

## 1.1. Summary

- Use hashmap with size 26. it will stores the character ASCII code counter.
- Loop through string `s1` and `s2`
	- Any character in `s1` will increase counter at position `i` (which match with characeter's ascii) of hashmap
	- Any character in `s2` will decrease counter at position `i` (which match with characeter's ascii) of hashmap
- `s1` and `s2` is an anagram if all hashmap counter is 0. Any character's in s1 will be in s2.

## 1.2. Code

```go
func isAnagram(s string, t string) bool {
    if len(s) != len(t) {
        return false
    }
    
    counter := make([]int, 26)
    
    for i, _ := range s {
        counter[s[i] - 'a']++
        counter[t[i] - 'a']--
    }
    
    for i, _ := range counter {
        if counter[i] != 0 {
            return false
        }
    }
    
    return true
}
```

# 2. First Unique Character in a String

https://leetcode.com/problems/first-unique-character-in-a-string/

## 2.1. Summary

- Use hashmap with size 26. it will stores the character ASCII code counter.
- Loop through string `s`
	- Any character in `s` will increase counter at position `i` (which match with characeter's ascii) of hashmap
 - Loop through string `s` again, and return the first character which has counter = 1

## 2.2. Code

```go
func firstUniqChar(s string) int {
    counter := make([]int, 26)
	for i := range s {
		counter[s[i] - 'a']++
	}
	for i := range s {
		if counter[s[i] - 'a'] == 1 {
			return i
		}
	}
	return -1
}
```

# 3. LRU Cache

https://leetcode.com/problems/lru-cache/

## 3.1. Summary

- Use a double linked list to store and arrange the least recently used items
- Use a hash map between key and linked list items to quick access items by key
- When the client get the item by key, we check it from the hash table, move the item to the head of the linked list (recently used item)
- When the client put item by key:
	- If the key existed already, update its value and move the item to the head of the linked list (recently used item)
	- If it doesn't reach capacity; then add it to the hash table, add it to the head of the linked list (recently used item)
	- If it reaches capacity; then pop and remove the tail of the linked list, add to the hash table, add it to head of the linked list (recently used item)

## 3.2. Code

```go
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

# 4. Making File Names Unique

https://leetcode.com/problems/making-file-names-unique

## 4.1. Summary

- Use a hashmap of word and counter.
	- Every word in the hash will cache the last duplicated number
-  Each word from the parameter
	- if it's inexistent, then keep using that word and update this word to the hash table with counter=1
	- If it's existed, get counter and create the next unique name with the increased counter. Continue increasing the unique name until it's inexistent in the hash table. 

## 4.2. Code

```go
type word string
type count int

func getFolderNames(names []string) []string {
    mapping := map[word]count{}
    for i, name := range names {
        uniqueName, c := getFolderName(name, mapping)
        mapping[word(uniqueName)]++
        mapping[word(name)] = c + 1
        names[i]= uniqueName
    }
    return names
}

func getFolderName(name string, mapping map[word]count) (string, count) {
    if _, existed := mapping[word(name)]; !existed {
        return name, count(0)
    }
    
    c := mapping[word(name)] - 1
    tmpName := ""
    for {
        c++
        tmpName = fmt.Sprintf("%s(%d)", name, c)
        
        if _, existed := mapping[word(tmpName)]; !existed  {
            return tmpName, c
        }
    }
}
```
