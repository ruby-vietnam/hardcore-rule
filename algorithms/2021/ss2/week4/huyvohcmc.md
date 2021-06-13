# Easy: Merge Sorted Array

https://leetcode.com/problems/merge-sorted-array/

### Approach

Loop through 2 arrays backward, check their last elements nums1[i] and nums2[j], if nums1[i] is larger we assign nums1[k] to nums1[i] and decrease i, k to 1, else assign nums1[k] to nums2[j] and decrease j, k to 1.

```
(k = m + n - 1, m = nums1.length - 1, n = nums2.length - 1)
```

### Code

```go
func merge(nums1 []int, m int, nums2 []int, n int) {
	if n == 0 {
		nums1 = nums1[:m]
	}
	i, j, k := m-1, n-1, m+n-1
	for i >= 0 && j >= 0 {
		if nums1[i] >= nums2[j] {
			nums1[k] = nums1[i]
			i -= 1
		} else {
			nums1[k] = nums2[j]
			j -= 1
		}
		k -= 1
	}
	for j >= 0 {
		nums1[j] = nums2[j]
		j--
	}
}
```

Time complexity: O(m+n).

### Submission Detail

```
59 / 59 test cases passed.
Status: Accepted
Runtime: 0 ms
Memory Usage: 2.3 MB
```

# Medium: Shuffle an Array

https://leetcode.com/problems/shuffle-an-array/

### Approach

We can apply [Fisher–Yates shuffle](https://en.wikipedia.org/wiki/Fisher%E2%80%93Yates_shuffle) algorithm to solve this problem:

```
for i from 0 to n-1 do:
    j <- random number in range 0..n
    swap arr[i] and arr[j]
```

### Code

```go
import "math/rand"

type Solution struct {
	Nums []int
}

func Constructor(nums []int) Solution {
	return Solution{Nums: nums}
}

/** Resets the array to its original configuration and return it. */
func (this *Solution) Reset() []int {
	return this.Nums
}

/** Returns a random shuffling of the array. */
func (this *Solution) Shuffle() []int {
	numsLength := len(this.Nums)
	shuffled := make([]int, numsLength)
	copy(shuffled, this.Nums)
	for i := range shuffled {
		randomIndex := rand.Intn(numsLength)
		shuffled[i], shuffled[randomIndex] = shuffled[randomIndex], shuffled[i]
	}
	return shuffled
}
```

Time complexity: O(n).

### Submission Detail

```
10 / 10 test cases passed.
Status: Accepted
Runtime: 48 ms
Memory Usage: 9.4 MB
```

# Hard: Median of Two Sorted Arrays

### Approach

My approach with O(m+n) time complexity and O(m+n) space complexity:
1. Merge 2 sorted arrays into a third array of length `m+n`, similar to the easy problem.
2. If `m+n` is odd, median of the third array is the value of the middle element.
3. If `m+n` is even, median of the third array is average of middle two elements.

### Code

```go
func findMedianSortedArrays(nums1 []int, nums2 []int) float64 {
	m, n := len(nums1), len(nums2)
	l := m + n
	if l == 0 {
		return 0
	}

	nums := make([]int, l)
	i, j, k := m-1, n-1, l-1
	for i >= 0 && j >= 0 {
		if nums1[i] > nums2[j] {
			nums[k] = nums1[i]
			i--
		} else {
			nums[k] = nums2[j]
			j--
		}
		k--
	}

	for i >= 0 {
		nums[k] = nums1[i]
		i--
		k--
	}
	for j >= 0 {
		nums[k] = nums2[j]
		j--
		k--
	}

	if l%2 == 1 {
		return float64(nums[l/2])
	} else {
		return (float64(nums[l/2-1]) + float64(nums[l/2])) / 2
	}
}
```

Time complexity: O(m+n).

### Submission Detail

```
2094 / 2094 test cases passed.
Status: Accepted
Runtime: 8 ms
Memory Usage: 5.8 MB
```
