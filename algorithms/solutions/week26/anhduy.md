# 389 

```ruby
def index(s)
    a = {}
    s.split("").each do |i|
        a[i] = a[i] ? (a[i] + 1) : 1
    end

    return a
end

def find_the_difference(s, t)
    index_s = index(s)
    index_t = index(t)
    
    index_t.keys.each do |k|
        if index_s[k] != index_t[k]
            return k
        end
    end
end
```

# 102

```ruby
def level_order(root)
    unless root
      return []
    end
    result = []
    result[0] = [root.val]
    current_level = [root]
    level = 0
    while current_level.length > 0 do
        level += 1
        next_level = []
        current_level.each do |node|
            if node.left
                next_level << node.left
            end
            
            if node.right
                next_level << node.right
            end
        end
        if next_level.length > 0
            result[level] = next_level.map(&:val)
        end
        current_level = next_level
    end
    result
end
```
