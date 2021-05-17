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