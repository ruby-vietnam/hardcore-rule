## Problem 1
Link: https://leetcode.com/submissions/detail/165368823/

 * 36 / 36 test cases passed.
 * Status: Accepted

```ruby
def leaf_similar(root1, root2)
    res1 = []
    res2 = []
    stack1 = []
    stack2 = []
    stack1 << root1
    stack2 << root2
    node1 = root1
    node2 = root2
    while !node1.nil? || !node2.nil? do
        node1 = stack1.pop
        node2 = stack2.pop
        next if node1.nil? && node2.nil?

        stack1 << node1.left if !node1.nil? && !node1.left.nil?
        stack1 << node1.right if !node1.nil? && !node1.right.nil?

        stack2 << node2.left if !node2.nil? && !node2.left.nil?
        stack2 << node2.right if !node2.nil? && !node2.right.nil?

        if !node1.nil? && node1.left.nil? && node1.right.nil?
            res1 << node1.val
        end

        if !node2.nil? && node2.left.nil? && node2.right.nil?
            res2 << node2.val
        end
    end
    res1 == res2
end
```
