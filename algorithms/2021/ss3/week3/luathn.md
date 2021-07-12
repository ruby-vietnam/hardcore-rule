# 1. Binary Tree Paths

https://leetcode.com/problems/binary-tree-paths

## 1.1. Summary

## 1.2. Code

```rb
def binary_tree_paths(root)
  arr = []
  path = nil
  find_children(root, arr, path)
end

def find_children(node, arr, path)
  return arr if node.nil?

  if path.nil?
    path = node.val.to_s
  else
    path += "->#{node.val}"
  end
  arr << path if node.left.nil? && node.right.nil?

  find_children(node.left, arr, path)
  find_children(node.right, arr, path)
end
```

# 2. Sum Root To Leaf Numbers

https://leetcode.com/problems/sum-root-to-leaf-numbers

## 2.1. Summary

## 2.2. Code

```rb
def sum_numbers(root)
  arr = []
  sum_p = 0
  sum_path(root, arr, sum_p)
end

def sum_path(node, arr, sum_p)
  return arr.sum if node.nil?

  sum_p = sum_p * 10 + node.val
  arr << sum_p if node.left.nil? && node.right.nil?
  sum_path(node.left, arr, sum_p)
  sum_path(node.right, arr, sum_p)
end
```

