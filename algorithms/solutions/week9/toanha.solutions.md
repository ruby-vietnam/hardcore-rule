## Problem 1

https://leetcode.com/problems/longest-harmonious-subsequence

Sử dụng 1 mảng để đếm số lần xuất hiện của các số trong mảng
Ta sẽ kiểm tra số hiện tại với số lớn hơn và nhỏ hơn 1 đơn vị
LHS sẽ là tổng số lần xuất hiện của số hiện tại và số hơn nó 1 đơn vị hoặc số hiện tại và số nhỏ hơn nó 1 đơn vị

```golang
func findLHS(nums []int) int {
	var m = map[int]int{}
	var LHS int

	for _, num := range nums {
		if _, ok := m[num]; ok {
			m[num] = m[num] + 1
		} else {
			m[num] = 1
		}

		if _, ok := m[num+1]; ok {
			LHS = max(LHS, m[num]+m[num+1])
		}

		if _, ok := m[num-1]; ok {
			LHS = max(LHS, m[num]+m[num-1])
		}
	}

	return LHS
}

func max(x, y int) int {
	if x < y {
		return y
	}
	return x
}
```

## Problem 2

https://leetcode.com/problems/merge-two-binary-trees

Đệ quy

```golang
func mergeTrees(t1 *TreeNode, t2 *TreeNode) *TreeNode {
	if t1 == nil {
		return t2
	}

	if t2 == nil {
		return t1
	}

	t := &TreeNode{
		Val: t1.Val + t2.Val,
	}

	t.Left = mergeTrees(t1.Left, t2.Left)
	t.Right = mergeTrees(t1.Right, t2.Right)

	return t
}
```
