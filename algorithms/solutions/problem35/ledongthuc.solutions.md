Problem 2:

https://leetcode.com/contest/weekly-contest-97/problems/spiral-matrix-iii/

```go
func spiralMatrixIII(R int, C int, r0 int, c0 int) [][]int {
    direction, r, mr, mc := 0, 0, max(r0+1, R-r0+1), max(c0+1, C-c0+1)
    m := max(mr, mc)
    result := make([][]int, 0)
    cs, ce, rs, re := -1, -1, -1, -1
    for r <= 2*m {
        switch direction {
        case 0:
            rs = -1
            cs = c0
            ce = c0 + r
            if ce >= C {
                ce = C - 1
            }
            if cs < 0 {
                cs = 0
            }
            if r0 >= 0 {
                for i := cs; i <= ce; i++ {
                    result = append(result, []int{r0, i})
                }
            }
            c0 = c0 + r + 1
        case 1:
            cs = -1
            rs = r0
            re = r0 + r
            if re >= R {
                re = R - 1
            }
            if rs < 0 {
                rs = 0
            }
            if c0 < C {
                for i := rs; i <= re; i++ {
                    result = append(result, []int{i, c0})
                }
            }
            r0 = r0 + r + 1
            r++
        case 2:
            rs = -1
            cs = c0
            ce = c0 - r
            if ce < 0 {
                ce = 0
            }
            if cs >= C {
                cs = C - 1
            }
            if r0 < R {
                for i := cs; i >= ce; i-- {
                    result = append(result, []int{r0, i})
                }
            }
            c0 = c0 - r - 1
        case 3:
            cs = -1
            rs = r0
            re = r0 - r
            if re < 0 {
                re = 0
            }
            if rs >= R {
                rs = R - 1
            }
            if c0 >= 0 {
                for i := rs; i >= re; i-- {
                    result = append(result, []int{i, c0})
                }
            }
            r0 = r0 - r - 1
            r++
        }

        direction = (direction + 1) % 4
    }
    return result
}

func max(a, b int) int {
    if a > b {
        return a
    }
    return b
}
```

Problem 3: 

https://leetcode.com/contest/weekly-contest-97/problems/possible-bipartition/

```go
func possibleBipartition(N int, dislikes [][]int) bool {
	adj := make([][]int, N+1)
	for _, dis := range dislikes {
		if len(adj[dis[0]]) <= 0 {
			adj[dis[0]] = make([]int, 0)
		}
		if len(adj[dis[1]]) <= 0 {
			adj[dis[1]] = make([]int, 0)
		}
		adj[dis[0]] = append(adj[dis[0]], dis[1])
		adj[dis[1]] = append(adj[dis[1]], dis[0])
	}
	list := make([]int, N+1)
	list[1] = 1
	for i := 1; i <= N; i++ {
		dfs(adj, i, list)
		if valid(adj, i, list) == false {
			return false
		}
	}
	return true
}
func valid(adj [][]int, v int, list []int) bool {
	for _, u := range adj[v] {
		if (list)[v] == (list)[u] {
			return false
		}
	}
	return true
}
func dfs(adj [][]int, v int, list []int) {
	for _, u := range adj[v] {
		if (list)[u] == 0 {
			(list)[u] = -(list)[v]
			dfs(adj, u, list)
		}
	}
}
```

Problem 4:

https://leetcode.com/contest/weekly-contest-97/problems/super-egg-drop/

```go
func superEggDrop(K int, N int) int {
    f := [][]int {
        makeRange(0, K+1),
        makeRange(1, K+1),
    }
    maxValue := 1
    for maxValue < N {
        ft := []int{0}
        for i := 0; i < K; i++ {
            var checking int
            if i == 0 {
                checking = len(f) 
            }  else {
                checking = f[len(f)-1][i] + 1 + f[len(f)-1][i+1]
            }
            maxValue = max(maxValue, checking)
            ft = append(ft, checking)
        }
        f = append(f, ft)
    }
    return len(f) - 1
}

func makeRange(number, length int) []int {
    l := make([]int, length)
    for i := range l {
        l[i] = number
    }
    return l
}

func max(num1, num2 int) int {
    if num1 > num2 {
        return num1
    }
    return num2
}

```
