# Problem 1: Valid Palindrome II

https://leetcode.com/problems/valid-palindrome-ii/description/

```
Runtime: 368 ms
Your runtime beats 54.55 % of ruby submissions.
```

```ruby
# @param {String} s
# @return {Boolean}
def valid_palindrome(s)
  left = 0
  right = s.length - 1
  while left < right
    if s[left] != s[right]
      s1 = s[left..(right - 1)]
      s2 = s[(left + 1)..right]
      return s1 == s1.reverse || s2 == s2.reverse 
    end
    left += 1
    right -= 1
  end
  true
end
```

# Problem 2: Flatten Binary Tree to Linked List

https://leetcode.com/problems/flatten-binary-tree-to-linked-list/description/

```
Runtime: 52 ms
Your runtime beats 100.00 % of ruby submissions.
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

# @param {TreeNode} root
# @return {Void} Do not return anything, modify root in-place instead.
def flatten(root)
  to_linked_list(root, root)
end

def to_linked_list(root, tail)
  return unless root
  left = flatten(root.left) if root.left
  right = flatten(root.right) if root.right
  if left
    left.right = root.right
    root.right = root.left
    root.left = nil
  end
  return right if right
  return left if left
  root
end
```

# Problem 3: Is Subsequence

https://leetcode.com/problems/is-subsequence/description/

```
Runtime: 364 ms
Your runtime beats 91.67 % of ruby submissions.
```

```ruby
# @param {String} s
# @param {String} t
# @return {Boolean}
def is_subsequence(s, t)
  i = 0
  t.each_char do |c|
    i += 1 if c == s[i]
  end
  i == s.length ? true : false
end
```
