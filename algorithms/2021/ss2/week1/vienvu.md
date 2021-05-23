# Easy: find-the-town-judge
https://leetcode.com/problems/find-the-town-judge/

Submission Details:

```
92 / 92 test cases passed.
Status: Accepted
Runtime: 104 ms
Memory Usage: 7.4 MB
```

We convert trust  array become a graph. This graph is [][]int. We need to find judge. 
 - The judge trust nobody so in graph must have array empty. 
 - Every body just the Judge so remain array must contain this index of the judge.


```Go
func findJudge(n int, trust [][]int) int {
	graph := make([][]int, n)
	for i:= 0; i < len(trust); i++ {
		r := trust[i]
		graph[r[0] - 1] = append(graph[r[0] - 1], r[1] - 1)
	}

    possibleJudge := -1
	for i := 0; i <len(graph); i++ {
		if len(graph[i]) == 0 {
			possibleJudge = i 
            break
		}
	}
    if possibleJudge == -1 { return -1 }
    
    for i := 0; i < len(graph); i++ { 
        if i != possibleJudge && !intIntSlice(possibleJudge, graph[i]) {
            return -1
        }
    }
    
	return possibleJudge + 1
}

func intIntSlice(a int, list []int) bool {
    for _, b := range list {
        if b == a {
            return true
        }
    }
    return false
}  
```

# Medium: all-nodes-distance-k-in-binary-tree
https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree/

Sumission Details:
```
57 / 57 test cases passed.
Status: Accepted
Runtime: 0 ms
Memory Usage: 3.4 MB
```

We convert binary tree to a graph. After that we find path from the given have distance k 

```Go
func distanceK(root *TreeNode, target *TreeNode, k int) []int {
	graph := make([][]int, 501)

	genGraph(root, &graph)

	result := make([]int, 0)
	distance(target.Val, -1, &graph, k, &result)

	return result
}

func distance(node int, previousNode int, graph *[][]int, k int, result *[]int) {
	if k == 0  {
		*result = append(*result, node)
		return
	}
	for i := range (*graph)[node] {
		if (*graph)[node][i] != previousNode {
			distance((*graph)[node][i], node, graph, k - 1, result)
		}
	}
}

func genGraph(root *TreeNode, graph *[][]int)  {
	if root.Left != nil {
		(*graph)[root.Val] =  append((*graph)[root.Val], root.Left.Val)
		(*graph)[root.Left.Val] = append((*graph)[root.Left.Val], root.Val)
	}
	if root.Right != nil {
		(*graph)[root.Val] = append((*graph)[root.Val], root.Right.Val)
		(*graph)[root.Right.Val] = append((*graph)[root.Right.Val], root.Val)
	}

	if root.Left != nil {
		genGraph(root.Left, graph)
	}
	if root.Right != nil {
		genGraph(root.Right, graph)
	}
}
```