# 169

```ruby
# @param {Integer[]} nums
# @return {Integer}
def majority_element(nums)
    count = {}
    nums.each do |i|
        count[i] = (count[i] || 0) + 1
    end
    
    count.max_by{|k,v| v}[0]
end
```

# 319

```ruby
# @param {Integer} n
# @return {Integer}
def bulb_switch(n)
    Math.sqrt(n).floor
end
```
