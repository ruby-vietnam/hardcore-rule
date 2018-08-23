# Problem 3 : Possible Bipartition

URL: https://leetcode.com/contest/weekly-contest-97/problems/possible-bipartition/


Naive Codes:

Status:
```
- Time Limit Exceeded
- 30 / 65 test cases passed.
```

```ruby
def possible_bipartition(n, dislikes)
  partition = Hash.new { 0 }
  bipartition(partition, dislikes)
end

def bipartition(partition, dislikes)
  return true if dislikes.size == 0
  a, b = dislikes.pop
  if partition[a] == 0 && partition[b] == 0
    another_partition = partition.clone
    partition[a] = 1
    partition[b] = 2
    another_partition[b] = 1
    another_partition[a] = 2
    return bipartition(partition, dislikes.clone) || bipartition(another_partition, dislikes.clone)
  elsif partition[a] != 0 && partition[b] != 0
    return false if partition[a] == partition[b] # same group but dislike each other
  elsif partition[a] != 0
    partition[a] == 1 ? partition[b] = 2 : partition[b] = 1
  else # partition[b] != 0
    partition[b] == 1 ? partition[a] = 2 : partition[a] = 1
  end
  bipartition(partition, dislikes.clone)
end
```

Graph:

Status:
```
- Accepted
```

```ruby
class Graph
  attr_accessor :vertexes
  def initialize
    @vertexes = {}
  end

  def add_path(u, v)
    vertexes[u] ||= {}
    vertexes[u][:connect_to] ||= []
    vertexes[u][:connect_to] += [v]
  end

  def bfs(starting_vertex)
    grouping = Hash.new { 0 }
    queue = [[starting_vertex, 1]]

    while queue.any?
      vertex, group = queue.shift
      return false if grouping[vertex] != 0 && grouping[vertex] != group
      grouping[vertex] = group
      next unless vertexes[vertex]
      vertexes[vertex][:connect_to].each do |connecting_vertex|
        if grouping[connecting_vertex] != 0
          return false if grouping[connecting_vertex] == group
          next
        end
        queue << [connecting_vertex, -group]
      end
    end

    true
  end
end

def possible_bipartition(_n, dislikes)
  graph = Graph.new
  dislikes.each { |u,v| graph.add_path(u, v) }
  u, _v = dislikes.first
  graph.bfs(u)
end
```
