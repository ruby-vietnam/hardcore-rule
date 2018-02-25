# Problemm 2: Flatten Binary Tree

URL: https://leetcode.com/problems/flatten-binary-tree-to-linked-list/description/

Status;
```
  ✔ Accepted
  ✔ 225/225 cases passed (72 ms)
  ✔ Your runtime beats 40 % of ruby submissions
```



```ruby
def flatten(root)
    return unless root
    flatten(root.left) unless root.left.nil?
    flatten(root.right) unless root.right.nil?

    return if root.left.nil? && !root.right.nil? # no need to change as tree only has 1 right node

    # store right tree before replace it with left tree
    t = root.right
    root.right = root.left
    root.left = nil

    # the right tree stored above will be a right tree of the last node of current right tree
    i = root.right
    while i && !i.right.nil? do
      i = i.right
    end
    i.right = t if i
end

```
