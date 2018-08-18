## Problem 3

https://leetcode.com/contest/weekly-contest-97/problems/possible-bipartition/

Classic bipartie graph. 
- We don't care about people that don't have any relationships.
- 1) Let X = {1}. Find Y = all the dislikes of X. If X & Y not empty, we can't arrange the tables.
- 2) Find T = all dislikes of Y. If Y & T not empty, we can't arrange the tables. If T == X, finish.
- 3) Assign X = T, and back to step 1.

```ruby
# @param {Integer} n
# @param {Integer[][]} dislikes
# @return {Boolean}
def possible_bipartition(n, dislikes)
    dislikes_hash = {}
    dislikes.each do |a, b|
        dislikes_hash[a] ||= []
        dislikes_hash[a] << b
        dislikes_hash[b] ||= []
        dislikes_hash[b] << a
    end
    
    x = Set.new
    x.add(1)
    
    while true
        y = find_dislikes_set(x, dislikes_hash)
        return false unless (x & y).empty?
        t = find_dislikes_set(y, dislikes_hash)
        return false unless (t & y).empty?
        return true if t == x
        x = t
    end
end

def find_dislikes_set(x, dislikes_hash)
    y = Set.new
    x.each do |person|
        next if dislikes_hash[person].nil?
        dislikes_hash[person].each do |other|
            y.add(other)
        end
    end
    y
end```
