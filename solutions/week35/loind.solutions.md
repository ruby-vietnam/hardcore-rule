# Problem 3

```ruby
def colorizable?(node, color)
  return @colors[node] == color if @colors[node]
  @colors[node] = color

  @graph[node].each do |neighbor|
    return false unless colorizable?(neighbor, color ^ 1)
  end
  true
end

def possible_bipartition(n, dislikes)
  @graph = []
  (1..n).each { |i| @graph[i] = [] }

  dislikes.each do |edge|
    @graph[edge[0]] << edge[1]
    @graph[edge[1]] << edge[0]
  end

  @colors = {}
  (1..n).each do |node|
    return false if !@colors[node] && !colorizable?(node, 0)
  end
  true
end
```
