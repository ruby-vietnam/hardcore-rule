## Problem 3
https://leetcode.com/contest/weekly-contest-97/problems/possible-bipartition/#

```
# @param {Integer} n
# @param {Integer[][]} dislikes
# @return {Boolean}
def tranverse(node, map, visited, color)
    if visited[node] != nil
        return visited[node] == color
    end

    visited[node] = color
    map[node].each do |n|
        return false if !tranverse(n, map, visited, !color)
    end
    return true
end

def possible_bipartition(n, dislikes)
    map = Hash.new([])
    dislikes.each do |d|
        map[d[0]] += [d[1]]
        map[d[1]] += [d[0]]
    end

    visited = {}
    (1..n).each do |node|
        if visited[node] == nil
            return false if !tranverse(node, map, visited, true)
        end
    end
    return true
end
```
