## Problem 1 - [Sum of Square Numbers](https://leetcode.com/problems/sum-of-square-numbers/description/)

```go
func judgeSquareSum(c int) bool {
    left, right := 0, int(math.Sqrt(float64(c)))
    
    var tmp int
    for left <= right {
        if tmp = left * left + right * right; tmp == c {
            return true
        } else if tmp > c {
            right--
        } else {
            left++
        }
    }
    
    return false
}
```

## Problem 2 - [Largest Number](https://leetcode.com/problems/largest-number/description/)

```go
func largestNumber(nums []int) string {
    if nums == nil || len(nums) == 0 {
        return ""
    }
    
    n := len(nums)
    
    wrap := make([]*NumWrapper, n)
    var t uint64
    for i, v := range nums {
        wrap[i] = &NumWrapper{Val: v}
        
        if v == 0 {
            t = 10
        } else {
            for t = 1; v > 0; {
                t *= 10
                v /= 10
            }
        }
        wrap[i].P = t
    }
    
    sort.Slice(wrap, func(i, j int) bool {
        return uint64(wrap[i].Val) * wrap[j].P + uint64(wrap[j].Val) > uint64(wrap[j].Val) * wrap[i].P + uint64(wrap[i].Val)
    })
    
    if wrap[0].Val == 0 {
        return "0"
    }
    
    result := make([]string, n)
    for i, v := range wrap {
        result[i] = strconv.Itoa(v.Val)
    }
    
    return strings.Join(result, "")
}

type NumWrapper struct {
    Val int
    P uint64
}
```

## Problem 3 - [Coin Change](https://leetcode.com/problems/coin-change/description/)

```go
func coinChange(coins []int, amount int) int {
    if amount == 0 {
        return 0
    }
    
    sort.Slice(coins, func(i, j int) bool {
        return coins[i] < coins[j]
    })
    
    f := make([]int, amount + 1)
    f[0] = 0
    
    var v, min, got int
    for i := 1; i <= amount; i++ {
        min = -1
        for _, v = range coins {
            if v > i {
                break
            }
            
            if got = f[i - v]; got != -1 && (min == -1 || got + 1 < min) {
                min = got + 1
            }
        }
        f[i] = min
    }
    
    return f[amount]
}
```

## Problem 4 - [Split Array With Same Average](https://leetcode.com/problems/split-array-with-same-average/description/)

```go
func splitArraySameAverage(A []int) bool {
    return (&Arr{A: A}).Split()
}

type Arr struct {
    A []int
    NumB int
    NumC int
    
    Half int
    HalfSum int
    
    SecondHalf int
    SecondHalfSum int
    
    N int
}

func (a *Arr) Split() bool {
    n := len(a.A)
    if n <= 1 {
        return false
    }
    if n == 2 {
        return a.A[0] == a.A[1]
    }
    
    a.Half, a.N = n >> 1, n
    
    // total of first half
    sum := 0
    for i := 0; i < a.Half; i++ {
        sum += a.A[i]
    }
    a.HalfSum = sum
    
    // total of second half
    sum = 0
    for i := a.Half; i < n; i++ {
        sum += a.A[i]
    }
    a.SecondHalf, a.SecondHalfSum = n - a.Half, sum
    
    // processing
    for v := 1; v <= a.Half; v++ {
        a.NumB, a.NumC = v, n - v
        
        f := make(map[int]map[int]struct{})
        a.firstHalf(0, 0, 0, f)
        
        if a.secondHalf(a.Half, 0, 0, f) {
            return true
        }
    }
    
    return false
}

func (a *Arr) firstHalf(i, numB, sumB int, f map[int]map[int]struct{}) {
    if numB > a.NumB {
        return
    }
    
    if i >= a.Half {
        if a.Half - numB > a.NumC {
            return
        }
        
        // sumC = a.HalfSum - sumB
        variant := (a.HalfSum - sumB) * a.NumB - sumB * a.NumC
        if _, ok := f[variant]; !ok {
            f[variant] = make(map[int]struct{})
        }
        f[variant][numB] = struct{}{}
        
        return
    }
    
    a.firstHalf(i + 1, numB, sumB, f)
    a.firstHalf(i + 1, numB + 1, sumB + a.A[i], f)
}

func (a *Arr) secondHalf(i, numB, sumB int, f map[int]map[int]struct{}) bool {
    if numB > a.NumB {
        return false
    }
    
    if i >= a.N {
        if a.SecondHalf - numB > a.NumC {
            return false
        }
        
        // sumC = a.SecondHalfSum - sumB
        variant := sumB * a.NumC - (a.SecondHalfSum - sumB) * a.NumB
        if _, ok := f[variant]; ok {
            if _, ok = f[variant][a.NumB - numB]; ok {
                return true
            }
        }
        
        return false
    }
    
    return a.secondHalf(i + 1, numB, sumB, f) || a.secondHalf(i + 1, numB + 1, sumB + a.A[i], f)
}
```