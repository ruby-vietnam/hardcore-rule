Problem 1:

https://leetcode.com/problems/maximum-product-of-three-numbers

```go
func maximumProduct(nums []int) int {
    arrLength := len(nums)
    if arrLength == 3 {
        return nums[0] * nums[1] * nums[2]
    }
    
    sort.Ints(nums)
    if nums[1] < 0  && (-nums[1]) * (-nums[0]) > nums[arrLength-2] * nums[arrLength-3] {
        return nums[arrLength-1] * nums[0] * nums[1]
    }
    
    return nums[arrLength-1] * nums[arrLength-2] * nums[arrLength-3]
}
```

Problem 2:

https://leetcode.com/problems/divide-two-integers

STUPID solution:

![](https://www.mathsisfun.com/numbers/images/apples-15.svg)

```go
func divide(dividend int, divisor int) int {
    if dividend == math.MinInt32 && divisor == -1 {
        return math.MaxInt32
    }
    if dividend == divisor {
        return 1
    }
    if divisor == 0 {
        return math.MaxInt32
    }
    if divisor == 1  {
        return dividend
    }
    if divisor == -1 {
        return -dividend
    }
    
    absDividend := Abs(dividend)
    absDivisor := Abs(divisor)
    if absDividend < absDivisor {
        return 0
    }
    
    counting := 0;
    result := 0
    for (counting + absDivisor)  <= absDividend{
        counting += absDivisor
        result++
    }
    
    if (dividend >= 0 && divisor >= 0) || 
    (dividend < 0 && divisor < 0) {
        return result
     } else {
         return -(result)
     }
}

func Abs(x int) int {
    if x >= 0 {
        return x
    } else {
        return -x
    }
}
```
