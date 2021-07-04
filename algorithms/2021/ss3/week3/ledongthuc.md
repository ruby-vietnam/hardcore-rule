# 1. Binary Tree Paths

https://leetcode.com/problems/binary-tree-paths/

## 1.1. Summary

 - Use deep first search, collect leaves and put to final result

![enter image description here](https://upload.wikimedia.org/wikipedia/commons/thumb/7/7f/Depth-First-Search.gif/220px-Depth-First-Search.gif)

## 1.2. Code

```go
/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func binaryTreePaths(root *TreeNode) []string {
    return gogogo(root, fmt.Sprintf("%d", root.Val))
}

func gogogo(node *TreeNode, pathValue string) []string {
    if node.Left == nil && node.Right == nil {
        return []string{pathValue}
    }
    
    result := []string{}
    if node.Left != nil {
        result = append(result, gogogo(node.Left, fmt.Sprintf("%s->%d", pathValue, node.Left.Val))...)
    }
    if node.Right != nil {
        result = append(result, gogogo(node.Right, fmt.Sprintf("%s->%d", pathValue, node.Right.Val))...)
    }
    return result
}
```

# 2. Find K Closest Elements

https://leetcode.com/problems/find-k-closest-elements/

## 2.1. Summary

 - Use binary search to find which position (`p`) in `arr` that `x` should be stay at
 - From position `p` of `x` in `arr`, sequencely check  `p-1` and `p+1` to find closest element and put to result
	 - note 1: handle case `x` is less than first element array, or `x` is greater than final element array.
	 - note 2: handle case array don't have enough of `k` final result
	 - note 3: handle case if `x` doesn't match any element in array `arr`, need to check `x` closer than p+1 or p-1 to decide its position.


## 2.2. Code

```go
func findClosestElements(arr []int, k int, x int) []int {
    if len(arr) <= k {
        return arr
    }
    
    position := findPositionOfX(arr, x)
    result := collectClosestElement(arr, k, x, position)
    sort.Ints(result)
    return result
}

func findPositionOfX(arr []int, x int) int {
    start := 0
    l := len(arr)
    p := -1
    
    for {
        if l == 1 {
            p = start
            break
        }
        
        p = start + (l - 1) / 2
        
        if x == arr[p] {
            return p
        }
        
        if x > arr[p] {
            start = p + 1
        }
             
        l = l/2
    }
    return p
}

func collectClosestElement(arr []int, k int, x int, p int) []int {
    leftP := p
    rightP := p + 1
    
    if p - 1 >= 0 && aIsCloserThanB(arr[p-1], arr[p], x) {
        // In case p-1 is closer than p
        leftP--
        rightP--
    }
    
    var result []int
    for (leftP >= 0 || rightP < len(arr)) && k > 0 {
        hasLeft := leftP >= 0
        hasRight := rightP < len(arr)
        
        k--
        
        if hasLeft && !hasRight {
            result = append(result, arr[leftP])
            leftP--
            continue
        }
        
        if !hasLeft && hasRight {
            result = append(result, arr[rightP])
            rightP++
            continue
        }
        
        a := arr[leftP]
        b := arr[rightP]
        
        if aIsCloserThanB(a, b, x) {
            result = append(result, arr[leftP])
            leftP--
            continue
        }
        result = append(result, arr[rightP])
        rightP++
    }
    return result
}

// a less than x, b is greater than x
func aIsCloserThanB(a, b, x int) bool {
    return -(a - x) < b - x || -(a - x) == b - x
}
```

# 3. Sum Root to Leaf Numbers

https://leetcode.com/problems/sum-root-to-leaf-numbers/

## 3.1. Summary

 - Use deep first search, collect leaves and put to final result
 - Each node from root  multiple with  10

![enter image description here](https://upload.wikimedia.org/wikipedia/commons/thumb/7/7f/Depth-First-Search.gif/220px-Depth-First-Search.gif)


## 3.2. Code

```go
/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func sumNumbers(root *TreeNode) int {
    arr := collectNumber(root, root.Val)
    var result int
    for _, item := range arr {
        result += item
    }
    return result
}

func collectNumber(node *TreeNode, value int) []int {
    if node.Left == nil && node.Right == nil {
        return []int{value}
    }
    
    var result []int
    if node.Left != nil {
        result = append(result, collectNumber(node.Left, value * 10 + node.Left.Val)...)
    }
    if node.Right != nil {
        result = append(result, collectNumber(node.Right, value * 10 + node.Right.Val)...)
    }
    return result
}
```
