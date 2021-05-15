# Easy

# Medium
```swift
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     public var val: Int
 *     public var left: TreeNode?
 *     public var right: TreeNode?
 *     public init() { self.val = 0; self.left = nil; self.right = nil; }
 *     public init(_ val: Int) { self.val = val; self.left = nil; self.right = nil; }
 *     public init(_ val: Int, _ left: TreeNode?, _ right: TreeNode?) {
 *         self.val = val
 *         self.left = left
 *         self.right = right
 *     }
 * }
 */
class Solution {
    func pathSum(_ root: TreeNode?, _ sum: Int) -> Int {
        var currentPath = [Int]()
        return findPathsRecursive(root, sum, &currentPath)
    }

    private func findPathsRecursive(_ currentNode: TreeNode?, _ sum: Int, _ currentPath: inout [Int]) -> Int {
        guard let currentNode = currentNode else { return 0 }

        currentPath.append(currentNode.val)

        var pathCount = 0
        var pathSum = 0

        for i in stride(from: currentPath.count - 1, through: 0, by: -1) {
            pathSum += currentPath[i]
            if pathSum == sum {
                pathCount += 1
            }
        }

        pathCount += findPathsRecursive(currentNode.left, sum, &currentPath)
        pathCount += findPathsRecursive(currentNode.right, sum, &currentPath)

        currentPath.removeLast()

        return pathCount

    }
}
```
```
126 / 126 test cases passed.
Status: Accepted
Runtime: 204 ms
Memory Usage: 14.3 MB
```

# Hard
```swift
class Solution {
    func maxPathSum(_ root: TreeNode?) -> Int {
        var maxSum = Int.min
        _ = findMaximumPathSum(root, &maxSum)
        return maxSum
    }

    private func findMaximumPathSum(_ currentNode: TreeNode?, _ maxSum: inout Int) -> Int {
        guard let currentNode = currentNode else { return 0 }
        var maxLeftPathSum = findMaximumPathSum(currentNode.left, &maxSum)
        var maxRightPathSum = findMaximumPathSum(currentNode.right, &maxSum)

        maxLeftPathSum = max(maxLeftPathSum, 0)
        maxRightPathSum = max(maxRightPathSum, 0)

        let currentPathSum = maxLeftPathSum + maxRightPathSum + currentNode.val

        maxSum = max(currentPathSum, maxSum)

        return max(maxLeftPathSum, maxRightPathSum) + currentNode.val
    }
}
```
```
94 / 94 test cases passed.
Status: Accepted
Runtime: 92 ms
Memory Usage: 16.3 MB
```