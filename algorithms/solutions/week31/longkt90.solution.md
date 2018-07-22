# Problem 2 : Binary tree maximum path sum

URL: https://leetcode.com/problems/binary-tree-maximum-path-sum/description/


Status:
```
  ✔ Accepted
```
Codes:
```ruby
def max_path_sum(root)
  max_path_from(root)[1]
end

def max_path_from(node)
  return [nil, nil] unless node

  left_sum = max_path_from(node.left)
  right_sum = max_path_from(node.right)
  sum_with_node = left_sum[0] + right_sum[0] + node.val if left_sum[0] && right_sum[0]
  max_child = [left_sum[0], right_sum[0]].compact.max
  max_single_path_at_node = max_child ? [node.val + max_child, node.val].max : node.val
  max_at_node = [sum_with_node, max_single_path_at_node, left_sum[1], right_sum[1]].compact.max
  [max_single_path_at_node, max_at_node]
end

```
