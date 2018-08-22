## Problem 1 - [Leaf-Similar Trees](https://leetcode.com/problems/leaf-similar-trees/)

```go
/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func leafSimilar(root1 *TreeNode, root2 *TreeNode) bool {
    leaves1 := make([]int, 0, 512)
    leaves1 = getLeaves(root1, leaves1)
    
    leaves2 := make([]int, 0, 512)
    leaves2 = getLeaves(root2, leaves2)
    
    if len(leaves1) != len(leaves2) {
        return false
    }
    
    for i := range leaves1 {
        if leaves1[i] != leaves2[i] {
            return false
        }
    }
    
    return true
}

func getLeaves(root *TreeNode, leaves []int) []int {
    if root == nil {
        return leaves
    }
    
    if root.Left == nil && root.Right == nil {
        leaves = append(leaves, root.Val)
        return leaves
    }
    
    if root.Left != nil {
        leaves = getLeaves(root.Left, leaves)
    }
    
    if root.Right != nil {
        leaves = getLeaves(root.Right, leaves)
    }
    
    return leaves
}
```

## Problem 2 - [Most Frequent Subtree Sum](https://leetcode.com/problems/most-frequent-subtree-sum/description/)

```go
/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func findFrequentTreeSum(root *TreeNode) []int {
    s := make(map[int]int)
    
    walk(root, s)
    
    isSet, max, num := false, 0, 0
    for _, v := range s {
        if isSet && max <= v {
           if max == v {
                num++
           }
           max = v
        } else if !isSet {
           max, isSet, num = v, true, 1
        }
    }
    
    vec := make([]int, 0, num)
    for k, v := range s {
        if v == max {
            vec = append(vec, k)
        }
    }
    
    return vec
}

func walk(root *TreeNode, sum map[int]int) int {
    if root == nil {
        return 0
    }
    
    tmp := walk(root.Left, sum) + walk(root.Right, sum) + root.Val
    sum[tmp]++
    return tmp
}
```

## Problem 3 - [Elevator](https://codeforces.com/problemset/problem/117/A)

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

fn time_arrive(m: i32, target: i32, from_time: i32) -> i32 {
    let step = from_time % (2 * m - 2);
    let current_floor = if step <= m - 1 {
        step + 1
    } else {
        2 * m - 1 - step
    };

    if current_floor == target {
        return from_time;
    }

    if step <= m - 1 {
        // is upping
        if current_floor < target {
            from_time + target - current_floor
        } else {
            from_time + (m - current_floor) + (m - target)
        }
    } else {
        if current_floor > target {
            from_time + (current_floor - target)
        } else {
            from_time + (current_floor - 1) + (target - 1)
        }
    }
}

fn read_input_and_solve() {
    let (n, m) = parse_line!(i32, i32);
    let mut tmp: i32;
    for _ in 0..n {
        let (s, f, t) = parse_line!(i32, i32, i32);
        if s == f {
            println!("{}", t);
            continue;
        }

        tmp = time_arrive(m, s, t);
        println!("{}", time_arrive(m, f, tmp));
    }
}

fn main() {
    read_input_and_solve();
}
```