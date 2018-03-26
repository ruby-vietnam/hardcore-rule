## Problem 1 - [Maximum Product of Three Numbers](https://leetcode.com/problems/maximum-product-of-three-numbers/description/)

```python
class Solution(object):
    def maximumProduct(self, A):
        """
        :type A: List[int]
        :rtype: int
        """
        A.sort()
        return max(A[-3]*A[-2]*A[-1], A[0]*A[1]*A[-1])
```

## Problem 2 - [Divide Two Integers](https://leetcode.com/problems/divide-two-integers/description/)

Bài này từ lâu lâu rồi, mềnh làm theo cách của a @linxGnu ..

```go
func divide(dividend int, divisor int) int {

    var (
      pos     bool
      result  int
    )
    if dividend > (1<<31 - 1) || dividend < (-1 << 31) {
        return (1<<31 - 1)
    }
    
    if divisor > (1<<31 - 1) || divisor < (-1 << 31) {
        return (1<<31 - 1)
    }
    
    if divisor == 0 {
        return (1<<31 - 1)
    } else if dividend == 0 {
        return 0
    } 
    
    pos = (dividend > 0 && divisor > 0) || (dividend < 0 && divisor < 0)
    
    if dividend < 0 {
       dividend = -dividend 
    }
    if divisor < 0 {
        divisor = -divisor
    }
    
    var bitK uint
    for dividend >= divisor {
        for bitK = 0; (dividend >> bitK) >= divisor; bitK++ {
        }
        bitK--
        
        result = result | (1 << bitK)
        dividend -= divisor << bitK
    }
    
    if !pos {
        result = -result
    }
    
    
    if result > (1<<31 - 1) || result < (-1 << 31) {
        return (1<<31 - 1)
    }
    
    return result
}
```
