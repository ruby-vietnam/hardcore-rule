# Problem 1: Longest Harmonious Subsequence

https://leetcode.com/problems/longest-harmonious-subsequence/description/

```
Runtime: 162 ms
Your runtime beats 100.00 % of ruby submissions.
```

```ruby
# @param {Integer[]} nums
# @return {Integer}
def find_lhs(nums)
  max = 0
  hash = {}
  nums.each do |num|
    hash[num] ||= 0
    hash[num] += 1
  end
  hash.keys.each do |num|
    temp = hash[num] + hash[num + 1] if hash[num + 1]
    max = temp if temp && temp > max
  end
  max
end
```

# Problem 2: Merge Two Binary Trees

https://leetcode.com/problems/merge-two-binary-trees/description/

```
Runtime: 115 ms
Your runtime beats 54.17 % of ruby submissions.
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
  t = TreeNode.new(nil)
  if t1
    t.val = t1.val 
    t1_left = t1.left
    t1_right = t1.right
  end
  
  if t2
    if t.val
      t.val += t2.val
    else
      t.val = t2.val
    end
    t2_left = t2.left
    t2_right = t2.right
  end
  t.left  = merge_trees(t1_left, t2_left) if t1_left || t2_left
  t.right = merge_trees(t1_right, t2_right) if t1_right || t2_right
  t.val ? t : nil
end
```
