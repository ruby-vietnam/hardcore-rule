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