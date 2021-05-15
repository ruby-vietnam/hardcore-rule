# Easy two-sum-iv-input-is-a-bst
https://leetcode.com/problems/two-sum-iv-input-is-a-bst/

Submission Details:

```
422 / 422 test cases passed.
Status: Accepted
Runtime: 28 ms
Memory Usage: 7.9 MB
```

We will traverse through the tree and get all value in this tree and save them in to an array with order from min to max. 
After that we will use two pointer technique to find if exist a pair have sum equal to k.

This appoarch will have O(n) space and O(n) time.


```Go
func findTarget(root *TreeNode, k int) bool {
	list := make([]int, 0)
	inorderRect(root, &list)

	l := 0
	r := len(list) - 1
	for l < r {
		if k == list[l] + list[r] {
			return  true
		} else if k > list[l] + list[r] {
			l++
		} else {
			r--
		}
	}

	return false
}

func inorderRect(root *TreeNode, list *[]int)  {
	if root != nil {
		inorderRect(root.Left, list)
		*list = append(*list, root.Val)
		inorderRect(root.Right, list)
	}
}
```

# Medium: path-sum-iii
https://leetcode.com/problems/path-sum-iii

Submission Details:

```
126 / 126 test cases passed.
Status: Accepted
Runtime: 16 ms
Memory Usage: 4.4 MB
```

```Go
func pathSum(root *TreeNode, targetSum int) int {
	if root == nil { return 0 }

	return pathOnNode(root, targetSum) + pathSum(root.Left, targetSum) + pathSum(root.Right, targetSum)
}

func pathOnNode(root *TreeNode, sum int) int  {
	count := 0
	if root == nil { return 0 }
    if root.Val == sum { count ++ }
    
	return count + pathOnNode(root.Left, sum - root.Val) + pathOnNode(root.Right, sum - root.Val)
}
```

# Hard: binary-tree-maximum-path-sum
https://leetcode.com/problems/binary-tree-maximum-path-sum


Submission Details:
```
94 / 94 test cases passed.
Status: Accepted
Runtime: 36 ms
Memory Usage: 7.3 MB
```




```Go
type Res struct {
	Val int
}

func maxPathSum(root *TreeNode) int {
	res := Res{Val: math.MinInt8}
	maxSum(root, &res)
	return res.Val
}

func maxSum(node *TreeNode, res *Res) int {
	if node == nil {
		return  0
	}

	 l := maxSum(node.Left, res)
	 r := maxSum(node.Right, res)
	 a := Max(l, r)
	 b := Max(node.Val, node.Val + a)
	 c := Max(b, node.Val + l + r)
	 res.Val = Max(res.Val, c)
	return  b

}
func Max(x, y int) int {
	if x < y {
		return y
	}
	return x
}
```