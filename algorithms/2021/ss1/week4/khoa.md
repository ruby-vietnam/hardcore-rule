# 1. Determine Color of a Chessboard Square

The even or odd of a letter or number in the coordinate is represented by 0(even) or 1(odd).
- For a letter, we can calculate using the Unicode % 2("a" = 97, "b" = 98...)
- For a number, just % 2
- If both chars are the same(even/even or odd/odd), return false.
- Otherwise, if both chars are different(even/odd or odd/even), return true.

Analysis:
- Time: O(1), since `coordinates` always has 2 character.
- Space: O(1)

```swift
class Solution {
    func squareIsWhite(_ coordinates: String) -> Bool {
        var num: UInt32 = 0
        coordinates.forEach {
            if let i = UInt32(String($0)) {
                num = (num & i) ^ (~num & ~i)
            } else {
                num = $0.unicodeScalars.first!.value
            }
        }
        return num % 2 == 0
    }
}
```

```
Runtime: 0 ms, faster than 100.00% of Swift online submissions for Determine Color of a Chessboard Square.
Memory Usage: 14.4 MB, less than 42.05% of Swift online submissions for Determine Color of a Chessboard Square.
```

# 2.

# 3.