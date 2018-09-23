```go
func MergeSortedArrays(nums1 []int, m int, nums2 []int, n int) {
	j := n - 1
	i := m - 1
	k := m + n - 1
	for j >= 0 {
		if i < 0 || nums2[j] > nums1[i] {
			nums1[k] = nums2[j]
			j--
		} else {
			nums1[k] = nums1[i]
			i--
		}
		k--
	}
}
```
