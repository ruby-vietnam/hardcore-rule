## Problem 1
https://leetcode.com/problems/leaf-similar-trees/description/

```
# Definition for a binary tree node.
# class TreeNode
#     attr_accessor :val, :left, :right
#     def initialize(val)
#         @val = val
#         @left, @right = nil, nil
#     end
# end

# @param {TreeNode} root1
# @param {TreeNode} root2
# @return {Boolean}
def tranverse(root, arr)
    arr.push root.val if !root.left && !root.right

    tranverse(root.left, arr) if root.left
    tranverse(root.right, arr) if root.right
end

def leaf_similar(root1, root2)
    arr1 = []
    arr2 = []
    tranverse(root1, arr1)
    tranverse(root2, arr2)
    arr1 == arr2
end
```
