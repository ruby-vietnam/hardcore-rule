# Problemm 2: permutations

URL: https://leetcode.com/problems/permutations/description/

Status;
```
  ✔ Accepted
```
Codes:
```ruby
def permute(nums)
  nums.permutation.to_a
end

```


# Problemm 3: Serialize and Deserialize Binary Tree

URL: https://leetcode.com/problems/serialize-and-deserialize-binary-tree/description/

Status:
```
  ✔ Accepted
```

Codes
```ruby
def tree_to_array(root)
  return [''] unless root
  [root.val] + tree_to_array(root.left) + tree_to_array(root.right)
end

def array_to_tree(root, array)
  element = array.shift
  return if element.to_s.empty?
  root = root || TreeNode.new(element)
  root.left = array_to_tree(root.left, array)
  root.right = array_to_tree(root.right, array)
  root
end

def serialize(root)
  tree_to_array(root).join(',')
end

def deserialize(data)
  array_to_tree(nil, data.split(','))
end

```
