Problem 1:

https://leetcode.com/problems/find-the-difference/description/

```go
func findTheDifference(s string, t string) byte {
    var differentByte byte
    if len(s) == len(t) {
        return differentByte
    }
    
    m := make([]int, 10000)
    for index, _ := range t {
        m[t[index]]++
        if index <= len(s) -1 {
            m[s[index]]++
        }
    }
    
    for index, v := range m {
        if v % 2 != 0 {
            return byte(index)
        }
    }
    return differentByte
}
```

Problem 2:

https://leetcode.com/problems/binary-tree-level-order-traversal/description

```go
/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func levelOrder(root *TreeNode) (r [][]int) {
    if root == nil {
        return r
    }
    stackT := NewStack()
    stackT.Push(&Node{root, 0})
    for  {
        checkingNode := stackT.Pop()
        if checkingNode == nil {
            break
        }
        if checkingNode.Level >= len(r) {
            r = append(r, []int{checkingNode.Value.Val})
        } else {
            fmt.Println(checkingNode.Level, len(r))
            r[checkingNode.Level] = append([]int{checkingNode.Value.Val}, r[checkingNode.Level]...)
        }
        if checkingNode.Value.Left != nil {
            stackT.Push(&Node{checkingNode.Value.Left, checkingNode.Level+1})
        }
        if checkingNode.Value.Right != nil {
            stackT.Push(&Node{checkingNode.Value.Right, checkingNode.Level+1})
        }
    }
    return r
}

type Node struct {
	Value *TreeNode
    Level int
}

func NewStack() *Stack {
	return &Stack{}
}

type Stack struct {
	nodes []*Node
	count int
}

func (s *Stack) Push(n *Node) {
	s.nodes = append(s.nodes[:s.count], n)
	s.count++
}
a
func (s *Stack) Pop() *Node {
	if s.count == 0 {
		return nil
	}
	s.count--
	return s.nodes[s.count]
}

```
