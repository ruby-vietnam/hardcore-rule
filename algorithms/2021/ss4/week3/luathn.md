# 1. N-ary Tree Postorder Traversal

https://leetcode.com/problems/n-ary-tree-postorder-traversal/

## 1.1. Summary

## 1.2. Code

```rb
def postorder(root)
  result = []
  stack = []
  stack.push(root)
  until stack.empty?
    node = stack.pop
    break if node.nil?

    result << node.val
    node.children.each { |n| stack.push(n) }
  end
  result.reverse
end
```

# 2. N-ary Tree Preorder Traversal

https://leetcode.com/problems/n-ary-tree-preorder-traversal/

## 2.1. Summary

## 2.2. Code

```rb
def preorder(root)
  result = []
  stack = []
  stack.push(root)
  until stack.empty?
    node = stack.pop
    break if node.nil?

    result << node.val
    node.children.reverse.each { |n| stack.push(n) }
  end
  result
end
```

# 3. Binary Tree Level Order Traversal

https://leetcode.com/problems/binary-tree-level-order-traversal/

## 3.1. Summary

## 3.2. Summary

```rb
def level_order(root)
  result = []
  arr = []
  arr << root if root
  until arr.empty?
    result << arr.map { |n| n.val }
    level = []
    arr.each do |node|
      level << node.left if node.left
      level << node.right if node.right
    end
    arr = level
  end
  result
end
```
