#Easy: last-stone-weight
https://leetcode.com/problems/last-stone-weight/

Submission Details

```
0 / 70 test cases passed.
Status: Accepted
Runtime: 0 ms
Memory Usage: 2 MB
Submitted: 12 minutes ago
```

Naive Solution:
We will run loop until total element in array is 0 or 1:
In this loop we will sort array. After that we will take 2 elements y and x of this array. Check 2 elements if they are not equal we will insert into the array y - x
when loop stop we will check array if don't have element we return 0. If not we return the element at 0.

the loop run n times, and sort of go is n*log(n). we run the sort 2 times. So bigO is n * n * 2 * log(n) -> n^2*log*(n)

Implementation:
```go
func lastStoneWeight(stones []int) int {
	for len(stones) > 1 {
		sort.Ints(stones)
		y := stones[len(stones) - 1]
		x := stones[len(stones) - 2]
		stones = stones[:len(stones) - 2]
		if y > x {
			z := y - x
			stones = append(stones, z)
		}
		sort.Ints(stones)
	}
    
    if len(stones) == 0 { return 0 }
	return  stones[0]
}
```

Better Solution:
We will use max heap to store element. We insert all element from array to this heap. After that we will pop elment until this head have 1 element or 0 element. We pop 2 elements: y,x and compare it. If they are not equal we insert back the heap value of y - x.

the loop run n times, and inseart heap have complexity is log(n) so complexity of this way is nlog(n)

Implementation:
```go
import "container/heap"

func lastStoneWeight(stones []int) int {
	h := &IntHeap{}
	heap.Init(h)
	for i := 0; i < len(stones); i++ {
		heap.Push(h, stones[i])
	}

	for h.Len() > 1 {
		y := heap.Pop(h).(int)
		x := heap.Pop(h).(int)
		if y > x {
			heap.Push(h, y - x)
		}

	}
	if h.Len() == 0 {
		return 0
	}

	return  heap.Pop(h).(int)
}

type IntHeap []int

func (h IntHeap) Len() int           { return len(h) }
func (h IntHeap) Less(i, j int) bool { return h[i] > h[j] }
func (h IntHeap) Swap(i, j int)      { h[i], h[j] = h[j], h[i] }

func (h *IntHeap) Push(x interface{}) {
	// Push and Pop use pointer receivers because they modify the slice's length,
	// not just its contents.
	*h = append(*h, x.(int))
}

func (h *IntHeap) Pop() interface{} {
	old := *h
	n := len(old)
	x := old[n-1]
	*h = old[0 : n-1]
	return x
}
```
