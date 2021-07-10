# Easy: Binary Tree Paths

https://leetcode.com/problems/binary-tree-paths/

### Approach

We're going to use DFS to solve this problem. Starting froo root node, traverse down each root child and keep track of the nodes we have been traversed, until we hit a leaf, then put the traversed nodes into a result array and goes back. The idea is very simple.

### Code

```go
import "strconv"

func binaryTreePaths(root *TreeNode) []string {
	paths := []string{}
	if root == nil {
		return paths
	}

	currentPath := strconv.Itoa(root.Val)
	if root.Left == nil && root.Right == nil {
		paths = append(paths, currentPath)
	}
	if root.Left != nil {
		travel(root.Left, currentPath, &paths)
	}
	if root.Right != nil {
		travel(root.Right, currentPath, &paths)
	}

	return paths
}

func travel(node *TreeNode, currentPath string, paths *[]string) {
	currentPath += "->" + strconv.Itoa(node.Val)
	if node.Left == nil && node.Right == nil {
		*paths = append(*paths, currentPath)
		return
	}
	if node.Left != nil {
		travel(node.Left, currentPath, paths)
	}
	if node.Right != nil {
		travel(node.Right, currentPath, paths)
	}
}
```

Time complexity: O(n).

### Submission Detail

```
208 / 208 test cases passed.
Status: Accepted
Runtime: 0 ms
Memory Usage: 2.4 MB
```

# Medium: Find K Closest Elements

https://leetcode.com/problems/find-k-closest-elements/

### Code

```go
import "math"

func findClosestElements(arr []int, k int, x int) []int {
	low, high := 0, len(arr)-1
	for high-low >= k {
		if math.Abs(float64(arr[low]-x)) > math.Abs(float64(arr[high]-x)) {
			low++
		} else {
			high--
		}
	}
	res := []int{}
	for i := low; i <= high; i++ {
		res = append(res, arr[i])
	}
	return res
}
```

Time complexity: O(n).

### Submission Detail

```
63 / 63 test cases passed.
Status: Accepted
Runtime: 60 ms
Memory Usage: 8.2 MB
```
