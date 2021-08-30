# 1. Reverse Bits

https://leetcode.com/problems/reverse-bits/

## 1.1. Summary

 - Make a loop base on the size of input:
	 - Pop the right bit of input num (get right bit + shift right)
	 - Push the bit to right of new result (shift left + update right bit)
 - Finally, new result will be reverse of input

```
┌─┬─┬─┬─┬─┬─┬─┬─┐       
│ │ │ │ │ │ │ │ │─────┐ 
└─┴─┴─┴─┴─┴─┴─┴─┘     ▼ 
                     ┌─┐
                     │█│
                     └─┘
                      │ 
        ┌─┬─┬─┬─┐     │ 
        │ │ │ │ │◀────┘ 
        └─┴─┴─┴─┘       
``` 

## 1.2. Code

```go
func reverseBits(num uint32) uint32 {
    var result uint32
    for i := 0; i < 32; i++ {
        result  = result << 1
        if num & 1 == 1{
            result++
        }
        num = num >> 1
    }
    return result
}
```

# 2. Number of 1 Bits

https://leetcode.com/problems/number-of-1-bits/

## 2.1. Summary

 - Make a loop base on the size of input:
    - Check and increase the counter if right bit is 1
    - Right shift

## 2.2. Code

```go
func hammingWeight(num uint32) int {
    var count int
    for i:=0; i<32; i++ {
        if num & 1 == 1 {
            count++
        }
        num = num >> 1
    }
    return count
}
```

# 3. Number of 1 Bits

https://leetcode.com/problems/number-of-1-bits/

## 3.1. Summary

 - Make a loop base on the size of input:
    - Check and increase the counter if right bit is 1
    - Right shift

## 3.2. Code

```go
func hammingWeight(num uint32) int {
    var count int
    for i:=0; i<32; i++ {
        if num & 1 == 1 {
            count++
        }
        num = num >> 1
    }
    return count
}
```

# 4. Container With Most Water

https://leetcode.com/problems/container-with-most-water/

## 4.1. Summary

 - Start to check from maximum width container
	 - Sequence, check left and right, move the smaller one to center if any higher verticle lines to continue to check max area

## 4.2. Code

```go
func maxArea(height []int) int {
    maxArea := 0
    i, j := 0, len(height) - 1
    
    for i < j {
        smaller := min(height[i], height[j])
        maxArea = max(maxArea, smaller * (j -i))
        for i < j {
            if height[i] < height[j] {
                i++
                if height[i] > height[i-1] {
                    break
                }
            } else {
                j--
                if height[j] > height[j+1] {
                    break
                }
            }
        }
    }
    return maxArea
}

func max(i1, i2 int) int {
    if i1 > i2 {
        return i1
    }
    return i2
}

func min(i1, i2 int) int {
     if i1 < i2 {
        return i1
    }
    return i2   
}
```
