# Problem 1:
Url: https://leetcode.com/problems/longest-harmonious-subsequence/description/

# Problem 2:
Url: https://leetcode.com/problems/merge-two-binary-trees/description/

Status:
```
  ✔ Accepted
  ✔ 183/183 cases passed (109 ms)
  ✔ Your runtime beats 72.92 % of ruby submissions
```

```ruby
# Definition for a binary tree node.
# class TreeNode
#     attr_accessor :val, :left, :right
#     def initialize(val)
#         @val = val
#         @left, @right = nil, nil
#     end
# end

# @param {TreeNode} t1
# @param {TreeNode} t2
# @return {TreeNode}
def merge_trees(t1, t2)
  merge_nodes(t1, t2, nil, true)
  return t1 ? t1 : t2
end

# merge node n2 to n1
def merge_nodes(n1, n2, root, left_side = false)
  return n1 if n2.nil?

  if n1.nil?
    if left_side
      root.left = n2 if root
    else
      root.right = n2
    end
    return n2
  end

  n1.val += n2.val
  merge_nodes(n1.left, n2.left, n1, true)
  merge_nodes(n1.right, n2.right, n1)
end


```

# Problem 3:
Url: https://leetcode.com/problems/gray-code/description/

# Bonus problem:
Url: https://leetcode.com/problems/number-of-longest-increasing-subsequence/description/

