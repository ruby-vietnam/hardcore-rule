# Last Stone Weight [Easy]

Problem: https://leetcode.com/problems/last-stone-weight/

## 1. Idea

The easiest idea is brute force, found 2 largest stone and combine them
together, until we get one or nothing left. Return the result.

![Brute force](https://github.com/monodyle/algorithms-adventure/raw/master/leetcode-problems/1046-last-stone-weight/brute-force.png)

But traverse through array two times to find two biggest numbers make the
complexity of the problem is `N ^ 2`.

So we could try a better way is sorted, then take two numbers from head could
make complexity more easier

![Sorted](https://github.com/monodyle/algorithms-adventure/raw/master/leetcode-problems/1046-last-stone-weight/sorted.png)

But this is algorithm, we need to think bigger...

In **C++** (or **Java**), we have `priority_queue`[^1], which based on `heap`
can quickly resolved this problem

[^1]: Reference: https://www.cplusplus.com/reference/queue/priority_queue/

> This context is similar to a heap, where elements can be inserted at any
> moment, and only the max heap element can be retrieved (the one at the top in
> the priority queue).

```cpp
int lastStoneWeight(vector<int>& stones) {
  priority_queue<int> heap(begin(stones), end(stones));
  while (heap.size() > 1) {
    int y = heap.top(); heap.pop();
    int x = heap.top(); heap.pop();
    if (y > x) heap.push(y - x);
  }
  return heap.empty() ? 0 : heap.top();
}
```

In **Go**, we have `container/heap` built in module, but we have to implement
priority queue. `heap.Init()` take pointer variable have type `x`, and `x` had
implement some requirement method: `Len`, `Less`, `Swap`, `Pop`, `Push`. So all
we need to do is make a type and write some function to implement that.

Wait... hold up boys. What is heap?

Heap just like a tree. But it more complete and stored in an array. Binary heap
is also divided into *maximum heap* and *minimum heap*. The maximum properties
are: each node is greater than or equal to its two children.

Now what is priority queue?

A key feature of priority queue is when you insert or delete some elements, the
elements are sorted automatically.

My tips: I do not imagine heap as a tree. I imagine it as a hierarchy.

![Heap](https://github.com/monodyle/algorithms-adventure/raw/master/leetcode-problems/1046-last-stone-weight/heap-explain.jpeg)

## 2. Example

### 2.1. Brute Force way

**Code:**

```go
func MaxIntSlice(s []int) (int, int) {
	index := 0
	max := s[index]
	for i, v := range s {
		if v > max {
			index = i
			max = v
		}
	}
	return max, index
}

func lastStoneWeight(stones []int) int {
	for {
		if len(stones) == 0 {
			return 0
		}
		if len(stones) == 1 {
			return stones[0]
		}
		y, i := MaxIntSlice(stones)
		stones = append(stones[:i], stones[i+1:]...)
		x, j := MaxIntSlice(stones)
		stones = append(stones[:j], stones[j+1:]...)
		if y != x {
			stones = append(stones, y-x)
		}
	}
}
```

**Submission Detail:**

```
70 / 70 test cases passed.
Status: Accepted
Runtime: 0 ms
Memory Usage: 2 MB
```

### 2.2. Heap way

**Code:**

```go
type max_heap []int

func (h max_heap) Len() int            { return len(h) }
func (h max_heap) Less(i, j int) bool  { return h[i] > h[j] }
func (h max_heap) Swap(i, j int)       { h[i], h[j] = h[j], h[i] }
func (h *max_heap) Push(x interface{}) { *h = append(*h, x.(int)) }
func (h *max_heap) Pop() interface{} {
	n := len(*h)
	x := (*h)[n-1]
	*h = (*h)[:n-1]
	return x
}

func lastStoneWeight(stones []int) int {
	pq := max_heap(stones)
	heap.Init(&pq)
	for pq.Len() > 1 {
		heap.Push(&pq, heap.Pop(&pq).(int)-heap.Pop(&pq).(int))
	}
	return heap.Pop(&pq).(int)
}
```

**Submission Detail:**

```
70 / 70 test cases passed.
Status: Accepted
Runtime: 0 ms
Memory Usage: 2 MB
```

# Last Stone Weight II [Medium]

Problem: https://leetcode.com/problems/last-stone-weight-ii/

## 1. Idea

Firstly, I really stuck in this problem in more than half a day. Happy that I
still resolved this problem as a weak CS knowledge. Trying to understand what
dynamic programming is and how to use it make me go crazy.

Finally I maked it work, lol. So the problem is how to combine the stones?

I can see that whatever order you combine them isn't matter. Let take an
example:

Giving to you some stones: `[a, b, c, d, e, f]` and you going to smash them
ramdomly. I will take a combine like: `a` vs `b` to make `a'` (dont matter what
greater one lol), `a'` vs `c` to make `c'`, `c'` vs `d` to make `d'`, `e` vs
`f` to make `e'`, `d'` vs `e'` are the rest and we I got result.

The formula going like `||||a-b|-c|-d| - |e-f||`*(1)* right?

The absolute is weird, it could be explain `x` to `x` (if `x >= 0`) and `-x`
(if `x < 0`). So `|a - b|` can be right down as `a - b` or `-a + b`, but which
one is the correct?

Now the formula *(1)* can be write down as multiple way:

- `(((a-b)-c)-d)-(e-f)` *(a)*
- `-(-(-(a-b)-c)-d)+(e-f)` *(b)*
- etc...

Now remove brackets:

- *(a)* <=> `a-b-c-d-e+f`
- *(b)* <=> `-a+b-c+d+e-f`

What now? We can see that the formula now going to monomial, before each
character is a plus or minus sign. Let's group them together:

- *(a)* <=> `(a+f) - (b+c+d+e)`
- *(b)* <=> `(b+d+e) - (a+c+f)`

![Explain](https://github.com/monodyle/algorithms-adventure/raw/master/leetcode-problems/1049-last-stone-weight-ii/last-stone-weight-2-explain.png)

So it's easier to think of, any compensates each other for the combine rock will
eventually transform into one. This similar to **Target Sum** problem. We could
use dynamic programming to find every case that could be reach to target sum.
Finally the result is the smallest target sum that is greater than zero.

The important is not all "adding signs" strategies will have a corresponding
"cancellation of stones" operation. For example `+a+b+c+d+e+f` is meaning less.
But what we are looking for is the smallest target (which also a positive
number), which can prove that there must be a corresponding "cancellation of
stones" operation.

## 2. Example

```go
func lastStoneWeightII(stones []int) int {
	total_weight := 0
	for _, weight := range stones {
		total_weight += weight
	}
	half := total_weight / 2
	dp := make([]int, half+1)
	dp[0] = 1
	for _, stone := range stones {
		for x := half; x >= stone; x-- {
			dp[x] |= dp[x-stone]
		}
	}
	result := total_weight
	for x := 0; x <= half; x++ {
		result = min(result, total_weight-dp[x]*x*2)
	}
	return result
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}
```

## 3. Submission Detail

```
86 / 86 test cases passed.
Status: Accepted
Runtime: 0 ms
Memory Usage: 2.1 MB
```

# Find K-th Smallest Pair Distance [Hard]

Problem: https://leetcode.com/problems/find-k-th-smallest-pair-distance/

## 1. Idea

Firstly, when I pick a pair to calc distance result will make `O(n^2)` time
complexity.

![Brute force](https://github.com/monodyle/algorithms-adventure/raw/master/leetcode-problems/719-find-k-th-smallest-pair-distance/brute-force.png)

But I've reach TLE when use this way... That mean I need to find another way.

![TLE](https://github.com/monodyle/algorithms-adventure/raw/master/leetcode-problems/719-find-k-th-smallest-pair-distance/tle.png)

Imagine we can sort the array of distances of all pair. That will look like:
`[0, 1, 1, ..., x-1, x, x+1, x+1, ...]` where `x` is the `k`th smallest
distance. Should be the `x` if:

* That means at most `k-1` smaller than numbers ahead.
* (Count of smaller than `x`) + (Count of same as `x`) >= `k`

Example: Give a array of distance `[0, 1, 2, 2 ,2, 4, 5]`, `5`th smallest is
`2`. There are 3 numbers smaller, and 2 numbers same. 3 + 2 >= 5 (true)

From the meaning of question, result must exist in range [`low`, `high`]. We
could use binary search to count numbers of distance smaller or equal to `mid`.

## 2. Example

```go
func smallestDistancePair(nums []int, k int) int {
	n := len(nums)
	sort.Ints(nums)

	low := nums[1] - nums[0]
	for i := 2; i < n; i++ {
		low = min(low, nums[i]-nums[i-1])
	}

	high := nums[n-1] - nums[0]
	for low < high {
		mid := low + (high-low)/2
		if count(nums, mid) < k {
			low = mid + 1
		} else {
			high = mid
		}
	}

	return low
}

func count(nums []int, mid int) int {
	n := len(nums)
	res := 0
	i, j := 0, 1
	for j < n {
		if nums[j]-nums[i] <= mid {
			res += j - i
			j++
		} else {
			i++
		}
	}
	return res
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}
```

## 3. Submission Detail

```
19 / 19 test cases passed.
Status: Accepted
Runtime: 4 ms
Memory Usage: 3.5 MB
```

