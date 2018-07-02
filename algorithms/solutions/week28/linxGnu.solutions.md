## Problem 1 - [Non-decreasing Array](https://leetcode.com/problems/non-decreasing-array/description/)

```go
func checkPossibility(nums []int) bool {
    n := len(nums)
    if n <= 1 {
        return true
    }
    
    for i := 0; i < n - 1; i++ {
        if nums[i] > nums[i+1] {
            return check(nums, i) || check(nums, i + 1)
        }
    }
    
    return true
}

func check(nums []int, ignoreIndex int) bool {
    n := len(nums)
    if ignoreIndex == 0 {
        return isIncrement(nums[1:])
    } else if ignoreIndex == n - 1 {
        return isIncrement(nums[:ignoreIndex])
    }
    
    if nums[ignoreIndex - 1] > nums[ignoreIndex + 1] {
        return false
    }
    
    return isIncrement(nums[:ignoreIndex]) && isIncrement(nums[ignoreIndex + 1:])
}

func isIncrement(nums []int) bool {
    n := len(nums)
    for i := 0; i < n - 1; i++ {
        if nums[i] > nums[i+1] {
            return false
        }
    }
    return true
}
```


## Problem 2 - [Permutations](https://leetcode.com/problems/permutations/description/)

```go
func permute(nums []int) [][]int {
    n := len(nums)
    if n == 0 {
        return [][]int{}
    }
    if n == 1 {
        return [][]int{nums}
    }
    
    var num int64
    for i := 2; i <= n; i++ {
        num *= int64(i)
    }
    
    return permute2(nums, 0, n, make([][]int, 0, num))
}

func permute2(nums []int, index, n int, result [][]int) [][]int {
    if index == n - 1 {
        tmp := make([]int, n)
        for i := range nums {
            tmp[i] = nums[i]
        }
        result = append(result, tmp)
        return result
    }
    
    for j := index; j < n; j++ {
        nums[j], nums[index] = nums[index], nums[j]
        result = permute2(nums, index + 1, n, result)
        nums[j], nums[index] = nums[index], nums[j]
    }
    
    return result
}
```

## Problem 4 - [Find Median from Data Stream](https://leetcode.com/problems/find-median-from-data-stream/)

```go
import "container/heap"

// An IntHeap is a min-heap of ints.
type IntLessHeap []int
func (h IntLessHeap) Len() int           { return len(h) }
func (h IntLessHeap) Less(i, j int) bool { return h[i] < h[j] }
func (h IntLessHeap) Swap(i, j int)      { h[i], h[j] = h[j], h[i] }

func (h *IntLessHeap) Push(x interface{}) {
	*h = append(*h, x.(int))
}

func (h *IntLessHeap) Pop() interface{} {
	old := *h
	n := len(old)
	x := old[n-1]
	*h = old[0 : n-1]
	return x
}

type IntLargeHeap []int
func (h IntLargeHeap) Len() int           { return len(h) }
func (h IntLargeHeap) Less(i, j int) bool { return h[i] > h[j] }
func (h IntLargeHeap) Swap(i, j int)      { h[i], h[j] = h[j], h[i] }

func (h *IntLargeHeap) Push(x interface{}) {
	*h = append(*h, x.(int))
}

func (h *IntLargeHeap) Pop() interface{} {
	old := *h
	n := len(old)
	x := old[n-1]
	*h = old[0 : n-1]
	return x
}


type MedianFinder struct {
    left IntLargeHeap
    right IntLessHeap
}


/** initialize your data structure here. */
func Constructor() MedianFinder {
    return MedianFinder{
        left:  make(IntLargeHeap, 0, 2048),
        right: make(IntLessHeap, 0, 2048),
    }
}


func (this *MedianFinder) AddNum(num int)  {
    var top int
    if len(this.left) == 0 {
        heap.Push(&this.left, num)
    } else if top = this.left[0]; num > top {
        heap.Push(&this.right, num)
        if len(this.left) < len(this.right) {
            heap.Push(&this.left, heap.Pop(&this.right).(int))
        }
    } else if len(this.left) == len(this.right) {
        heap.Push(&this.left, num)
    } else {
        this.left[0] = num
        heap.Fix(&this.left, 0)
        heap.Push(&this.right, top)
    }
}


func (this *MedianFinder) FindMedian() float64 {
    if len(this.left) == 0 {
        return 0
    } else if len(this.left) != len(this.right) {
        return float64(this.left[0])
    } else {
        return float64(this.left[0] + this.right[0]) / 2.0
    }
}


/**
 * Your MedianFinder object will be instantiated and called as such:
 * obj := Constructor();
 * obj.AddNum(num);
 * param_2 := obj.FindMedian();
 */
```