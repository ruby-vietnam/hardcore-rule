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

# Medium: Last Stone Weight II

Leetcode: https://leetcode.com/problems/last-stone-weight-ii/

### Approach

Suppose we separate stones that have weight `x` and stones that have weight `y` into 2 subsets:
```
S: [2, 7, 4, 1, 8, 1]
S1: [2, 7, 1]
S2: [4, 8, 1]
```
Then when smashing together we will have
```
S1 - S2 -> [2, 1]
and 2 - 1 -> [1]
```
The problem ask us to find the smallest possible weight of the left stone. The result can be calculated like this:
```
S = S1 + S2
result = S1 - S2 = S - S2 - S2 = S - 2 * S2
```

To minimize the result (the weight of the left stone) we need to maximize S2. We don't need to find which stone is in S2, we just need to find the sum of all stones in S2. But how do we find the sum of S2 exactly?

This is a 0/1 knapsack problem: you have a list of items with value `v` and weight `w`, you also have a sack of `W` capacity. Now you need to collect the items to maximize item values and make sure item weights still smaller than or equal to the sack's capacity.

To find S2, we can think of
- `W` as `sum(stones) / 2`
- `v` as `stones[i]`
- `w` as `stones[i]`

### Solution (Go):

```go
func lastStoneWeightII(stones []int) int {
	/*
	   S: sum of weights in stones
	   S1: sum of stones have weight x
	   S2: sum of stones have weight y
	   S1 + S2 = S
	   S1 - S2 = smallest possible weight of the left stone
	   smallest possible stone weight = S - 2 * S2 where S2 is as close to S/2 as possible
	*/
	S := 0
	for _, weight := range stones {
		S += weight
	}
	S2 := S >> 1
	T := make([]int, S2+1) // T[i] is the sum of stones you can choose from S when the allowed weight (capacity) is i
	for _, weight := range stones {
		for i := S2; i >= weight; i-- {
			T[i] = max(weight+T[i-weight], T[i])
		}
	}
	return S - 2 * T[S2]
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}
```

Time complexity: O(N * S2)
Space complexity: S2

### Submission Detail

```
86 / 86 test cases passed.
Status: Accepted
Runtime: 0 ms
Memory Usage: 2.1 MB
```
