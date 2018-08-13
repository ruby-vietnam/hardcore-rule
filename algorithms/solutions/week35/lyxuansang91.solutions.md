# [Problem 1 - K-based Numbers](http://acm.timus.ru/problem.aspx?space=1&num=1009)

## Solution

Using Dynamic Programming. Let f(i,j) shows the numbers of k-based numbers with i-digit and end at j( j equal to 0 or 1).

- f(1, 1) = k - 1
- f(i, 0) = f(i - 1, 1)
- f(i, 1) = (f(i - 1, 1) + f(i - 1, 0)) * (k - 1)

The answer is f(n, 0) + f(n, 1)
Time complexity: O(N)

```cpp
#include <iostream>

using namespace std;
typedef long long ll;


ll calculate(const int &n, const int &k) {
    if(n == 1) return k;
    ll f[20][2]; /* dynamic programming f[i][j] = result at i-digit, and end is j (j = 0 or 1) */
    for(int i = 0; i < n; i++)
        for(int j = 0; j < 2; j++)
            f[i][j] = 0;
    f[1][1] = k-1;
    for(int i = 2; i <= n; i++) {
        f[i][0] = f[i-1][1];
        f[i][1] = (f[i-1][1] + f[i-1][0]) * (k-1);
    }
    return f[n][1] + f[n][0];
}

int main() {
    int n,k;
    cin >> n >> k;
    cout << calculate(n, k) << endl;
    return 0;
}
```

# [Problem 2 - Spiral Matrix III](https://leetcode.com/contest/weekly-contest-97/problems/spiral-matrix-iii/)

```golang
func inside(R int, C int, r int, c int) bool {
    return 0 <= r && r < R && 0 <= c && c < C
}
func spiralMatrixIII(R int, C int, r0 int, c0 int) [][]int {
    result := make([][]int, R * C)
    for i := range result {
        result[i] = make([]int, 2)
    }
    dr := []int {0, 1, 0, -1}
    dc := []int {1, 0, -1, 0}
    result[0][0], result[0][1] = r0, c0
    n, step, direction := 1, 1, 0
    for n < R * C {
        for i := 0; i < step; i++ {
            dx, dy := r0 + dr[direction], c0 + dc[direction];
            if inside(R,C, dx, dy) {
                result[n][0], result[n][1] = dx, dy
                n++;
            }
            r0, c0 = dx, dy
        }
        step += (direction % 2);
        direction = (direction + 1) % 4;
    }
    return result;
}
};
```
# [Problem 3 - Possible Bipartition](https://leetcode.com/problems/possible-bipartition/description/)

```go
func possibleBipartition(N int, dislikes [][]int) bool {
    edges := make([][]int, N + 1)
    for i := range edges {
        edges[i] = []int{}
    }
    for _, tmp:= range dislikes {
        u,v := tmp[0], tmp[1]
        edges[u] = append(edges[u], v)
        edges[v] = append(edges[v], u)
    }
    colors := make([]int, N + 1)
    // start color-ing
    for u := 1; u <= N; u++ {
        if colors[u] == 0 && !dfs(u, edges, colors, 1) {
            return false
        }
    }
    return true
}

func dfs(u int, edges [][]int, colors []int, color int) bool {
    if colors[u] != 0 { // colour-ed
        return colors[u] == color
    }
    colors[u] = color
    for _, v := range edges[u] {
        if !dfs(v, edges, colors, 3 - color) {
            return false
        }
    }
    return true
}
```