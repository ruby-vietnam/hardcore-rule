# Problem 1 - [Longest Harmonious Subsequence](https://leetcode.com/problems/longest-harmonious-subsequence/description/)

Using hashmap for counting number of element X. Find pair (X, X+1) with sum of number is max.

```go
func findLHS(nums []int) int {
    if nums == nil || len(nums) == 0 {
        return 0
    }
    
    m := make(map[int]int, len(nums))
    for i := range nums {
        if _, ok := m[nums[i]]; !ok {
            m[nums[i]] = 1
        } else {
            m[nums[i]]++
        }
    }
    
    max := 0
    for k, v1 := range m {
        if v2, ok := m[k+1]; ok && v1 + v2 > max {
            max = v1 + v2
        }
    }
    
    return max
}
```

# Problem 2 - [Merge Two Binary Trees](https://leetcode.com/problems/merge-two-binary-trees/description/)

It's super easy

```go
func mergeTrees(t1 *TreeNode, t2 *TreeNode) *TreeNode {
    if t1 == nil {
        return t2
    }
    
    if t2 == nil {
        return t1
    }
    
    t1.Val += t2.Val
    t1.Left = mergeTrees(t1.Left, t2.Left)
    t1.Right = mergeTrees(t1.Right, t2.Right)
    
    return t1
}
```

# Problem 3 - [Gray Code](https://leetcode.com/problems/gray-code/description/)

The idea is simple: find the way to find grayCode of N bits by N - 1 bits.
N bits should be in form of: 
- 0xx...xx
- 1xx...xx
In this form, G0 (0xx...xx) is grayCode of N - 1 bits and starts with bit 0, G1 (1xx..xx) is also grayCode of N - 1 bits and starts with bit 1.
So if we could solve grayCode of N - 1 bits and also merge G0 and G1, then we done.

My idea: reversing and building G1 from G0
Because:
- If G is a reverse of G0, G keeps grayCode feature of G0
- All elements of G starts with 0 (just like G0), then make them start with 1 won't change grayCode feature
- The last element X of G0 equals to first element Y of G (G is a reverse of G0), changing start bit of Y from 0 to 1 could make grayCode too because X and Y differ in start bit only. This makes possibility of appending G to G0 since we could append Y after X.

So: G1 = ChangeStartBitFrom0To1(Reverse(G0))

```go
func grayCode(n int) []int {
    if n == 0 {
        return []int{0}
    }
    
    if n == 1 {
        return []int{0, 1}
    }
    
    result := make([]int, 1 << uint(n))
    result[0], result[1], result[2], result[3] = 0, 1, 3, 2
    m := 4
    
    var end, j int
    for i, startBit := 2, 2; i < n; i++ {
        startBit <<= 1 // changing start bit by this one
        for end, j = m << 1, 0; j < m; j++ {
            result[end - j - 1] = startBit | result[j] // reverse and change start bit
        }
        m = end
    }
    
    return result
}
```

# Problem Bonus - [Number of Longest Increasing Subsequence](https://leetcode.com/problems/number-of-longest-increasing-subsequence/description/)

Using Fenwick tree (Binary index tree) for storing max length and counting numbers of sequence whose the same max length.

```go
func findNumberOfLIS(nums []int) int {
    if nums == nil || len(nums) == 0 {
        return 0
    }
    
    n, m := len(nums), discrete(nums)

    // fenwick tree (binary index tree)
    // f1: store max length
    // f2: number of max length
    f1, f2 := make([]int, n + 1), make([]int, n + 1)
    
    // calculation
    max, counter, index := 0, 0, 0
    
    var ln, count int
    for i := range nums {
        index, _ = m[nums[i]]
        
        ln, count = get(f1, f2, n, index - 1)
        if ln++; ln >= f1[index] {
            if count == 0 {
                count = 1
            }
            update(f1, f2, n, index, ln, count)
        }
        
        if ln > max {
           max, counter = ln, count
        } else if ln == max {
           counter += count
        }
    }
    
    return counter
}

// get on fenwick tree
func get(f1, f2 []int, n, ind int) (max, count int) {
    for max, count = 0, 0; ind > 0; ind -= ind & -ind {
        if f1[ind] > max {
            max, count = f1[ind], f2[ind]
        } else if f1[ind] == max {
            count += f2[ind]
        }
    }
    
    return
}

// update fenwick tree
func update(f1, f2 []int, n, ind int, value, count int) {
    for ; ind <= n; ind += ind & -ind {
        if f1[ind] < value {
            f1[ind], f2[ind] = value, count
        } else if f1[ind] == value {
            f2[ind] += count
        }
    }
    
    return
}

// discrete nums into new cordinates
func discrete(nums []int) (m map[int]int) {
    n := len(nums)
    if n == 0 {
        return
    }
    m = make(map[int]int, n)
    
    tmp := make([]int, n)
    for i := range nums {
        tmp[i] = nums[i]
    }
    sort.Slice(tmp, func(i, j int) bool {
        return tmp[i] < tmp[j]
    })
    
    old, currentIndex := tmp[0], 1
    m[old] = currentIndex
    for i := 1; i < n; i++ {
        if tmp[i] != old {
            old = tmp[i]
            
            currentIndex++
            m[old] = currentIndex
        }
    }
    
    return
}
```