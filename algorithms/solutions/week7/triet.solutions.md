## Problem 1
User hashmap

```go
func firstUniqChar(s string) int {
    if len (s) == 0 {
        return -1
    }
    m := map[rune]int{}
    for _, r := range s {
        if _, exists := m[r]; exists {
            m[r] = 2
        } else {
            m[r] = 1
        }
    }

    for i, r := range s {
        if m[r] == 1 {
            return i
        }
    }
    return -1
}
```


User array char

```go
func firstUniqChar(s string) int {
    if len (s) == 0 {
        return -1
    }
    arrIndex := make([]int, 26)
    for _, c := range s {
        arrIndex[int(c)-97] += 1
    }

    for i, c := range s {
        if arrIndex[int(c)-97] == 1 {
            return i
        }
    }
    return -1
}
```

## Problem 2

Recursive

```go
func compare(left, right *TreeNode) bool {
	if left == nil && right == nil {
		return true
	}
	if (left == nil && right != nil) || (left != nil && right == nil) {
		return false
	}
	if left.Val != right.Val {
		return false
	}
	if compare(left.Left, right.Right) == false {
		return false
	}
	if compare(left.Right, right.Left) == false {
		return false
	}

	return true
}

func isSymmetric(root *TreeNode) bool {
    	if root == nil {
		return true
	}

	return compare(root.Left, root.Right)
}
```

Iteratively

```
func isSymmetricIterate(root *TreeNode) bool {
	if root == nil {
		return true
	}
	leftQueue, rightQueue := []*TreeNode{root.Left}, []*TreeNode{root.Right}
	for len(leftQueue) > 0 && len(rightQueue) > 0 {
		// pop and compare
		leftNode, rightNode := leftQueue[0], rightQueue[0]
		leftQueue, rightQueue = leftQueue[1:], rightQueue[1:]

		if leftNode == nil && rightNode == nil {
			continue
		}

		if (leftNode == nil && rightNode != nil) ||
			(leftNode != nil && rightNode == nil) {
			return false
		}

		if leftNode.Val != rightNode.Val {
			return false
		}

		// push left & right to stack
		leftQueue = append(leftQueue, leftNode.Left)
		leftQueue = append(leftQueue, leftNode.Right)
		rightQueue = append(rightQueue, rightNode.Right)
		rightQueue = append(rightQueue, rightNode.Left)
	}

	return len(leftQueue) == len(rightQueue)
}
```

## Problem bonus 1

```go
package main

import "container/list"
import "fmt"

type input struct {
	Key   int
	Value int
}

func main() {
	actions1 := []string{"LRUCache", "put", "put", "get", "put", "get", "put", "get", "get", "get"}
	inputs1 := []input{{2, 0}, {1, 1}, {2, 2}, {1, 0}, {3, 3}, {2, 0}, {4, 4}, {1, 0}, {3, 0}, {4, 0}}
	output1 := []int{1, -1, -1, 3, 4}

	actions2 := []string{"LRUCache", "put", "put", "get", "put", "put", "get"}
	inputs2 := []input{{2, 0}, {2, 1}, {2, 2}, {2, 0}, {1, 1}, {4, 1}, {2, 0}}
	output2 := []int{2, -1}

	actions3 := []string{"LRUCache", "get", "put", "get", "put", "put", "get", "get"}
	inputs3 := []input{{2, 0}, {2, 0}, {2, 6}, {1, 0}, {1, 5}, {1, 2}, {1, 0}, {2, 0}}
	output3 := []int{-1, -1, 2, 6}

	actions4 := []string{"LRUCache", "put", "put", "put", "put", "get", "get"}
	inputs4 := []input{{2, 0}, {2, 1}, {1, 1}, {2, 3}, {4, 1}, {1, 0}, {2, 0}}
	output4 := []int{-1, 3}
	test(actions1, inputs1, output1)
	test(actions2, inputs2, output2)
	test(actions3, inputs3, output3)
	test(actions4, inputs4, output4)
}

func test(actions []string, inputs []input, result []int) {
	var lru LRUCache
	var output []int
	for i := range actions {
		switch actions[i] {
		case "LRUCache":
			fmt.Printf("CONSTRUCT: %d\n", inputs[i].Key)
			lru = Constructor(inputs[i].Key)
		case "put":
			fmt.Printf("PUT {%d,%d}\n", inputs[i].Key, inputs[i].Value)
			lru.Put(inputs[i].Key, inputs[i].Value)
		case "get":
			value := lru.Get(inputs[i].Key)
			output = append(output, value)
			fmt.Printf("GET %d: %d\n", inputs[i].Key, value)
		}
	}

	if len(result) != len(output) {
		fmt.Println("FAIL, output:", output, "| Expect:", result)
		return
	}

	for i := range result {
		if result[i] != output[i] {
			fmt.Println("FAIL, output:", output, "| Expect:", result)
			return
		}
	}
	fmt.Println("PASS")
	fmt.Println("============")
}

type data struct {
	key   int
	value int
}

type LRUCache struct {
	Capacity int
	Cache    *list.List
	hm       map[int]*list.Element
}

func Constructor(capacity int) LRUCache {
	return LRUCache{
		Capacity: capacity,
		Cache:    list.New(),
		hm:       make(map[int]*list.Element),
	}
}

func (this *LRUCache) Get(key int) int {
	// naive solution, loop throught list
	if element, exists := this.hm[key]; exists {
		d := element.Value.(data)
		this.Cache.MoveToBack(element)

		return d.value
	}

	return -1
}

func (this *LRUCache) Put(key int, value int) {
	// If exists then update
	if element, exists := this.hm[key]; exists {
		element.Value = data{key: key, value: value}
		this.hm[key] = element
		this.Cache.MoveToBack(element)
		this.printList()
		return
	}

	// check current usaged
	if this.Cache.Len() == this.Capacity {
		// evict the front
		frontElement := this.Cache.Front()
		// remove from map
		delete(this.hm, (frontElement.Value).(data).key)

		this.Cache.Remove(frontElement)
	}

	// push back
	e := this.Cache.PushBack(data{key: key, value: value})
	this.hm[key] = e
	this.printList()
}

func (this *LRUCache) printList() {
	currentElement := this.Cache.Front()
	for currentElement != nil {
		d := currentElement.Value.(data)
		fmt.Print("[", d.key, d.value, "]", " ")

		currentElement = currentElement.Next()
	}
	fmt.Println()
}
```
