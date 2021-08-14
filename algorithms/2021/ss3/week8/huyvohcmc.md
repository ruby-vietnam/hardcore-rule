# Easy 1: Valid Anagram

https://leetcode.com/problems/valid-anagram/

### Approach

Once you know what is an anagram, then you can use a hashmap to solve this problem by counting the occurence of unique characters in the first string and then subtract the counter of a character to one every time it appears in the second string.

### Code

```go
func isAnagram(s string, t string) bool {
	if len(s) != len(t) {
		return false
	}
	m := make(map[rune]int)
	for _, c := range s {
		m[c]++
	}
	for _, c := range t {
		m[c]--
	}
	for k, _ := range m {
		if m[k] != 0 {
			return false
		}
	}
	return true
}
```

Time complexity: O(n), space complexity: O(n).

### Submission Detail

```
35 / 35 test cases passed.
Status: Accepted
Runtime: 10 ms
Memory Usage: 3.1 MB
```

# Medium 1: LRU Cache

https://leetcode.com/problems/lru-cache/

### Code

```go
import "container/list"

type pair struct {
	key int
	value int
}

type LRUCache struct {
	capacity int
	data map[int]*list.Element
	history *list.List
}


func Constructor(capacity int) LRUCache {
	return LRUCache{
		capacity,
		make(map[int]*list.Element),
		list.New(),
	}
}


func (this *LRUCache) Get(key int) int {
	if item, ok := this.data[key]; ok {
		this.history.MoveToFront(item)
		return item.Value.(pair).value
	}
	return -1
}


func (this *LRUCache) Put(key int, value int)  {
	if item, ok := this.data[key]; ok {
		item.Value = pair{key, value}
		this.history.MoveToFront(item)
		return
	}
	if this.history.Len() == this.capacity {
		mostRecent := this.history.Back()
		delete(this.data, mostRecent.Value.(pair).key)
		this.history.Remove(mostRecent)
	}
	this.data[key] = this.history.PushFront(pair{key, value})
}
```

### Submission Detail

```
21 / 21 test cases passed.
Status: Accepted
Runtime: 560 ms
Memory Usage: 81.1 MB
```
