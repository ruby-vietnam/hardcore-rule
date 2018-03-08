## Problem 4
Use segment tree

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
