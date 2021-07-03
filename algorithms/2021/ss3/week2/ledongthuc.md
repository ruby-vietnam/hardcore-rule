# 1. Happy Number

https://leetcode.com/problems/happy-number/

## 1.1. Summary

 - Split number to parts by
	 - Unit = number % 10
	 - Next digit = number / 10
 - Plus square of splitted numbers
	 - If result's 1 then number is happy
	 - If result's not 1 and never existed in previous results, then continue
	 - If result's not 1 and existed in previous results, then number is not happy

## 1.2. Code

```go
func isHappy(n int) bool {
    arr := splitNumber(n)
    cache := map[int]struct{}{}
    
    for {
        if n = sumOfSquare(arr); n == 1 {
            return true
        }
        
        _, existed := cache[n]
        if existed {
            return false
        }
        
        cache[n] = struct{}{}
        arr = splitNumber(n)
    }
}

func sumOfSquare(arr []int) int {
    n := 0
    for _, digit := range arr {
        n += digit * digit 
    }
    return n
}

func splitNumber(n int) []int {
    if n < 10 {
        return []int{n}
    }
    
    result := []int{} 
    for {
        var unit int
        n, unit = getUnitNumber(n)
        result = append(result, unit)
        if n == 0 {
            break
        }
    }
    
    return result
}

func getUnitNumber(n int) (left, right int) {
    if n >= 10 {
        return n / 10, n % 10
    }
    return 0, n
}
```

# 2. Longest Happy String

https://leetcode.com/problems/longest-happy-string/

## 2.1. Summary

 - Use priority queue to storing 'a', 'b', 'c' and their remaining counter as priority
	 - Highest priority means highest counter of 'a', 'b' or 'c'
 - Loop and pop from priority queue until the queue is empty
	 - Pop item is highest priority, we try to use this character first.
	 - If pop item's value is not same value with 2 previous item of result, then use it to build result; decrease counter and push back to the queue if counter is not 0
	 - If pop item's value is same with 2 previous item of result, then pop again and use 2nd highest priority item to build the result; decrease counter and push back 1st + 2nd item to the queue if counters are not 0

## 2.2. Code

```go
type Item struct {
	value    rune
	priority int
	index    int
}

type PriorityQueue []*Item

func (pq PriorityQueue) Len() int { return len(pq) }

func (pq PriorityQueue) Less(i, j int) bool {
	return pq[i].priority > pq[j].priority
}

func (pq PriorityQueue) Swap(i, j int) {
	pq[i], pq[j] = pq[j], pq[i]
	pq[i].index = i
	pq[j].index = j
}

func (pq *PriorityQueue) Push(x interface{}) {
	n := len(*pq)
	item := x.(*Item)
	item.index = n
	*pq = append(*pq, item)
}

func (pq *PriorityQueue) Pop() interface{} {
	old := *pq
	n := len(old)
	item := old[n-1]
	old[n-1] = nil
	item.index = -1
	*pq = old[0 : n-1]
	return item
}

func longestDiverseString(a int, b int, c int) string {
    raw := []*Item{
        &Item { value: rune('a'), priority: a },
        &Item { value: rune('b'), priority: b },
        &Item { value: rune('c'), priority: c },
    }
    pq := make(PriorityQueue, 0, a+b+c)
    for _, item := range raw {
        if item.priority > 0 {
            heap.Push(&pq, item)
        }
    }
    
    var previous1, previous2 rune
    var result strings.Builder

    for len(pq) > 0 {
        updatedItem := heap.Pop(&pq).(*Item)
        
        // If highest priority same with 2 previous item, use 2nd highest piority item as updated item
        if updatedItem.value == previous1 && updatedItem.value == previous2 {
            if len(pq) == 0 {
                break
            }
            
            secondItem := heap.Pop(&pq).(*Item)
            heap.Push(&pq, updatedItem)
            
            updatedItem = secondItem
        }
        
        result.WriteRune(updatedItem.value)
        updatedItem.priority--
        if updatedItem.priority > 0 {
            heap.Push(&pq, updatedItem)
        }

        previous2 = previous1
        previous1 = updatedItem.value
    }
    return result.String()
}
```

# 3. The k-th Lexicographical String of All Happy Strings of Length n

https://leetcode.com/problems/the-k-th-lexicographical-string-of-all-happy-strings-of-length-n/

## 3.1. Summary
  - Use backtrack to build a tree with available option leaves is 'a', 'b' and 'c'
  - When building nodes of the tree, the option same with previous node will be skipped
  -  Result is sorted of leaves and get item at k

## 3.2. Code

```go
var options = []string{"a", "b", "c"}

func getHappyString(n int, k int) string {
    result := buildResult(n, "", "")
    sort.Strings(result)
    if k > len(result) {
        return ""
    }
    return result[k-1]
}

func buildResult(n int, s string, previous string) []string {
    if n == 0 {        
        return []string{s}
    }
    
    result := []string{}
    for _, option := range options {
        if previous == option {
            continue
        }
        result = append(result, buildResult(n-1, s+option, option)...)
    }
        
    return result
}
```
