## Problem 1

```ruby
# @param {Integer[]} nums
# @return {Integer}
def majority_element(nums)
  h = {}
  nums.each do |num|
    h[num] = h.has_key?(num) ? h[num] += 1 : 1
  end
  
  h.each do |key, value|
    return key if value > (nums.length / 2)
  end
end
```

## Problem 3

```ruby
# @param {Integer[]} nums1
# @param {Integer[]} nums2
# @return {Float}
def find_median_sorted_arrays(nums1, nums2)
  merged = []
  l1, l2 = 0, 0
  until l1 >= nums1.length && l2 >= nums2.length do
    if l1 >= nums1.length 
      merged << nums2[l2]
      l2 += 1
      next
    end
    
    if l2 >= nums2.length
      merged << nums1[l1]
      l1 += 1
      next
    end
      
    if nums1[l1] < nums2[l2]
      merged << nums1[l1]
      l1 +=1
    else
      merged << nums2[l2]
      l2 += 1
    end
  end
  
  if merged.length % 2 == 0 
    (merged[merged.length / 2] + merged[merged.length / 2 - 1]) / 2.0
  else
    merged[merged.length / 2]*1.0
  end
end
```

## Problem 4

```go

type NumArray struct {
	nums        []int
	segmentTree []int
}

func Constructor(nums []int) NumArray {
	narr := NumArray{
		nums:        nums,
		segmentTree: make([]int, len(nums)*4),
	}
	if len(nums) > 0 {
		narr.initTree(0, 0, len(nums)-1)
	}

	return narr
}

func (this *NumArray) initTree(i, left, right int) int {
	if left == right {
		this.segmentTree[i] = this.nums[left]
		return this.nums[left]
	}

	mid := (left + right) / 2
	this.segmentTree[i] = this.initTree(i*2+1, left, mid) + this.initTree(i*2+2, mid+1, right)
	return this.segmentTree[i]
}

func (this *NumArray) Update(i int, val int) {
	diff := val - this.nums[i]
	this.nums[i] = val

	this.update(i, 0, diff, 0, len(this.nums)-1)
}

func (this *NumArray) update(i, currentIndex, diff, l, r int) {
	if l > i || r < i {
		return
	}

	if l <= i && i <= r {
		this.segmentTree[currentIndex] += diff
	}

	if l == r {
		return
	}

	mid := (l + r) / 2
	if i <= mid {
		this.update(i, currentIndex*2+1, diff, l, mid)
	}
	if i > mid {
		this.update(i, currentIndex*2+2, diff, mid+1, r)
	}
}

func (this *NumArray) SumRange(i, j int) int {
	sum := this.sum(0, i, j, 0, len(this.nums)-1)
	return sum
}

func (this *NumArray) sum(index, l, r, u, v int) int {

	if index >= len(this.segmentTree) {
		return 0
	}
	// completely outside
	if l > v || r < u {
		return 0
	}

	// completely within
	if l <= u && r >= v {
		return this.segmentTree[index]
	}

	// overlap
	mid := (u + v) / 2
	return this.sum(index*2+1, l, r, u, mid) + this.sum(index*2+2, l, r, mid+1, v)
}
 ```
