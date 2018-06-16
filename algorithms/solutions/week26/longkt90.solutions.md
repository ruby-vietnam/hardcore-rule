### Problem 1 - [Find the different](https://leetcode.com/problems/find-the-difference/description/)

Status:
```
  ✔ Accepted
```

```ruby
def find_the_difference(s, t)
  return if s.size + 1 != t.size
  c = nil
  while s.size > 0
    c = s.slice!(0)
    t.slice!(t.index(c), 1)
  end
  t
end
```

### Problem 2 - [Binary Tree Level Order Traversal](https://leetcode.com/problems/binary-tree-level-order-traversal/description/)

```ruby
def level_order(root)
  nodes = {}
  visit(root, nodes, 1) unless root.nil?
  nodes.values
end

def visit(node, nodes, priority)
  nodes[priority] ||= []
  nodes[priority] << node.val
  visit(node.left, nodes, priority + 1) unless node.left.nil?
  visit(node.right, nodes, priority + 1) unless node.right.nil?
end
```