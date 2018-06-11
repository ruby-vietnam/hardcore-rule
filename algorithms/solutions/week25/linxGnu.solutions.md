## Problem 1 - [Keyboard Row](https://leetcode.com/problems/keyboard-row/description/)

```go
var rows = []string{
            "qwertyuiopQWERTYUIOP",
            "asdfghjklASDFGHJKL",
            "zxcvbnmZXCVBNM",
}

var mark = make([]byte, 256)

func findWords(words []string) []string {
    for i, row := range rows {
        for _, b := range row {
            mark[b] = byte(i)
        }
    }
    
    n := 0
    for _, word := range words {
        if validWord(word) {
            words[n] = word
            n++
        }
    }
    
    return words[:n]
}

func validWord(word string) bool {
    ln := len(word)
    if ln == 0 {
        return true
    }
    
    r := mark[word[0]]
    for i := 1; i < ln; i++ {
        if r != mark[word[i]] {
            return false
        }
    }
    
    return true
}
```

## Problem 2 - [Friend Circles](https://leetcode.com/problems/friend-circles/description/)

```java
class Solution {
    private int[] root;
    
    public int findCircleNum(int[][] M) {
        if (M == null) {
            return 0;
        }
        
        root = new int[M.length];
        for (int i = 0; i < M.length; i++) root[i] = i;
        
        for (int i = 0; i < M.length; i++) 
          for (int j = i + 1; j < M.length; j++)
              if (M[i][j] == 1) union(i, j);
        
        int count = 0;
        for (int i = 0; i < root.length; i++)
            if (i == root[i]) count++;
        
        return count;
    }
    
    private int walkToRoot(int u) {
        while (u != root[u]) u = root[u];
        return u;
    }
    
    private void compress(int u0, int u) {
        int tmp;
        while (u != u0) {
            tmp = root[u];
            root[u] = u0;
            u = tmp;
        }
    }
    
    private void union(int u, int v) {
        int u0 = walkToRoot(u);
        int v0 = walkToRoot(v);
        
        compress(u0, u);
        compress(v0, v);
        
        if (u0 != v0) {
            root[v0] = u0;
            compress(u0, v);
        }
    }
}
```

## Problem 3 - [Pride](http://codeforces.com/contest/892/problem/C)

```go
package main

import (
	"bufio"
	"fmt"
	"os"
)

type pride struct {
	n   int
	arr []int
}

func (c *pride) readInput() {
	scanner := bufio.NewReader(os.Stdin) // read n and m
	fmt.Fscanf(scanner, "%d\n", &c.n)

	c.arr = make([]int, c.n)
	for i := range c.arr {
		fmt.Fscanf(scanner, "%d", &c.arr[i])
	}
}

func (c *pride) solve() int {
	n, arr := c.n, c.arr

	var gcdTmp, gcdAll int
	var i, j, min int

	// count number of 1
	count1 := 0
	for i = range arr {
		if arr[i] == 1 {
			count1++
		}
	}
	if count1 > 0 {
		return n - count1
	}

	// check all gcd
	for gcdAll, i = arr[0], 1; i < n; i++ {
		gcdAll = gcd(arr[i], gcdAll)
	}
	if gcdAll > 1 {
		return -1
	}

	// find continuous subarray has gcd = 1 with min length
	for min, i = n+1, 1; i < n; i++ {
		for gcdTmp, j = arr[i], i-1; j >= 0; j-- {
			if gcdTmp = gcd(arr[j], gcdTmp); gcdTmp == 1 {
				if i-j < min {
					min = i - j
				}
				break
			}
		}
	}

	return n - 1 + min
}

func gcd(a, b int) int {
	if a == 1 || b == 1 {
		return 1
	}

	if a < b {
		a, b = b, a
	}

	for b != 0 {
		a, b = b, a%b
	}

	return a
}

func main() {
	var p pride
	p.readInput()
	fmt.Print(p.solve())
}
```

## Problem 4 - [QMAX](http://vn.spoj.com/problems/QMAX/)

```go
package main

import (
	"bufio"
	"fmt"
	"os"
)

type qmax struct {
	n int
	m int
	q int

	f       []int
	variant []int
}

func (c *qmax) readInput() {
	scanner := bufio.NewReader(os.Stdin) // read n and m
	fmt.Fscanf(scanner, "%d %d\n", &c.n, &c.m)

	c.f, c.variant = make([]int, c.n<<2+4), make([]int, c.n<<2+4) // read each query

	var u, v, w int
	for i := 0; i < c.m; i++ {
		fmt.Fscanf(scanner, "%d %d %d\n", &u, &v, &w)
		c.Set(1, 1, c.n, u, v, w)
	}

	// read query
	fmt.Fscanf(scanner, "%d\n", &c.q)
	for i := 1; i <= c.q; i++ {
		if i == c.q {
			fmt.Fscanf(scanner, "%d %d", &u, &v)
			fmt.Print(c.Query(1, 1, c.n, u, v))
		} else {
			fmt.Fscanf(scanner, "%d %d\n", &u, &v)
			fmt.Println(c.Query(1, 1, c.n, u, v))
		}
	}
}

func (c *qmax) Set(node, u1, v1, u2, v2 int, w int) (max int) {
	if v1 < u2 || v2 < u1 {
		return c.f[node]
	}

	if u2 <= u1 && v1 <= v2 {
		c.f[node] += w
		c.variant[node] += w
		return c.f[node]
	}

	mid := (u1 + v1) >> 1

	tmp1, tmp2 := c.Set(node<<1, u1, mid, u2, v2, w), c.Set(node<<1+1, mid+1, v1, u2, v2, w)
	if tmp1 > tmp2 {
		c.f[node] = tmp1 + c.variant[node]
	} else {
		c.f[node] = tmp2 + c.variant[node]
	}

	return c.f[node]
}

func (c *qmax) Query(node, u1, v1, u2, v2 int) (max int) {
	if v1 < u2 || v2 < u1 {
		return 0
	}

	if u2 <= u1 && v1 <= v2 {
		return c.f[node]
	}

	mid := (u1 + v1) >> 1
	tmp1, tmp2 := c.Query(node<<1, u1, mid, u2, v2), c.Query(node<<1+1, mid+1, v1, u2, v2)

	if tmp1 < tmp2 {
		tmp1 = tmp2
	}

	return tmp1 + c.variant[node]
}

func main() {
	var solutioner qmax
	solutioner.readInput()
}
```
