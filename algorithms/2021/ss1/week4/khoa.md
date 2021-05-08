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

# 2. Knight Dialer

```swift
class Solution {
    private let mod: Int = Int(1e9 + 7)
    private let moves: [Int: [Int]] = [
        1: [6, 8],
        2: [7, 9],
        3: [4, 8],
        4: [3, 9, 0],
        5: [],
        6: [1, 7, 0],
        7: [2, 6],
        8: [1, 3],
        9: [2, 4],
        0: [4, 6]
    ]

    var dp = [[Int]]()

    func knightDialer(_ n: Int) -> Int {
        dp = Array(repeating: Array(repeating: 0, count: 10), count: n)
        dp[0] = [1, 1, 1, 1, 1, 1, 1, 1, 1, 1]

        var res = 0

        for start in moves.keys {
            res += dial(n - 1, start)
        }

        return res % mod
    }

    private func dial(_ n: Int, _ i: Int) -> Int {
        guard dp[n][i] <= 0 else { return dp[n][i] }

        for nextMove in moves[i]! {
            dp[n][i] += dial(n - 1, nextMove) % mod
        }

        return dp[n][i]
    }

}
```
```
Runtime: 1496 ms, faster than 60.00% of Swift online submissions for Knight Dialer.
Memory Usage: 17.5 MB, less than 60.00% of Swift online submissions for Knight Dialer.
```

# 3. N-Queens