## Problem 1 - [Two Substrings](http://codeforces.com/contest/550/problem/A)

```go
package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	inp := bufio.NewReader(os.Stdin)

	// read string
	var s string
	fmt.Fscanf(inp, "%s", &s)

	// solve
	minA, maxA := -1, -1
	minB, maxB := -1, -1
	for i := 0; i < len(s)-1; i++ {
		if s[i] == 'A' && s[i+1] == 'B' {
			if minA == -1 {
				minA = i
			}
			maxA = i
		}
		if s[i] == 'B' && s[i+1] == 'A' {
			if minB == -1 {
				minB = i
			}
			maxB = i
		}
	}

	// write output
	if minA == -1 || minB == -1 {
		fmt.Println("NO")
	} else if diffAbs(minA, maxB) > 1 || diffAbs(minB, maxA) > 1 {
		fmt.Println("YES")
	} else {
		fmt.Println("NO")
	}
}

func diffAbs(a, b int) int {
	if a > b {
		return a - b
	}
	return b - a
}
```

## Problem 2 - [Binary Tree Maximum Path Sum](https://leetcode.com/problems/binary-tree-maximum-path-sum/description/)

```go
func maxPathSum(root *TreeNode) int {
    v1, v2 := dynamicPrograming(root)
    if v1 > v2 {
        return v1
    }
    
    return v2
}

func dynamicPrograming(root *TreeNode) (v1 int, v2 int) {
    if root == nil {
        return 0, 0
    }
    
    if root.Left == nil && root.Right == nil {
        return root.Val, root.Val
    }
    
    if root.Right == nil {
        root.Left, root.Right = root.Right, root.Left
    }
    
    if root.Left == nil {
        r1, r2 := dynamicPrograming(root.Right)
        
        v2 = root.Val
        if v2 < r1 {
            v2 = r1
        }
        if v2 < r2 {
            v2 = r2
        }
        if v2 < r1 + root.Val {
            v2 = r1 + root.Val            
        }
        
        v1 = root.Val
        if v1 < root.Val + r1 {
            v1 = root.Val + r1            
        }
        
        return
    }
    
    l1, l2 := dynamicPrograming(root.Left)
    r1, r2 := dynamicPrograming(root.Right)
    
    v2 = root.Val
    
    if v2 < l1 {
        v2 = l1
    }
    if v2 < r1 {
        v2 = r1
    }
    if v2 < l2 {
        v2 = l2
    }
    if v2 < r2 {
        v2 = r2
    }
    
    if v2 < l1 + r1 + root.Val {
        v2 = l1 + r1 + root.Val
    }
    
    v1 = root.Val
    if v1 < root.Val + l1 {
        v1 = root.Val + l1
    }
    if v1 < root.Val + r1 {
        v1 = root.Val + r1
    }
    
    return
}
```

## Problem 3 - [Kefa and Dishes](http://codeforces.com/contest/580/problem/D)

```rust
use std::boxed::Box;
use std::io;

const LIMIT_N: usize = 18;

// This macro I found at: https://users.rust-lang.org/t/reading-and-parsing-a-line-from-stdin-containing-3-integers/7265/2
macro_rules! parse_line {
    ($($t: ty),+) => ({
        let mut a_str = String::new();
        io::stdin().read_line(&mut a_str).expect("read error");
        let mut a_iter = a_str.split_whitespace();
        (
            $(
            a_iter.next().unwrap().parse::<$t>().expect("parse error"),
            )+
        )
    })
}

fn read_integers<T>() -> Box<Vec<T>>
where
    T: std::str::FromStr,
    <T as std::str::FromStr>::Err: std::fmt::Debug,
{
    let mut input = String::new();
    io::stdin().read_line(&mut input).expect("Expect integers");
    let v = input
        .trim()
        .split(' ')
        .map(|a| a.parse::<T>())
        .map(|a| a.expect("Expect integers"))
        .collect::<Vec<T>>();
    Box::from(v)
}

fn read_input() -> (usize, u32, Box<Vec<u64>>, [[u64; LIMIT_N]; LIMIT_N]) {
    // first line
    let (n, m, k) = parse_line!(usize, u32, u16);

    // second line
    let dishes = read_integers::<u64>();

    // edges
    let mut rules = [[0 as u64; LIMIT_N]; LIMIT_N];
    for _ in 0..k {
        let (u, v, w) = parse_line!(usize, usize, u64);
        rules[u - 1][v - 1] = w;
    }

    (n, m, dishes, rules)
}

fn solve(n: usize, m: u32, dishes: Box<Vec<u64>>, rules: [[u64; LIMIT_N]; LIMIT_N]) -> u64 {
    let limit = 1 << n;

    let mut f = vec![vec![0 as u64; LIMIT_N]; limit];
    let mut new_state: usize;
    let mut current_state_val: u64;
    let mut max: u64 = 0;

    for i in 0..n {
        f[1 << i][i] = dishes[i];
        if max < dishes[i] {
            max = dishes[i];
        }
    }

    for state in 1..limit {
        if usize::count_ones(state) < m {
            for i in 0..n {
                if (state >> i) & 1 == 1 {
                    current_state_val = f[state][i];
                    for j in 0..n {
                        if (state >> j) & 1 == 0 {
                            new_state = state | (1 << j);

                            if f[new_state][j] < current_state_val + dishes[j] + rules[i][j] {
                                f[new_state][j] = current_state_val + dishes[j] + rules[i][j];
                                if max < f[new_state][j] {
                                    max = f[new_state][j];
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    max
}

fn main() {
    let (n, m, dishes, rules) = read_input();
    let result = solve(n, m, dishes, rules);
    print!("{}", result);
}
```

## Problem 4 - [Shortest Subarray with Sum at Least K](https://leetcode.com/problems/shortest-subarray-with-sum-at-least-k/description/)

* Solution 1: Fenwick tree

```go
func shortestSubarray(A []int, K int) int {
    f, n := make([]int64, len(A) << 1, len(A) << 1 + 1), 0
    
    var i, ivtIndex, min int
    var sum int64
    
    for i = range A {
        if A[i] >= K {
            return 1
        }
        
        sum += int64(A[i])
        f[n] = sum
        f[n+1] = sum - int64(K)
        n += 2
    }
    
    // make inverted index for binary index tree
    invertedIndex, n := makeInvertedIndex(f)
    
    // reset f
    f = f[:n+1]
    for i = 0; i <= n; i++ {
        f[i] = -1
    }
    
    // solution
    sum = 0
    for i = range A {
        sum += int64(A[i])
        
        // find max from [1; index]
        ivtIndex = invertedIndex[sum - int64(K)]
        if j := getMaxIndex(f, ivtIndex); j != -1 {
            if min == 0 || i - int(j) < min {
                min = i - int(j)
            }
        }
        
        if sum >= int64(K) && min == 0 {
            min = i + 1
        }
        
        // update
        ivtIndex = invertedIndex[sum]
        f[ivtIndex] = int64(i)
        updateMaxIndex(f, ivtIndex, n)
    }
    
    // got min range
    if min == 0 {
        return -1
    }
    
    return min
}

func getMaxIndex(f []int64, index int) (max int64) {
    max = -1
    for index > 0 {
        if max == -1 || max < f[index] {
            max = f[index]
        }
        index -= index & (-index)
    }
    return
}

func updateMaxIndex(f []int64, index, limit int) {
    tmp := f[index]
    for index <= limit {
        if tmp >= f[index] {
            f[index] = tmp
        }
        index += index & (-index)
    }
}

func makeInvertedIndex(a []int64) (m map[int64]int, n int) {
    sort.Slice(a, func(i, j int) bool {
        return a[i] < a[j]
    })
    
    n = 1 
    for i := 1; i < len(a); i++ {
        if a[i] != a[n-1] {
            a[n] = a[i]
            n++
        }
    }
    a = a[:n]
    
    m = make(map[int64]int, n)
    for i := range a {
        m[a[i]] = i + 1
    }
    
    return
}
```

* Solution 2: Stack

```go
func shortestSubarray(A []int, K int) int {
    stack, nStack := make([]int, len(A)), 0
    idx := make([]int, len(A))
    
    var sum int
    min := -1
    
    cur := len(A)
    for i := range A {
        sum += A[i]
                      
        if sum >= K && min == -1 {
            min = i + 1
        }
        
        for nStack > 0 && stack[nStack - 1] >= sum {
            nStack--
        }
        stack[nStack] = sum
        idx[nStack] = i
        nStack++
        
        if cur >= nStack {
            cur = nStack - 1
        } else if cur < 0 {
            cur = 0
        }
        
        for cur >= 0 && sum - stack[cur] < K {
            cur--
        }
        if cur < 0 {
            continue
        }
        
        for cur + 1 < nStack && sum - stack[cur + 1] >= K {
            cur++
        }
        if min == -1 || min > i - idx[cur] {
           min = i - idx[cur]
        }
    }
    
    return min
}
```