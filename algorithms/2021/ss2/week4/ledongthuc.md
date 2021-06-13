# 1. Merge Sorted Array

https://leetcode.com/problems/merge-sorted-array/

## 1.1. Summary

 - Move nums1 to bottom, keep free front part for the result.

![enter image description here](https://raw.githubusercontent.com/ledongthuc/notes/master/leetcode/merge-sorted-array/MergeSortedArray-push%20data%20back.png)

 - Loop through nums1 (bottom part) and nums2, compare and pick a smaller element to the front part of nums1.
 
 ![enter image description here](https://raw.githubusercontent.com/ledongthuc/notes/master/leetcode/merge-sorted-array/MergeSortedArray-merge.png)


```go
func merge(nums1 []int, m int, nums2 []int, n int) {
	if n == 0 {
		return
	}
	if m == 0 {
	        copy(nums1, nums2)
		return
	}
	pushDataBack(nums1, m, n)
	for im, in, i := n, 0, 0; (im < m+n || in < n) && i < m+n; i++ {
		if (im < m+n && in >=  n) || (im < m+n && nums1[im] < nums2[in]) {
			nums1[i] = nums1[im]
			im++
		} else if in < n {
			nums1[i] = nums2[in]
			in++
		} else {
			break
		}
	}
}

func pushDataBack(nums []int, m, n int) {
	for i := m - 1; i >= 0; i-- {
		nums[i+n] = nums[i]
	}
}
```


# 2. Shuffle an Array

https://leetcode.com/problems/shuffle-an-array/

## 2.1. Summary

- Use Fisher–Yates to suffer array (https://en.wikipedia.org/wiki/Fisher%E2%80%93Yates_shuffle)

- Generate pseudorandom Xorshift star (https://en.wikipedia.org/wiki/Xorshift#xorshift*)

```go
type Solution struct {
    state uint64
    originalArray []int
}


func Constructor(nums []int) Solution {
    return Solution{
        state: generateSeeding(uint64(time.Now().UnixNano())),
        originalArray: nums,
    }
}


/** Resets the array to its original configuration and return it. */
func (this *Solution) Reset() []int {
    return this.originalArray
}


/** Returns a random shuffling of the array. */
func (this *Solution) Shuffle() []int {
    l := len(this.originalArray)
    
    newArr := make([]int, len(this.originalArray))
    copy(newArr, this.originalArray)
    
    for i := l - 1; i > 0; i-- {
        this.state = generateSeeding(this.state)
        swapIndex := this.state % uint64(i+1)
        newArr[i], newArr[swapIndex] = newArr[swapIndex], newArr[i]
    }
    
    return newArr
}

// Xorshift star
func generateSeeding(state uint64) uint64 {
    newState := state
    newState ^= newState << 12
	newState ^= newState >> 25
	newState ^= newState << 27
    return newState;
}
```
