# Definition for a binary tree node.
# class TreeNode
#     attr_accessor :val, :left, :right
#     def initialize(val)
#         @val = val
#         @left, @right = nil, nil
#     end
# end

# @param {TreeNode} root
# @return {Integer[][]}
def level_order(root)
  return [] if root.nil?
  result = []
  q = [[root,0]]
  row = []
  cur_lvl = 0
  loop do
    break if q.empty?
    cur, level = q.shift
    if level != cur_lvl
      result << row
      row = []
      cur_lvl = level
    end
    row << cur.val
    q.push([cur.left, level+1]) if cur.left
    q.push([cur.right, level+1]) if cur.right
  end
  result << row
  result
end
