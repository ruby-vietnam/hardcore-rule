# 1. Last stone weight

https://leetcode.com/problems/last-stone-weight/

## 1.1. Summary

- Basically, steps to solve issue are:
	- Get 2 heaviest stones from the basket.
	- Mash them together. If they have result, put them back to basket.
	- Loop to first step until the basket only has one or runs out of stone.
- So we have 2 things need to think:
	- How to arrange the stones in the basket to make us easier to get 2 heaviest continously.
	- How we put result stone from mashing back to basket but still keep the arrangement.
- Form that one, we go to following solution

## 1.2. Unsorted array

- We don't need to arrange stones in basket.
- Every mashing step, we check all basket and get heaviest stones to mash.
- Result of mashing, we put randomly back to basket 
- Complexity: n^2

```go
func lastStoneWeight(stones []int) int {
    for {
        if len(stones) == 0 {
            return 0
        }
        if len(stones) == 1 {
            return stones[0]
        }
        var first, second int 
        first, second, stones = get2HeaviestStones(stones)
        if remaining := first - second; remaining != 0 {
            stones = append(stones, remaining)
        }
    }
}

func get2HeaviestStones(stones []int) (first,second int, arr []int) {
    if len(stones) > 0 {
        first = stones[0]
    }
    if len(stones) > 1 {
        second = stones[1]
    }
    
    firstIndex := 0
    secondIndex := 1
    if first < second {
        firstIndex = 1
        secondIndex = 0
        first, second = second, first
    }
    
    if len(stones) < 3 {
        return first, second, []int{}
    }
    
    for i:=2; i < len(stones); i++ {
        stone := stones[i]
        if stone > first {
            first, second = stone, first
            firstIndex, secondIndex  = i, firstIndex
            continue
        }
        if stone > second {
            second = stone
            secondIndex = i
        }
    }
    
    // Remove item from array
    stones = append(stones[:firstIndex], stones[firstIndex+1:]...)
    if firstIndex < secondIndex {
        secondIndex--
    }
    stones = append(stones[:secondIndex], stones[secondIndex+1:]...)
    return first, second, stones
}
```

## 1.3. Sorted array

- An improvement of previous solution
- Init, we sort stones in the basket
- Every mashing step, get 2 last stones from sorted stones
- Result of mashing, we scan from sorted stones and put the stones to correct order
- Complexity: n^2

![enter image description here](https://raw.githubusercontent.com/ledongthuc/notes/master/leetcode/last-stone-weight/LastStoneWeight-Sort.png)

```go
func lastStoneWeight(stones []int) int {
    sort.Ints(stones)
    for {
        if len(stones) == 0 {
            return 0
        }
        if len(stones) == 1 {
            return stones[0]
        }
        if len(stones) == 2 {
            return stones[1] - stones[0]
        }
        
        remaining := stones[len(stones)-1] - stones[len(stones)-2]
        stones = stones[:len(stones)-2]
        if remaining != 0 {
            stones = putKeepOrder(remaining, stones)
        }
    }
}

func putKeepOrder(remaining int, stones []int) []int {
    if len(stones) == 0 {
        return []int{remaining}
    }
    if remaining > stones[len(stones)-1] {
        return append(stones, remaining)
    }
    
    newStones := make([]int, 0, len(stones) + 1)
    for i, stone := range stones {
        if stone >= remaining {
            newStones = append(newStones, remaining)
            newStones = append(newStones, stones[i:]...)
            break
        }
        newStones = append(newStones, stone)
    }
    return newStones
}
```

## 1.4. Heap

- Same previous version, but use heap instead of sorted array 
- Init, we heapify stones in the basket
- Every mashing step, get 2 last stones from sorted stones
- Result of mashing, we put it to heap and heapify again
- Complexity: nlog(n)

![enter image description here](https://raw.githubusercontent.com/ledongthuc/notes/master/leetcode/last-stone-weight/LastStoneWeight-binary%20heap.png)

```go
func lastStoneWeight(stones []int) int {
    maxHeap := InitHeapMaxInt(stones)
    for len(*maxHeap) > 0 {
        remaining := maxHeap.Mash2TopAndPushRemaning();
        fmt.Println(remaining, (*maxHeap))
        if len(*maxHeap) == 1 {
            return (*maxHeap)[0]
        }
    }
    return 0
}

type HeapMinInt []int

func InitHeapMinInt(arr []int) *HeapMinInt {
	heap := HeapMinInt(arr)
	for i := len(heap)/2 - 1; i >= 0; i-- {
		heap.heapifyDown(i)
	}
	return &heap
}

func (h *HeapMinInt) Pop() int {
	item := (*h)[0]
	(*h) = (*h)[1:len(*h)]
	h.heapifyDown(0)
	return item
}

func (h *HeapMinInt) Push(item int) {
	(*h) = append(*h, item)
	h.heapifyUp(len(*h) - 1)
}

func (h *HeapMinInt) heapifyDown(i int) {
	min := i
	left := 2*i + 1
	right := 2*i + 2

	if left < len(*h) && (*h)[left] < (*h)[min] {
		min = left
	}

	if right < len(*h) && (*h)[right] < (*h)[min] {
		min = right
	}

	if min != i {
		(*h)[i], (*h)[min] = (*h)[min], (*h)[i]
		h.heapifyDown(min)
	}
}

func (h *HeapMinInt) heapifyUp(i int) {
	parent := (i - 1) / 2
	if (*h)[i] >= (*h)[parent] {
		return
	}
	(*h)[i], (*h)[parent] = (*h)[parent], (*h)[i]
	h.heapifyUp(parent)
}

type HeapMaxInt []int

func InitHeapMaxInt(arr []int) *HeapMaxInt {
	heap := HeapMaxInt(arr)
	for i := len(heap)/2 - 1; i >= 0; i-- {
		heap.heapifyDown(i)
	}
	return &heap
}

func (h *HeapMaxInt) Pop() int {
	item := (*h)[0]
	(*h)[0] = (*h)[len(*h)-1]
	(*h) = (*h)[:len(*h)-1]
	h.heapifyDown(0)
	return item
}

func (h *HeapMaxInt) Push(item int) {
	(*h) = append(*h, item)
	h.heapifyUp(len(*h) - 1)
}

func (h *HeapMaxInt) heapify(i int) {
	for i := len(*h)/2 - 1; i >= 0; i-- {
		(*h).heapifyDown(i)
	}
}

func (h *HeapMaxInt) heapifyDown(i int) {
	max := i
	left := 2*i + 1
	right := 2*i + 2

	if left < len(*h) && (*h)[left] > (*h)[max] {
		max = left
	}

	if right < len(*h) && (*h)[right] > (*h)[max] {
		max = right
	}

	if max != i {
		(*h)[i], (*h)[max] = (*h)[max], (*h)[i]
		h.heapifyDown(max)
	}
}

func (h *HeapMaxInt) heapifyUp(i int) {
	parent := (i - 1) / 2
	if (*h)[i] <= (*h)[parent] {
		return
	}
	(*h)[i], (*h)[parent] = (*h)[parent], (*h)[i]
	h.heapifyUp(parent)
}

func (h *HeapMaxInt) Mash2TopAndPushRemaning() int {
	if len(*h) == 0 {
		return 0
	}

	if len(*h) == 1 {
		return (*h)[0]
	}

	first := h.Pop()
	second := h.Pop()
	remaining := first - second
	if remaining > 0 {
		h.Push(remaining)
	}
	return remaining
}
```

# 2. Last stone weight II

https://leetcode.com/problems/last-stone-weight-ii/

## 2.1. Summary

The problem requires us to try mash stone together to have the last smallest remaining. So, the best scenario is that the remaining is zero, it means each pair stones will be the same weight, or their remaining pair stone will have the same weight.
It means:

```
StoneL1 + StoneL2 + ... + StoneL(n) = StoneR1 + StoneR2 + ... + StoneR(n)
or we can write
[StoneL1 + StoneL2 + ... + StoneL(n)] - [StoneR1 + StoneR2 + ... + StoneR(n)] = 0
```

![enter image description here](https://raw.githubusercontent.com/ledongthuc/notes/master/leetcode/last-stone-weight-2/LastStoneWeight2-Best%20scenario.png)

But if it's not the best scenario, then we need to find the smallest (x) from, it will be:

![enter image description here](https://raw.githubusercontent.com/ledongthuc/notes/master/leetcode/last-stone-weight-2/LastStoneWeight2-Normal%20scenario.png)

## 2.2. Math thinking

To find x, we will have:

```
[StoneL1 + StoneL2 + ... + StoneL(n)] - [StoneR1 + StoneR2 + ... + StoneR(n)] = x
<=> [StoneL1 + StoneL2 + ... + StoneL(n)] = x + [StoneR1 + StoneR2 + ... + StoneR(n)]
```

Recheck, we have another equation to calculate the total weight stone we have:

```
[StoneL1 + StoneL2 + ... + StoneL(n)] + [StoneR1 + StoneR2 + ... + StoneR(n)] = Sum
<=> x + [StoneR1 + StoneR2 + ... + StoneR(n)] + [StoneR1 + StoneR2 + ... + StoneR(n)] = sum
<=> x = Sum  - 2 * [StoneR1 + StoneR2 + ... + StoneR(n)]
```

From here, we can understand, if we want to find smallest x, we find largest `[StoneR1 + StoneR2 + ... + StoneR(n)]` with condition:

```
Sum  - 2 * [StoneR1 + StoneR2 + ... + StoneR(n)] >= 0
<=> Sum/2 - [StoneR1 + StoneR2 + ... + StoneR(n)] >= 0
<=> Sum/2 >= [StoneR1 + StoneR2 + ... + StoneR(n)]
```

It means we will find largest `[StoneR1 + StoneR2 + ... + StoneR(n)]` that is less than `1/2 of Sum` total weight of stones

## 2.3. Image thinking

Because Total left = Total right + remaining (if right's smaller than left)

Then, if we want to find x, it means we need to find the total Right

And if we want to find the smallest x, it means we need to find the biggest total Right we can from available stones

![enter image description here](https://raw.githubusercontent.com/ledongthuc/notes/master/leetcode/last-stone-weight-2/LastStoneWeight2-Find%20equation.png)

## 2.4. Combinations

The next question is how we can find maximum stones that are less than `1/2 of the sum weight of the total stone.`

The easiest solution is to try all stone combinations with a weight of less than 1/2 of sum and get the heaviest combinations.

![enter image description here](https://raw.githubusercontent.com/ledongthuc/notes/master/leetcode/last-stone-weight-2/LastStoneWeight2-combination.png)

Let's re-thinking a little bit about the remaining of a stone checking.

Let's check a stone1 with 1kg. If we know any combination y = stone2 + stone3 + stone4 that maximum remaining of stone 1, we can confirm the combination is available to use.

![enter image description here](https://raw.githubusercontent.com/ledongthuc/notes/master/leetcode/last-stone-weight-2/LastStoneWeight2-remaining%201.png)

The problem is we don't know any combination at the beginning, so we need to build the list caching of stone + their combination step by step:

![enter image description here](https://raw.githubusercontent.com/ledongthuc/notes/master/leetcode/last-stone-weight-2/LastStoneWeight2-remaining%202.png)

The maximum we have in the caching will be maximum stones that we can combine to.

Finally, apply `x = Sum  - 2 * [StoneR1 + StoneR2 + ... + StoneR(n)]` to find smallest stone x

## 2.5. Code

```go
func lastStoneWeightII(stones []int) int {
    totalStonesWeight := getTotalStonesWeight(stones)
    halfOfTotalStonesWeight := int(totalStonesWeight/2)
    cachedCombinations := map[int]struct{}{}
    maxCombination := 0
    
    for _, stone := range stones {
        if stone > halfOfTotalStonesWeight {
            continue
        }
        newCombinations := map[int]struct{}{stone: struct{}{}}
        maxCombination = max(stone, maxCombination)
        
        for cachedCombination := range cachedCombinations {
            newCombination := stone + cachedCombination
            if newCombination > halfOfTotalStonesWeight {
                continue
            }
            
            newCombinations[newCombination] = struct{}{}
            maxCombination = max(newCombination, maxCombination)
        }
        
        fillCacheToCache(newCombinations, cachedCombinations)
    }
    
    return totalStonesWeight - 2 * (maxCombination)
}

func getTotalStonesWeight(stones []int) (sum int) {
    for _, stone := range stones {
        sum += stone
    }
    return sum
}

func fillCacheToCache(from, to map[int]struct{}) {
    for item := range from {
        to[item] = struct{}{}
    }
}

func max(i, j int) int {
    if i > j {
        return i
    }
    return j
}
```
