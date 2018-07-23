## Problem 2

```go
/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func maxPathSum(root *TreeNode) int {
    res := root.Val
    val := traverse(root, &res)
    return max([]int{res, val})
}

func max(a []int) int {
    m := a[0]
    for _, v := range a {
        if v > m {
            m = v
        }
    }
    return m
}

func traverse(root *TreeNode, res *int) int {
    if root == nil {
        return 0
    }
    left := traverse(root.Left, res)
    right := traverse(root.Right, res)
    *res = max([]int{*res, root.Val + left + right, root.Val + left, root.Val + right})
    return max([]int{root.Val, root.Val + left, root.Val + right})
}
```

### Problem 3

```go
package main

/*
Due to a maximum of 18 dishes, a number s (s <= 2^18) can be used to uniquely identify a state.

For a state s, enumerate two positions i and j:
- i is from the selected dishes
- j is from the unselected dishes

The next state ss is: the maximum value of all the states of j after eating i.

ss = s | 2^j

DP forumla:
dp[ss][j] = max(dp[ss][j], dp[s][i] + a[j] + c[i][j])

The answer is the maximum of all states in which the number of choices reaches m.
*/

// Count number of dishes from a state.
func count(state int) int {
	num := 0
	for a > 0 {
		if state&1 != 0 {
			num++
		}
		state = state / 2
	}
	return num
}

// Return true if the state contains the i-th dish.
func contains(state int, i int) bool {
  return state&pow[i] != 0
}

func solve(n int, m int, k int, a []int, c [][]int) int {
	pow := make([]int, n+1)
	dp := make([][]int, n+1)
	pow[0] = 1
	for i := 1; i <= n; i++ {
		pow[i] = pow[i-1] * 2
	}

	for i := 0; i < n; i++ {
		dp[pow[i]][i] = a[i]
	}

	for state := 0; state < pow[n]; state++ {
		for i := 0; i < n; i++ {
			if contains(state, i) {
				for j := 0; j < n; j++ {
					if !contains(state, j) {
						val := dp[state][i] + c[i][j] + a[i]
						nextState := state | pow[j]
						if val > dp[nextState][j] {
							dp[nextState][j] = val
						}

					}
				}
			}
		}
	}
    
	ret := 0
	for state := 0; state < pow[n]; state++ {
		if count(state) == m {
			for i := 0; i < n; i++ {
				val := dp[state][i]
				if val > ret {
					ret = val
				}

			}
		}
	}
	return ret
}

// Too lazy to write input/output
func main() {}
```
