def leaf_similar(root1, root2)
  leaf_values(root1) == leaf_values(root2)
end

def leaf_values(node)
  return [] if node.nil?
  return [node.val] if node.left.nil? && node.right.nil?
  return leaf_values(node.left) + leaf_values(node.right)
end
