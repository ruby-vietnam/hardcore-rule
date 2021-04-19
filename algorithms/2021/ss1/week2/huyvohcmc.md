# Easy: Last Stone Weight

Leetcode: https://leetcode.com/problems/last-stone-weight/

### Approach

The first algorithm that came to my mind:
1. sort `stones` in ascending order.
2. while length of stones > 1:
  - pops out 2 last stones, smashes them and put the remaining weight (if any) back to its desired position in `stones` to maintain the order.
3. if `stones` is empty, returns 0, otherwise returns the left stone.

We could use binary search (O(logN)) to find the desired position of `stones[i] - stones[j]`, then insert the new stone to that position in the array (O(N)). Combine with the looping, this algorithm costs O(N^2) in time complexity and O(1) in space.

To improve time complexity, we can use a heap data structure to store the stones, because pushing and popping operations of a heap is only O(logN) complexity. The steps are follow:
1. build a heap `heap` from `stones`
2. while heap size > 1:
  - pops out 2 stones, smashes them and push the remaining weight (if any) back to `heap`
3. if `heap` is empty, returns 0, otherwise returns the left stone.

The time complexity has improved to O(NlogN), and space is O(N).

### Solution (Go):

```go
func lastStoneWeight(stones []int) int {
	pq := PriorityQueue(stones)
	heap.Init(&pq)
	for pq.Len() > 1 {
		a, b := heap.Pop(&pq).(int), heap.Pop(&pq).(int)
		if a != b {
			heap.Push(&pq, a-b)
		}
	}
	if pq.Len() == 0 {
		return 0
	}
	return heap.Pop(&pq).(int)
}

type PriorityQueue []int

func (pq PriorityQueue) Len() int {
	return len(pq)
}

func (pq PriorityQueue) Less(i, j int) bool {
	return pq[i] > pq[j]
}

func (pq PriorityQueue) Swap(i, j int) {
	pq[i], pq[j] = pq[j], pq[i]
}

func (pq *PriorityQueue) Push(x interface{}) {
	*pq = append(*pq, x.(int))
}

func (pq *PriorityQueue) Pop() interface{} {
	n := len(*pq)
	a := (*pq)[n-1]
	*pq = (*pq)[:n-1]
	return a
}
```

### Submission Detail

```
70 / 70 test cases passed.
Status: Accepted
Runtime: 0 ms
Memory Usage: 2 MB
```
