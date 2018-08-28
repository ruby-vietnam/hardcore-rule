Problem 1:

https://leetcode.com/problems/climbing-stairs/description/

```go
func climbStairs(n int) int {
	if n <= 2 {
		return n
	}

	n1 := 1
	n2 := 2
	for i := 2; i < n; i++ {
		n1, n2 = n2, n1+n2
	}

	return n2
}
```

Problem 2:

https://leetcode.com/problems/longest-substring-without-repeating-characters/description/

```go
func lengthOfLongestSubstring(s string) int {
    max := 0
    mOccur := make([]int, 256, 256)
    j := 0
    for i := 0; i < len(s); i++ {
        ch := s[i]
        mOccur[ch]++
        for mOccur[ch] > 1 {
            mOccur[s[j]]--
            j++
        }
        max = Max(max, i-j+1)
    }
    return max
}

func Max(a, b int) int {
    if a > b {
        return a
    } else {
        return b
    }
}

```

Problem 3:

https://leetcode.com/problems/course-schedule/description/

```go
func canFinish(numCourses int, prerequisites [][]int) bool {
    gr := make([][]int, numCourses, numCourses)
    degree := make([]int, numCourses, numCourses)
    var bfs []int
    for _, e := range prerequisites {
        gr[e[1]] = append(gr[e[1]], e[0])
        degree[e[0]]++
    }
    for i:=0; i < numCourses; i++ {
        if degree[i] == 0 {
            bfs = append(bfs, i)
        }
    }
    for i := 0; i < len(bfs); i++ {
        for _, j := range gr[bfs[i]]{
            degree[j]--
            if degree[j] == 0 {
                bfs = append(bfs, j)
            }
        }
    }
    return len(bfs) == numCourses
}
```
