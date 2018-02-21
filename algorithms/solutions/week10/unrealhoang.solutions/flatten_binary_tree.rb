# @param {TreeNode} root
# @return {Void} Do not return anything, modify root in-place instead.
#         1
#        / \
#       2   5
#      / \   \
#     3   4   6
#
# Move the right tree (5  ) to the rightmost node of left tree (2  )
#                       \                                        \
#                        6                                        4
# Result after 1 step:
#          1
#         / \
#        2   nil
#       / \
#      3   4
#           \
#            5
#             \
#              6
# Move to right branch, apply recursively to the rest
def flatten(root)
  return if root.nil?

  if root.left
    r = root.left
    while r.right
      r = r.right
    end

    r.right = root.right
    root.right = root.left

    root.left = nil
  end
  flatten(root.right)
end
