## Problem 1 - [Climbing Stairs](https://leetcode.com/problems/climbing-stairs/description/)

```go
// Fibonaci number
func climbStairs(n int) int {
    if n <= 2 {
        return n
    }
    
    a, b, c := 1, 2, 0
    for i := 3; i <= n; i++ {
        c = a + b
        a, b = b, c
    }
    
    return c
}
```

## Problem 2 - [Longest Substring Without Repeating Characters](https://leetcode.com/problems/longest-substring-without-repeating-characters/description/)

```go
func lengthOfLongestSubstring(s string) int {
    t, m := []byte(s), make(map[byte]int)
    
    max, currentLen := 0, 0 
    for ind, v := range t {
        if p, ok := m[v]; !ok || p < ind - currentLen {
            currentLen++
        } else {
            currentLen = ind - p
        }
        
        if currentLen > max {
            max = currentLen
        }
        
        m[v] = ind
    }
    
    return max
}
```

## Problem 3 - [Course Schedule](https://leetcode.com/problems/course-schedule/description/)

```go
// O(M) solution uses Tarzan to find strong connected components
// Other: M log N solution is using TOPO Graph
func canFinish(numCourses int, prerequisites [][]int) bool {
    g := DirectGraph{n: numCourses, edges: make([][]int, numCourses)}
    
    for _, e := range prerequisites {
        g.edges[e[1]] = append(g.edges[e[1]], e[0])
    }
    
    return !g.HasCircle()
}

type DirectGraph struct {
    n int
    edges [][]int
}

func (g *DirectGraph) HasCircle() bool {
    num, low := make([]int, g.n), make([]int, g.n)
    count, stack := 0, 0
    
    for i := 0; i < g.n; i++ {
        if stack = 0; num[i] == 0 && g.foundCircle(i, num, low, &count, &stack) {
            return true
        }
    }
    
    return false
}

// tarzan visit
func (g *DirectGraph) foundCircle(u int, num, low []int, count *int, stackCounter *int) bool {
    newCount := *count + 1
    num[u], low[u], *count = newCount, newCount, newCount
    
    startStack := *stackCounter
    *stackCounter += 1
    
    for _, v := range g.edges[u] {
        if num[v] != 0 {
            low[u] = min(low[u], num[v])
        } else if g.foundCircle(v, num, low, count, stackCounter) {
            return true
        } else {
            low[u] = min(low[u], low[v])
        }
    }
    
    if num[u] == low[u] {
        if *stackCounter - startStack != 1 {
            return true
        }
        *stackCounter = startStack
        num[u], low[u] = g.n + 1, g.n + 1
    }
    
    return false
}

func min(a, b int) int {
    if a < b {
        return a
    }
    return b
}
```

## Problem 4 - [Sum of Subsequence Widths](https://leetcode.com/problems/sum-of-subsequence-widths/description/)

```go
// Easy to prove when ai is sorted: 
//            SUM( ai * (2^i - 1) - ai * (2^(n-i-1) - 1) )
func sumSubseqWidths(A []int) int {
    n := len(A)
    
    var mod int64 = 1000000007
    pow := make([]int64, n + 1)
    
    pow[0] = 1
    for i := 1; i <= n; i++ {
        pow[i] = (pow[i-1] << 1) % mod
    }
    
    sort.Slice(A, func(i, j int) bool {
        return A[i] < A[j]  
    })
    
    var sum int64
    for i := range A {
        
        ai := int64(A[i]) % mod
        sum = (sum + (ai * (pow[i] - 1)) % mod) % mod
        sum = (sum - (ai * (pow[n-i-1] - 1)) % mod) % mod
        sum %= mod
    }
    
    if sum < 0 {
        sum += mod
    }
    
    return int(sum)
}
```