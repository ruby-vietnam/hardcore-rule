def merge_trees(t1, t2)
  return t2 if t1.nil?
  return t1 if t2.nil?

  t = TreeNode.new(t1.val + t2.val)
  t.left = merge_trees(t1.left, t2.left)
  t.right = merge_trees(t1.right, t2.right)
  t
end
