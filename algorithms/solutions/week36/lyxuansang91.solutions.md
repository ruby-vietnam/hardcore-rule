# Problem 1 - [Climbing Stairs](https://leetcode.com/problems/climbing-stairs/description/)

## Solution: Using DP (Dynamic Programming)
Time complexity: O(N)

```go
func climbStairs(n int) int {
    dp := make([]int, n+1)
    dp[0], dp[1] = 1, 1
    for i := 2; i <= n; i++ {
        dp[i] = dp[i-1] + dp[i-2]
    }
    return dp[n]
}
```

# Problem 3 - [Course Schedule](https://leetcode.com/problems/course-schedule/description/)

Time complexity: O(M + N)

```go
func dfs(edges [][]int, visit []int, u int) bool {
    if visit[u] == 1 {
        return true
    }
    
    visit[u] = -1 // being visited
    for _, v := range edges[u] {
        if visit[v] == -1 {
            return false
        }
        if visit[v] == 0 && !dfs(edges, visit, v) {
            return false
        }
    }
    visit[u] = 1 // visited
    return true
}
func canFinish(numCourses int, prerequisites [][]int) bool {
    edges := make([][]int, numCourses + 1)
    for _, val := range prerequisites {
        edges[val[0]] = append(edges[val[0]], val[1])
    }
    visit := make([]int, numCourses + 1)
    for i := 0; i < numCourses; i++ {
        if visit[i] == 0 {
            if !dfs(edges, visit, i) {
                return false
            }
        }
    }
    return true
}
```

# Problem 4 - [Sum of Subsequence Widths](https://leetcode.com/problems/sum-of-subsequence-widths/description/)

```go
func sumSubseqWidths(A []int) int {
    MOD := 1000000007
    n := len(A)
    sort.Ints(A)
    pow2 := make([]int, n)
    pow2[0] = 1
    for i := 1; i < n; i++ {
        pow2[i] = pow2[i-1] * 2 % MOD
    }
    ans := 0
    for i := 0; i < n; i++ {
        ans += (pow2[i] - 1) * A[i] % MOD
        ans -= (pow2[n-1-i] - 1) * A[i] % MOD
        ans = (ans + MOD) % MOD
    }

    return ans;
}
```