# 1. Linked List Cycle

https://leetcode.com/problems/linked-list-cycle

## 1.1. Summary

- Using Tortoise and Hare algorithm

## 1.2. Code

```rb
def hasCycle(head)
  hare = tortoise = head
  while hare
    hare = hare&.next&.next
    return true if hare == tortoise

    tortoise = tortoise.next
  end
  false
end
```

# 3. Binary Search Tree Iterator

https://leetcode.com/problems/binary-search-tree-iterator

## 3.1. Summary

## 3.2. Code

```rb
class BSTIterator
  # type root: TreeNode
  def initialize(root)
    @sorted_node = BSTIterator.sort_node(root)
    @current_index = -1
  end

  # rtype: Integer
  def next
    index = @current_index += 1
    @sorted_node[index].val
  end

  # rtype: Boolean
  def has_next
    @current_index < @sorted_node.length - 1
  end

  class << self
    def sort_node(node)
      arr = []

      recursive(node, arr)
    end

    def recursive(node, arr)
      return if node&.val.nil?

      recursive(node.left, arr) if node.left

      arr << node
      recursive(node.right, arr) if node.right

      arr
    end
  end
end
```

## 3.3 Analyzing

- Time complexity: O(n)
- Space complexity: O(n)
