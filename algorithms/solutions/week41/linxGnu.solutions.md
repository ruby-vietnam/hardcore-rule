## Problem 4 - [Largest Rectangle in Histogram](https://leetcode.com/problems/largest-rectangle-in-histogram/description/)

```go
func largestRectangleArea(heights []int) int {
    if heights == nil || len(heights) == 0 {
        return 0
    }
    
    n := len(heights)
    
    stack, stackLen := make([]int, n+1), 0
    
    j, max, tmp, x := 0, 0, 0, 0
    for i:=0;i<=n;i++ {
        if i == n {
            x = 0
        } else {
            x = heights[i]
        }

        for stackLen > 0 && heights[stack[stackLen-1]] >= x {
            tmp = heights[stack[stackLen-1]]
            stackLen--
                
            if stackLen > 0 {
                j = stack[stackLen-1]
            } else {
                j = -1
            }
                    
            if tmp = tmp * (i-j-1); tmp > max {
                max = tmp
            }
        }
        stack[stackLen] = i
        stackLen++
    }
    
    return max
}
```
