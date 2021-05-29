# Easy: Add Binary

```swift
class Solution {
    func addBinary(_ a: String, _ b: String) -> String {
        let chars: [Int: Character] = [0: "0", 1: "1"]
        let ints: [Character: Int] = ["0": 0, "1": 1]
        let aArray = Array(Array(a)), bArray = Array(Array(b))
        var resultArray = [Character]()
        var aIndex = aArray.count - 1, bIndex = bArray.count - 1
        var carry = 0
        while aIndex >= 0 || bIndex >= 0 {
            var sum = carry
            if aIndex >= 0 {
                sum += ints[aArray[aIndex]]!
                aIndex -= 1
            }
            if bIndex >= 0 {
                sum += ints[bArray[bIndex]]!
                bIndex -= 1
            }
            resultArray.append(chars[sum % 2]!)
            carry = sum / 2
        }
        if carry == 1 { resultArray.append("1") }

        return String(resultArray.reversed())
    }
}
```
```
Runtime: 4 ms, faster than 99.70% of Swift online submissions for Add Binary.
Memory Usage: 14.2 MB, less than 86.36% of Swift online submissions for Add Binary.
```

# Medium: Multiply Strings

```swift
class Solution {
    func multiply(_ num1: String, _ num2: String) -> String {

        var smallString = num1, largeString = num2
        if smallString.count > largeString.count { smallString = num2; largeString = num1 }

        var small = smallString.compactMap { Int(String($0)) }
        var large = largeString.compactMap { Int(String($0)) }

        guard small.count > 0, large.count > 0 else { return "0" }

        var length = small.count + large.count + 1
        var workout = [[Int]](repeating: [Int](repeating: 0, count: length), count: small.count)

        var i = small.count - 1
        var shift = 0

        while i >= 0 {
            var val1 = small[i]
            var carry = 0
            var j = large.count - 1
            var paste = length - (1 + shift)
            while j >= 0 {
                var val2 = large[j]
                var num = val1 * val2 + carry
                workout[i][paste] = num % 10
                carry = num / 10
                j -= 1
                paste -= 1
            }
            while carry > 0 {
                workout[i][paste] = carry % 10
                carry /= 10
                paste -= 1
            }
            shift += 1
            i -= 1
        }

        var j = length - 1


        var res = [Int](repeating: 0, count: length)

        var carry: Int = 0
        while j >= 0 {
            var sum: Int = carry
            i = 0
            while i < small.count {
                sum += workout[i][j]
                i += 1
            }
            res[j] = sum % 10
            carry = sum / 10
            j -= 1
        }

        var zeroIndex = 0
        while zeroIndex < length && res[zeroIndex] == 0 { zeroIndex += 1 }
        if zeroIndex == length { zeroIndex = length - 1 }
        res = Array(res[zeroIndex...])

        return res.map { String($0) }.joined()
    }
}
```
```
Runtime: 32 ms, faster than 97.18% of Swift online submissions for Multiply Strings.
Memory Usage: 15.2 MB, less than 18.31% of Swift online submissions for Multiply Strings.
```

# Hard: Minimum Window Substring

```swift
class Solution {
    func minWindow(_ s: String, _ pattern: String) -> String {
        let s = Array(s)
        let pattern = Array(pattern)

        var start = 0
        var startIdx = 0
        var matches = 0
        var minLength = s.count + 1
        var dict = [Character: Int]()

        for str in pattern {
            dict[str, default: 0] += 1
        }

        for end in 0 ..< s.count {
            let endChar = s[end]
            if let _ = dict[endChar] {
                dict[endChar, default: 0] -= 1

                if dict[endChar, default: 0] >= 0 {
                    matches += 1
                }
            }

            while matches == pattern.count {
                if minLength > end - start + 1 {
                    minLength = end - start + 1
                    startIdx = start
                }
                let startChar = s[start]
                start += 1
                if let _ = dict[startChar] {
                    if dict[startChar, default: 0] == 0 {
                        matches -= 1
                    }
                    dict[startChar, default: 0] += 1
                }
            }
        }
        if minLength > s.count {
          return ""
        } else {
          let res = s[startIdx ... startIdx + minLength - 1]
          return String(res)
        }
    }
}
```
```
Runtime: 80 ms, faster than 83.93% of Swift online submissions for Minimum Window Substring.
Memory Usage: 16.1 MB, less than 67.86% of Swift online submissions for Minimum Window Substring.
```