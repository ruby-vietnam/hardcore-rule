## 997. Find the Town Judge

https://leetcode.com/problems/find-the-town-judge/

Nodes are people. Edges from person A to person B means that person A trusts person B.

Iterate through all edges, have 2 arrays: `in_count` and `out_count` to count the in-edges and out-edges to each nodes.

"Judge" is the node with `in_count[x] == N-1 && out_countt[x] == 0`. 

Time complexity: `O(E+V)`

```
Runtime: 108 ms, faster than 62.50% of Ruby online submissions for Find the Town Judge.
Memory Usage: 212.1 MB, less than 45.00% of Ruby online submissions for Find the Town Judge.
```

```ruby
# @param {Integer} n
# @param {Integer[][]} trust
# @return {Integer}
def find_judge(n, trust)
  in_count = Hash.new(0)
  out_count = Hash.new(0)

  trust.each do |t|
    in_count[t[1]] += 1
    out_count[t[0]] += 1
  end

  (1..n).each do |i|
    return i if out_count[i] == 0 && in_count[i] == n - 1
  end
  return -1
end
```

## 863. All Nodes Distance K in Binary Tree

https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree/

### Approach 1:

First, convert the tree to Indirected Graph, using DFS from tree root
Second, use BFS to traverse the graph from `target` node, just go `k` levels deep.

In the below code, I intended to use BFS but end up using DFS, but it is still Accepted with poor performance and memory usage.

Complexity: `O(2(V+E))`

```
Runtime: 76 ms, faster than 6.25% of Ruby online submissions for All Nodes Distance K in Binary Tree.
Memory Usage: 210.7 MB, less than 6.25% of Ruby online submissions for All Nodes Distance K in Binary Tree.
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
# @param {TreeNode} target
# @param {Integer} k
# @return {Integer[]}

def distance_k(root, target, k)
  @g = {}
  @result = []
  @visited = Hash.new(false)
  
  # - Convert the tree to graph by DFS from root
  visit(root)
  
  # pp @g.keys
  # pp @g.values
  
  # BFS from node `target`, stop at level k
  bfs(target.val, 0, k)
  
  return @result
end

def bfs(node, level, k)
  # pp "Visiting node #{node}, level #{level}"
  return if @visited[node]
  @visited[node] = true
  
  if level == k
    @result << node 
    return
  end
  
  @g[node]&.each do |next_node, _|
    bfs(next_node, level + 1, k)
  end
end

def visit(node)
  if node.left
    # pp "Setting #{node.val} -> #{node.left.val}"
    @g[node.val] = {} if @g[node.val].nil?
    @g[node.val][node.left.val] = true
    @g[node.left.val] = {} if @g[node.left.val].nil?
    @g[node.left.val][node.val] = true
    visit(node.left) 
  end
  if node.right
    # pp "Setting #{node.val} -> #{node.right.val}"
    @g[node.val] = {} if @g[node.val].nil?
    @g[node.val][node.right.val] = true
    @g[node.right.val] = {} if @g[node.right.val].nil?
    @g[node.right.val][node.val] = true
    visit(node.right) 
  end
end
```

### Approach 2:

Step 1: Use DFS to mark parent of each node
Step 2: Use BFS

Time complexity: `O(E+V+V)`

Performance improves a little bit:

```
Runtime: 68 ms, faster than 31.25% of Ruby online submissions for All Nodes Distance K in Binary Tree.
Memory Usage: 210.5 MB, less than 12.50% of Ruby online submissions for All Nodes Distance K in Binary Tree.
```

```ruby
def distance_k(root, target, k)
  @parents = {}
  @result = []
  @visited = {}
  
  # DFS to mark parent of all nodes
  visit(root)
  
  # pp @parents
  
  # BFS from node `target`, stop at level k
  q = Queue.new
  q << [target, 0]
  
  while !q.empty?
    item = q.pop
    node = item[0]
    @visited[node.val] = true
    if item[1] == k
      @result << item[0].val
      next
    end
    
    next_level = item[1] + 1
    q << [@parents[node.val], next_level] if @parents[node.val] && !@visited[@parents[node.val].val]
    q << [node.left, next_level] if node.left && !@visited[node.left.val]
    q << [node.right, next_level] if node.right && !@visited[node.right.val]
  end
  
  return @result
end
  
def visit(node)
  if node.left
    @parents[node.left.val] = node
    visit(node.left)
  end
  if node.right
    @parents[node.right.val] = node
    visit(node.right)
  end
end
```
