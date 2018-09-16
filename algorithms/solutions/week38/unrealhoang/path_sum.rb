class TreeNode
  attr_accessor :val, :left, :right, :id
  def initialize(val, id)
    @id = id
    @val = val
    @left, @right = nil, nil
  end
end

class Cache
  attr_reader :cache
  def initialize
    @cache = {}
  end
  def count(node, sum)
    return 0 if node.nil?
    @cache[[node, sum]] ||= begin
                              t = (node.val == sum ? 1 : 0) +
                                count(node.left, sum - node.val) +
                                count(node.right, sum - node.val)
                              t
                            end
  end
end

def t(s, root, sum)
  return 0 if root.nil?
  s.count(root, sum) + t(s, root.left, sum) + t(s, root.right, sum)
end

def path_sum(root, sum)
  s = Solution.new
  t(s, root, sum)
end

def tree(arr)
  nodes = arr.map.with_index { |val, index| val ? TreeNode.new(val, index) : nil }
  nodes.each.with_index do |node, i|
    if node
      node.left = nodes[i * 2 + 1]
      node.right = nodes[i * 2 + 2]
    end
  end
  nodes[0]
end

nodes = [10,5,-3,3,2,nil,11,3,-2,nil,1]
root = tree(nodes)
