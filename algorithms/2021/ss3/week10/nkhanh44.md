# 1. Reverse Bits

https://leetcode.com/problems/reverse-bits/

## 1.1. Summary

 - Loop through 32 bits
 - Use method (2^n)*i to get result
  - Shift right and compare bit to get i
  - n is bit's order

## 1.2. Code

```swift

class Solution {
    
    func reverseBits(_ n: Int) -> Int {
        var result = 0
        var count = 0
        
        while count < 32 {
            result += Int(pow(Float(2), Float(31 - count))) * ((n >> count) & 1)
            count += 1
        }
        return result
    }
}
```

# 2. Number of 1 Bits

https://leetcode.com/problems/number-of-1-bits/

## 2.1. Summary

 - Loop through 32 bits with right shift
 - Compare each bit & 1 to get result

## 2.2. Code

```swift
class Solution {
    func hammingWeight(_ n: Int) -> Int {
        var count = 0
        var total = 0
        while count < 32 {
            total += ((n >> count) & 1) == 1 ? 1 : 0
            count += 1
        }
        return total
    }
}
```
