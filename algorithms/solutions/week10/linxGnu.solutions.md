## Problem 1 - [Valid Palindrome II](https://leetcode.com/problems/valid-palindrome-ii/description/)

```go
func validPalindrome(s string) bool {
    n := len(s)
    if n <= 2 {
        return true
    }
    
    i, j := 0, n - 1
    for i < j && s[i] == s[j] {
        i++
        j--
    }
    
    if i >= j {
        return true
    }
    
    return isValidPalindrome(s, i + 1, j) || isValidPalindrome(s, i, j-1)
}

func isValidPalindrome(s string, i, j int) bool {
    for i < j && s[i] == s[j] {
        i++
        j--
    }
    
    return i >= j
}
```

## Problem 2 - [Flatten Binary Tree to Linked List](https://leetcode.com/problems/flatten-binary-tree-to-linked-list/description/)

```go
func flatten(root *TreeNode)  {
    flattenByTraversal(root)
}

func flattenByTraversal(root *TreeNode) (tail *TreeNode) {
    if root == nil {
        return root
    }
    
    // Check leave node
    if root.Left == nil && root.Right == nil {
        return root
    }
    
    if root.Left == nil {
        return flattenByTraversal(root.Right)
    }
    
    if root.Right == nil {
        root.Right, root.Left = root.Left, nil
        return flattenByTraversal(root.Right)
    }
    
    x := flattenByTraversal(root.Left)
    x.Right = root.Right
    root.Right, root.Left = root.Left, nil
    
    return flattenByTraversal(x.Right)
}
```

## Problem 3 - [Is Subsequence](https://leetcode.com/problems/is-subsequence/description/)

An O(S + T) solution.

If there are lots of incoming S, say S1, S2, ... , Sk where k >= 1B, and you want to check one by one to see if T has its subsequence, there is an O(S * K + T * 26) solution with O(T * 26) space which simulates Trie structure.

```go
func isSubsequence(s string, t string) bool {
    if len(s) == 0 {
        return true
    }
    
    n, m := len(s), len(t)
    if n > m {
        return false
    }
    
    var j int
    for i := range s {
        for j < m && t[j] != s[i] {
            j++
        }
        
        if j >= m {
            return false
        }
        
        j++
    }
    
    return true
}
```

## Problem Bonus - [The Skyline Problem](https://leetcode.com/problems/the-skyline-problem/description/)

Using Heap to observe heighest building

```go
type Building struct {
	H   int // the height of the building
	R   int // the x coordinate of right edge of the building
	Ind int // index in heap
}

type BuildingsHeap []*Building

func (h BuildingsHeap) Len() int { return len(h) }
func (h BuildingsHeap) Less(i, j int) bool {
	if h[i].H == h[j].H {
		return h[i].R > h[j].R
	}

	return h[i].H > h[j].H
}

func (h BuildingsHeap) Swap(i, j int) {
	h[i].Ind, h[j].Ind = j, i
	h[i], h[j] = h[j], h[i]
}

func (h *BuildingsHeap) Push(x interface{}) {
	n := len(*h)
	item := x.(*Building)
	item.Ind = n
	*h = append(*h, item)
}

func (h *BuildingsHeap) Pop() interface{} {
	old := *h
	n := len(old)
	x := old[n-1]
	*h = old[0 : n-1]
	return x
}

type VerticalLine struct {
	X    int  // x-axis of vertical line
	Type byte // Type of vertical line
	Bid  int  // building ID
}

func getSkyline(buildings [][]int) (result [][]int) {
	n := len(buildings)
	if n == 0 {
		return [][]int{}
	}

	// parsing buildings into cordinations of start/end points
	builds, vLines := parseData(buildings)
	numLines := len(vLines)

	// make a heap of buildings
	h := make(BuildingsHeap, 0, n+1)

	// result in form of points
	result = make([][]int, 0, (n<<2)+1)

	// now solve our problem
	var line *VerticalLine
	var i, j, k int

	// store current max height
	var curMaxHeight int

	for i < numLines {
		for j = i; j < numLines && vLines[j].X == vLines[i].X; j++ {
		}
		// [i, j) has the same x-axis

		// try to add/remove building to/from heap
		curMaxHeight = 0
		if len(h) > 0 { curMaxHeight = h[0].H }
        
		for k = i; k < j; k++ {
			if line = &vLines[k]; line.Type == 1 { // end of a building
				heap.Remove(&h, builds[line.Bid].Ind)
			} else { // start of a building
				heap.Push(&h, &builds[line.Bid])
			}
		}

		// heap is empty means end of block of buildings
		if len(h) == 0 {
			result = append(result, []int{vLines[i].X, 0})
		} else if h[0].H != curMaxHeight { // if not, check for change of max height
			result = append(result, []int{vLines[i].X, h[0].H})
		}

		// out of loop
		i = j
	}

	return
}

func parseData(buildings [][]int) (builds []Building, vLines []VerticalLine) {
	n := len(buildings)

	builds, vLines = make([]Building, n), make([]VerticalLine, n<<1)

	for i, v := range buildings {
		builds[i].H, builds[i].R = v[2], v[1]

		vLines[i].X, vLines[i].Type, vLines[i].Bid = v[0], 0, i
		vLines[i+n].X, vLines[i+n].Type, vLines[i+n].Bid = v[1], 1, i
	}

	sort.Slice(vLines, func(i, j int) bool { return vLines[i].X < vLines[j].X })

	return
}
```
