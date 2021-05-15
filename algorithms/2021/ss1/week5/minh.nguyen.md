## 653. Two Sum IV - Input is a BST

https://leetcode.com/problems/two-sum-iv-input-is-a-bst/

```ruby
# Definition for a binary tree node.
# class TreeNode
#     attr_accessor :val, :left, :right
#     def initialize(val = 0, left = nil, right = nil)
#         @val = val
#         @left = left
#         @right = right
#     end
# end
# @param {TreeNode} root
# @param {Integer} k
# @return {Boolean}
def all_values(node, hash)
    return if node.nil?

    hash[node.val] ||= 0
    hash[node.val] += 1
    all_values(node.left, hash)
    all_values(node.right, hash)
    hash
end

def find_target(root, k)
    vals = all_values(root, {})
    vals.keys.each do |val|
        if val == k - val
            return true if vals[val] >= 2
        else
            return true if vals[k - val]
        end
    end
    false
end
```

## 437. Path Sum III

https://leetcode.com/problems/path-sum-iii/

```ruby
# Definition for a binary tree node.
# class TreeNode
#     attr_accessor :val, :left, :right
#     def initialize(val = 0, left = nil, right = nil)
#         @val = val
#         @left = left
#         @right = right
#     end
# end
# @param {TreeNode} root
# @param {Integer} target_sum
# @return {Integer}
def path_sum(root, target_sum)
    count = 0
    queue = [[root, []]]
    until queue.empty?
        node, sums = queue.shift
        next if node.nil?

        new_sums = sums.map! { |sum| sum + node.val }.push(node.val)
        count += new_sums.count(target_sum)
        queue << [node.left, new_sums.dup] if node.left
        queue << [node.right, new_sums.dup] if node.right
    end
    count
end
```

```
Runtime: 172 ms, faster than 62.50% of Ruby online submissions for Path Sum III.
Memory Usage: 224.2 MB, less than 25.00% of Ruby online submissions for Path Sum III.
```

## 124. Binary Tree Maximum Path Sum

https://leetcode.com/problems/binary-tree-maximum-path-sum/

```ruby
# Definition for a binary tree node.
# class TreeNode
#     attr_accessor :val, :left, :right
#     def initialize(val)
#         @val = val
#         @left, @right = nil, nil
#     end
# end

# @param {TreeNode} root
# @return {Integer}
def max_path_sum(root)
    TreeNode.send(:attr_accessor, :sum)

    calculate_sums(root)
    find_max_sum(root)
end

def calculate_sums(node)
    return 0 if node.nil?
    node.sum = [
        calculate_sums(node.left) + node.val,
        calculate_sums(node.right) + node.val,
        node.val
    ].max
    node.sum
end

def find_max_sum(node)
    if node.left.nil? && node.right.nil?
        node.sum
    elsif node.left.nil?
        [node.sum, find_max_sum(node.right)].max
    elsif node.right.nil?
        [node.sum, find_max_sum(node.left)].max
    else
        [
          node.sum,
          find_max_sum(node.right),
          find_max_sum(node.left),
          (node.left.sum + node.right.sum + node.val)
        ].max
    end
end
```

```
Runtime: 84 ms, faster than 63.08% of Ruby online submissions for Path Sum III.
```
