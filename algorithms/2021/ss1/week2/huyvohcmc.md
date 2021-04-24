# Easy: Last Stone Weight

Leetcode: https://leetcode.com/problems/last-stone-weight/

### Approach

The first algorithm that came to my mind:
1. sort `stones` in ascending order.
2. while length of stones > 1:
  - pops out 2 last stones, smashes them and put the remaining weight (if any) back to its desired position in `stones` to maintain the order.
3. if `stones` is empty, returns 0, otherwise returns the left stone.

We could use binary search (O(log(n))) to find the desired position of `stones[i] - stones[j]`, then insert the new stone to that position in the array (O(n)). Combine with the looping, this algorithm costs O(n^2) in time complexity and O(1) in space.

To improve time complexity, we can use a heap data structure to store the stones, because pushing and popping operations of a heap is only O(logN) complexity. The steps are follow:
1. build a heap `heap` from `stones`
2. while heap size > 1:
  - pops out 2 stones, smashes them and push the remaining weight (if any) back to `heap`
3. if `heap` is empty, returns 0, otherwise returns the left stone.

The time complexity has improved to O(nlog(n)), and space complexity is O(n).

### Code (Go):

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

### Code (Go):

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
	T := make([]int, S2+1) // T[i] is sum of stones you can choose to make S2, where this sum of stones cannot larger than i
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

Time complexity is O(n * S2) and space complexity is S2.

### Submission Detail

```
86 / 86 test cases passed.
Status: Accepted
Runtime: 0 ms
Memory Usage: 2.1 MB
```

# Hard: Find K-th Smallest Pair Distance

Leetcode: https://leetcode.com/problems/find-k-th-smallest-pair-distance/

### Brute-force

Find all possible pair distances, sort them in ascending order and returns the kth distance. This solution clearly doesn't work for large inputs.

### A Better Approach

We know that kth smallest distance will always be in between the range of smallest possible distance and largest possible distance. If we sort the input in ascending order then the largest possible distance will be:

```
largestPossibleDistance = nums[l-1] - nums[0] // l: length of nums
```

We don't know for sure that the smallest possible distance will be nums[1] - nums[0], because with input `[1, 5, 6]` smallest possible pair distance is `[5, 6]` not `[1, 5]`. But we know that the smallest possible distance cannot be smaller than 0, so let's just say it's 0 and call it a day:

```
smallestPossibleDistance = 0
```

So now we have `smallestPossibleDistance <= kth smallest distance <= largestPossibleDistance`. Next step is to find kth smallest distance by try guessing.

We don't know yet what is kth smallest distance, but for a certain distance `x`, we can know how many pairs that have smaller distance than or equal to `x`.

For example, the question ask us to find the 5th smallest distance (k = 5), and since we already know the range of the smallest distance and largest distance, if we start with a random number `x` (smallest <= x <= largest), and there are indeed 5 pairs in the input (sorted) that have `distance <= x`, then the 5th smallest distance is `x`.

```
[smallest possible distance ... x] has 5 elements, so 5th smallest distance is x
```

But if there are only 3 pairs in the input that have `distance <= x`, then the range [smallest distance ... x] doesn't contain the 5th smallest distance

```
[smallest possible distance ... x] has 3 elements, so 5th smallest distance is outside of this range
```

Similarly when are 6 pairs have `distance <= x`:
```
[smallest possible distance ... x] has 6 elements, so x is 6th smallest distance, not 5th smallest distance
```

The pattern above is pretty much the same with binary search algorithm. So by applying the algorithm we can find which value is x and is also kth smallest distance.

There is one thing left to do, which is given a sorted array of numbers, count the number of pairs that have distance smaller than or equal to a given distance:

```
1. loop through the array with 2 pointers i and j (increment i every step)

nums = 0 0 1 1 2 2, d = 1 (given distance)
       i j

2. increment j while nums[j] - nums[i] <= d

nums = 0 0 1 1 2 2, d = 1
       i       j

3. number of pairs <= d at this step is j - i - 1
```

### Code (Go)

```go
import "sort"

func smallestDistancePair(nums []int, k int) int {
    sort.Ints(nums)
    max := nums[len(nums)-1] - nums[0]
    min := 0
    for min < max {
        median := min + (max - min) / 2
        if countPairs(nums, median) >= k {
            max = median
        } else {
            min = median + 1
        }
    }
    return min
}

func countPairs(nums []int, d int) int {
    c, n := 0, len(nums)
    j := 1
    for i := 0; i < n; i++ {
        for j < n && nums[j] - nums[i] <= d {
            j++
        }
        c += j - 1 - i
    }
    return c
}
```

Time complexity of the initial sort is O(nlog(n)), binary search is O(log(n)), and for each search we calls `countPairs` with O(n), so the total time complexity is O(nlog(n)).

### Submission Detail

```
19 / 19 test cases passed.
Status: Accepted
Runtime: 276 ms
Memory Usage: 3.5 MB
```
