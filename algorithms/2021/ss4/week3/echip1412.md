# Easy 1: https://leetcode.com/problems/n-ary-tree-postorder-traversal/
## Approach
- Similar to DFS for Binary tree, use a stack to store the node and go by post order
## Code
```
class Solution {
    fun postorder(root: Node?): List<Int> {
        val stack = Stack<Node>()
        val result = mutableListOf<Int>()
        if (root == null) {
            return listOf<Int>()
        }
        stack.push(root)
        while (!stack.isEmpty()) {
            val node = stack.pop()
            result.add(0, node.`val`)
            for (childNode in node.children) {
                if (childNode != null) {
                    stack.push(childNode)
                }
            }
        }
        return result
        
    }
}
```
# Medium 1: https://leetcode.com/problems/binary-tree-level-order-traversal/
## Approach
Similar to BFS but need to separate by levels.
### Option 1:
  1. Enqueue the treenode to the queue
  1. Then dequeue everything in the queue -> this should be one level
  1. Repeat until queue is empty
### Option 2:
  1. Enqueue a node and level, the childNode's level will be parentNode's level + 1
## Code
```
class Solution {
    data class NodeInfo(val node: TreeNode, val level: Int)
    
    fun levelOrder(root: TreeNode?): List<List<Int>> {
        val queue = LinkedList<NodeInfo>()
        if (root == null) {
            return emptyList()
        }
        queue.offer(NodeInfo(root, 0))
        val result = mutableListOf<MutableList<Int>>()
        while (queue.isNotEmpty()) {
            val node = queue.poll()            
            if (result.size <= node.level) {
                result += mutableListOf<Int>()
            }
            val treeNode = node.node
            result[node.level].add(treeNode.`val`)
            treeNode.left?.let {
                queue.offer(NodeInfo(it, node.level + 1))
            }
            treeNode.right?.let {
                queue.offer(NodeInfo(it, node.level + 1))
            }
        }
        return result
    }
}
```
