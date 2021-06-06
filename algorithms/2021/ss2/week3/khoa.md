# Easy: Min Stack

```swift
class MinStack {

    private var auxiliaryArray = [Int]()
    private var minStack = [Int]()

    func push(_ val: Int) {
        minStack.append(val)
        let minValue = min(auxiliaryArray.last ?? Int.max, val)
        auxiliaryArray.append(minValue)
    }

    func pop() {
        _ = minStack.popLast()
        _ = auxiliaryArray.popLast()
    }

    func top() -> Int {
        return minStack.last ?? 0
    }

    func getMin() -> Int {
        return auxiliaryArray.last ?? 0
    }
}
```
```
Runtime: 84 ms, faster than 26.15% of Swift online submissions for Min Stack.
Memory Usage: 15.3 MB, less than 77.69% of Swift online submissions for Min Stack.
```

# Medium: Number of islands

```swift
class Solution {
    func numIslands(_ grid: [[Character]]) -> Int {

        guard grid.count > 0 else { return 0 }
        guard grid[0].count > 0 else { return 0 }

        var matrix = grid
        var numberOfIslands = 0

        for i in 0..<matrix.count {
            for j in 0..<matrix[0].count {
                if matrix[i][j] == "1" {
                    numberOfIslands += 1
                    changeElement(&matrix, i, j)
                }
            }
        }
        return numberOfIslands
    }

    private func changeElement(_ matrix: inout [[Character]], _ i: Int, _ j: Int) {
        guard i >= 0, i < matrix.count, j >= 0, j < matrix[0].count, matrix[i][j] == "1" else { return }
        matrix[i][j] = "0"
        changeElement(&matrix, i + 1, j)
        changeElement(&matrix, i - 1, j)
        changeElement(&matrix, i, j + 1)
        changeElement(&matrix, i, j - 1)
    }
}
```
```
Runtime: 244 ms, faster than 5.12% of Swift online submissions for Number of Islands.
Memory Usage: 15.3 MB, less than 89.76% of Swift online submissions for Number of Islands.
```