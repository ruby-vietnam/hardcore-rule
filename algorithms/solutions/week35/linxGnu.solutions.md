## Problem 1 - [K-based Numbers](http://acm.timus.ru/problem.aspx?space=1&num=1009)

```rust
use std::io;

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

fn main() {
    let _n = parse_line!(usize);
    let _k = parse_line!(usize);
    let n = _n.0;
    let k = _k.0;

    let mut f = vec![vec![0 as u64; k]; 2];
    for base in 0..k {
        f[0][base] = 1
    }

    let mut current = 0;
    let mut next = 0;
    let mut startDigit = 0;
    for _ in 1..n {
        // reset first
        next = 1 - current;
        for lastDigit in 0..k {
            f[next][lastDigit] = 0
        }

        for lastDigit in 0..k {
            startDigit = match lastDigit {
                0 => 1,
                _ => 0,
            };
            for d in startDigit..k {
                f[next][lastDigit] += f[current][d]
            }
        }

        current = next;
    }

    let mut total = 0;
    for lastDigit in 1..k {
        total += f[current][lastDigit]
    }

    println!("{}", total);
}
```

## Problem 3 - [Possible Bipartition](https://leetcode.com/problems/possible-bipartition/description/)

```go
func possibleBipartition(N int, dislikes [][]int) bool {
    // store group
    group := make([]byte, N + 1)
    
    // temporary store bfs
    bfs := make([]int, N)
    
    // build edges
    edges := make([][]int, N + 1)
    for i := 1; i <= N; i++ {
        edges[i] = make([]int, 0, 10)
    }
    var u, v int
    for _, edge := range dislikes {
        u, v = edge[0], edge[1]
        edges[u] = append(edges[u], v)
        edges[v] = append(edges[v], u)
    }
    
    // try to partitioning
    for i := 1; i <= N; i++ {
        if group[i] == 0 && !partition(i, group, edges, bfs) { // 
            return false
        }
    }
    
    return true
}

func partition(u int, group []byte, edges [][]int, bfs []int) bool {
    start, end := 0, 0
    bfs[0] = u
    group[u] = 1
    
    e := end
    for start <= end {
        for i := start; i <= end; i++ {
            u = bfs[i]
            for _, v := range edges[u] {
                if group[u] == group[v] {
                    return false
                } else if group[v] == 0 {
                    e++
                    bfs[e], group[v] = v, 3 - group[u]
                }
            }
        }
        
        start, end = end + 1, e
    }
    
    return true
}
```