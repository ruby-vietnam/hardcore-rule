## Problem 1 - [Maximum Product of Three Numbers](https://leetcode.com/problems/maximum-product-of-three-numbers/description/)

- If N = number of elements in array is small enough, just brute force
- If not, we need to find 3 largest and 3 (or 2) smallest numbers, and brute force around them

```go
func maximumProduct(nums []int) (max int) {
    n := len(nums)    
    if n <= 6 {
        max = nums[0] * nums[1] * nums[2]
        
        var i, j, k, p int
        for i = 0; i < n; i++ {
            for j = i + 1; j < n ;j++ {
                for k = j+1; k < n; k++ {
                    if p = nums[i] * nums[j] * nums[k]; p > max {
                        max = p
                    }
                }
            }
        }
        
        return
    }
    
    minArr, maxArr := []int{nums[0], nums[1], nums[2]}, []int{nums[0], nums[1], nums[2]}
    var tmp int
    for i := 3; i < n; i++ {
        tmp = 0
        if minArr[1] > minArr[tmp] {
            tmp = 1
        }
        if minArr[2] > minArr[tmp] {
            tmp = 2
        }
        if minArr[tmp] > nums[i] {
            minArr[tmp] = nums[i]
        }
        
        tmp = 0
        if maxArr[1] < maxArr[tmp] {
            tmp = 1
        }
        if maxArr[2] < maxArr[tmp] {
            tmp = 2
        }
        if maxArr[tmp] < nums[i] {
            maxArr[tmp] = nums[i]
        }
    }
    
    return maximumProduct([]int{minArr[0], minArr[1], minArr[2], maxArr[0], maxArr[1], maxArr[2]})
}
```

## Problem 2 - [Divide Two Integers](https://leetcode.com/problems/divide-two-integers/description/)

We did it before. In this writeup, I use shiftbit as replacement for dividing operator.

```go
func divide(dividend int, divisor int) int {
    if dividend > math.MaxInt32 || dividend < math.MinInt32 {
        return math.MaxInt32
    }
    
    if divisor > math.MaxInt32 || divisor < math.MinInt32 {
        return math.MaxInt32
    }
    
    if dividend == 0 {
        return 0
    } 
    
    // mark result is positive or negative interger
    positive := (dividend > 0 && divisor > 0) || (dividend < 0 && divisor < 0)
    
    // make it abs
    if dividend < 0 {
       dividend = -dividend 
    }
    if divisor < 0 {
        divisor = -divisor
    }
    
    // perform
    result := 0
    
    var bitK uint
    for dividend >= divisor {
        for bitK = 0; (dividend >> bitK) >= divisor; bitK++ {
        }
        bitK--
        
        result = result | (1 << bitK)
        dividend -= divisor << bitK
    }
    
    if !positive {
        result = -result
    }
    
    
    if result > math.MaxInt32 || result < math.MinInt32 {
        return math.MaxInt32
    }
    
    return result
}
```

## Problem 3 - [Valid Number](https://leetcode.com/problems/valid-number/description/)

To validate number, we need to check through several steps:
- Trim Space (trim trailing spaces from prefix and suffix)
- Check if string contains 'e', if yes, then before 'e' and after 'e' must be a valid number. After 'e' must be an integer.
- If not contains 'e', then check whole string for valid number with floating point or not.

```go
func isNumber(s string) bool {
    // Trim spaces first
    s = strings.TrimSpace(s)
    
    // get index of 'e'
    eIndex, valid := getEindex(s)
    if !valid {
        return false
    }
    
    if eIndex > -1 {
        return isValidNumber(s[0:eIndex], true) && isValidNumber(s[eIndex + 1:], false)
    }
    
    return isValidNumber(s, true)
}

func getEindex(s string) (eIndex int, isValid bool) {
    eIndex = -1
    for i := range s {
        if (s[i] >= '0' && s[i] <= '9') || s[i] == '+' || s[i] == '-' || s[i] == '.' {
            continue
        }
        
        if s[i] == 'e' {
            if eIndex == -1 {
                eIndex = i
                continue
            }
        }
        
        isValid = false
        return
    }
    
    isValid = true
    return
}

func isValidNumber(s string, shouldContainDot bool) (valid bool) {
    countDot := 0
    for i := range s {
        if s[i] == '.' {
            countDot++
        }
    }
    
    if (!shouldContainDot && countDot > 0) || (shouldContainDot && countDot > 1) {
        return false
    }
    
    sign, numbers := -1, 0
    for i := range s {
        if s[i] == '+' || s[i] == '-' {
            if sign = i; sign != 0 {
                return false
            }
        } else if s[i] >= '0' && s[i] <= '9' {
            numbers++
        }
    }
    
    return numbers > 0
}
```

## Problem Bonus - [Cherry Pickup](https://leetcode.com/problems/cherry-pickup/description/)

Dynamic programing over `diagonals`

```go
func cherryPickup(grid [][]int) int {
    n := len(grid)
    if grid[0][0] < 0 {
        grid[0][0] = -grid[0][0]
    }
    
    //
    f := make([][][]int, 2)
    f[0], f[1] = make([][]int, n), make([][]int, n)
    for i := range f[0] {
        f[0][i], f[1][i] = make([]int, n), make([]int, n)
    }
    
    // 
    o1, o2 := f[0], f[1]
    o1[0][0] = grid[0][0]
    oldLen, newLen := 1, 0
    
    //
    directions := make([][][]int, 2)
    directions[0], directions[1] = [][]int{[]int{-1, 0}, []int{-1, -1}, []int{0, 0}, []int{0, -1}}, [][]int{[]int{1, 0}, []int{1, 1}, []int{0, 0}, []int{0, 1}}
    
    //
    var c1, c2, added, i1, j1, max int
    var direction [][]int
    
    for diagonal, limit := 1, (n << 1) - 1; diagonal < limit; diagonal++ {
        if diagonal < n {
            newLen, direction = oldLen + 1, directions[0]
        } else {
            newLen, direction = oldLen - 1, directions[1]
        }
        
        for i := 0; i < newLen; i++ {
            c1 = getCherry(grid, i, diagonal, n)
            for j := i; j < newLen; j++ {
                if c2 = getCherry(grid, j, diagonal, n); c1 == -1 || c2 == -1 {
                    o2[i][j] = -1
                    continue
                }
                    
                if i == j {
                    added = c1
                } else {
                    added = c1 + c2
                }
                
                max = -1
                for _, dir := range direction {
                    i1, j1 = i + dir[0], j + dir[1]
                    if i1 < 0 || i1 >= oldLen || j1 < 0 || j1 >= oldLen || o1[i1][j1] <= max || i1 > j1 {
                        continue
                    }
                    
                    max = o1[i1][j1]
                }
                
                if max < 0 {
                    o2[i][j] = -1
                } else {
                    o2[i][j] = max + added
                }
            }
        }
        
        oldLen = newLen
        o1, o2 = o2, o1
    }
    
    if o1[0][0] >= 0 {
        return o1[0][0]
    }
    
    return 0
}

func getCherry(grid [][]int, i, diagonal, n int) int {
    if diagonal < n {
        return grid[diagonal - i][i]
    }
    
    return grid[n - 1 - i][diagonal - n + 1 + i]
}
```