# Problem 1
```ruby
def miniMaxSum(arr)
  sorted_arr = arr.sort
  print sorted_arr[0..3].reduce(&:+)
  print ' '
  print sorted_arr[1..4].reduce(&:+)
end
```

# Problem 2
```ruby
def matchingStrings(strings, queries)
  counting_hash = Hash.new(0)
  strings.each do |string|
    counting_hash[string] += 1
  end

  queries.map { |query| counting_hash[query] }
end
```

# Problem 3
Ko hieu sao bi exceed max stack level o test 5 :((
```ruby
class Location
  attr_accessor :value
  attr_accessor :adjacents
  attr_accessor :discovered_time
  attr_accessor :lowest_connected_location
  attr_accessor :area

  def initialize(value)
    @value = value
    @adjacents = []
  end
end

locations = []
n, m = gets.split(' ').map(&:to_i)


m.times do
  loc1, loc2 = gets.split(' ').map(&:to_i)

  locations[loc1] ||= Location.new(loc1)
  locations[loc2] ||= Location.new(loc2)

  locations[loc1].adjacents << locations[loc2]
  locations[loc2].adjacents << locations[loc1]
end

def visit(u, parents, stack)
  stack << u
  $time += 1
  u.discovered_time = $time
  u.lowest_connected_location = $time
  u.adjacents.each do |adjacent|
    if adjacent.discovered_time
      if adjacent != parents[u.value] && adjacent.discovered_time < u.lowest_connected_location
        u.lowest_connected_location = adjacent.discovered_time
      end
    else
      parents[adjacent.value] = u
      visit(adjacent, parents, stack)

      if adjacent.lowest_connected_location < u.lowest_connected_location
        u.lowest_connected_location = adjacent.lowest_connected_location
      end
    end
  end

  if u.discovered_time == u.lowest_connected_location
    $area += 1
    while true
      top = stack.pop
      top.area = $area
      break if top == u
    end
  end
end

def dfs(location, distance, distances, visited)
  distances[location.value] = distance
  visited[location.value] = true
  location.adjacents.each do |adjacent|
    dfs(adjacent, distance+1, distances, visited) if !visited[adjacent.value]
  end
end

parents = []
stack = []
$time = 0
$area = 0

visit(locations[1], parents, stack)


connected_graph = []

locations.each do |location|
  next unless location
  location.adjacents.each do |adjacent|
    if adjacent.area != location.area
      connected_graph[adjacent.area] ||= Location.new(adjacent.area)
      connected_graph[location.area] ||= Location.new(location.area)

      connected_graph[adjacent.area].adjacents << connected_graph[location.area]
      connected_graph[location.area].adjacents << connected_graph[adjacent.area]
    end
  end
end

if connected_graph.all?(&:nil?)
  puts 0
else
  visited = []
  distances = []
  dfs(connected_graph[1], 0, distances, visited)

  next_start_point = 1
  max = distances[connected_graph[1].value]
  2.upto($area) do |i|
    if distances[i] > max
      max = distances[i]
      next_start_point = i
    end
  end

  visited = []
  dfs(connected_graph[next_start_point], 0, distances, visited)
  max = distances[connected_graph[1].value]
  2.upto($area) do |i|
    if distances[i] > max
      max = distances[i]
    end
  end

  puts max
end
```
