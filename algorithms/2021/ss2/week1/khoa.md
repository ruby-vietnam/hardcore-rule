# Easy

```swift
class Solution {
    func findJudge(_ N: Int, _ trust: [[Int]]) -> Int {
        var possibleJudge = -1
        var hash = [Int: [Int]]()

        for i in 1...N {
            hash[i] = [Int]()
        }

        trust.forEach { trustee in
            hash[trustee[0]]!.append(trustee[1])
        }

        for (key, value) in hash {
            if value.count == 0 {
                possibleJudge = key
            }
        }

        hash.keys.forEach { key in
            if key != possibleJudge {
                if !hash[key]!.contains(possibleJudge) {
                    possibleJudge = -1
                }
            }
        }

        return possibleJudge
    }
}
```
```
Runtime: 828 ms, faster than 32.56% of Swift online submissions for Find the Town Judge.
Memory Usage: 15.2 MB, less than 37.21% of Swift online submissions for Find the Town Judge.
```

# Medium

```swift
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     public var val: Int
 *     public var left: TreeNode?
 *     public var right: TreeNode?
 *     public init(_ val: Int) {
 *         self.val = val
 *         self.left = nil
 *         self.right = nil
 *     }
 * }
 */

extension TreeNode: Equatable {
    public static func ==(lhs: TreeNode, rhs: TreeNode) -> Bool {
        return lhs.val == rhs.val
    }
}

extension TreeNode: Hashable {
    public func hash(into hasher: inout Hasher) {
        hasher.combine(val)
    }
}

extension TreeNode: CustomStringConvertible {
    public var description: String {
        return "Value: \(val)"
    }
}

class Solution {
    func distanceK(_ root: TreeNode?, _ target: TreeNode?, _ K: Int) -> [Int] {
        guard let root = root, let target = target else { return [] }
        var map = [TreeNode: TreeNode]()
        traverseTreePopulateMap(root, root, &map)
        return bfs(root, target, K, map)
    }

    private func traverseTreePopulateMap(_ node: TreeNode?, _ parent: TreeNode?, _ map: inout [TreeNode: TreeNode]) {
        guard let node = node else { return }
        map[node] = parent
        traverseTreePopulateMap(node.left, node, &map)
        traverseTreePopulateMap(node.right, node, &map)
    }

    private func bfs(_ node: TreeNode?, _ target: TreeNode, _ K: Int, _ map: [TreeNode: TreeNode]) -> [Int] {
        var queue = [TreeNode]()
        queue.append(target)

        var visited = Set<TreeNode>()

        var level = 0
        while !queue.isEmpty {
            for i in 0..<queue.count {
                if level == K {
                    return queue.map { $0.val }
                }
                let node = queue.removeFirst()
                visited.insert(node)

                if let left = node.left, !visited.contains(left) {
                    queue.append(left)
                }

                if let right = node.right, !visited.contains(right) {
                    queue.append(right)
                }

                if let parent = map[node], !visited.contains(parent) {
                    queue.append(parent)
                }
            }
            level += 1
        }
        return []
    }
}
```
```
Runtime: 16 ms, faster than 76.53% of Swift online submissions for All Nodes Distance K in Binary Tree.
Memory Usage: 14.3 MB, less than 60.20% of Swift online submissions for All Nodes Distance K in Binary Tree.
```