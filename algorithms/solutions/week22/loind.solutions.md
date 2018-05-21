# Problem 1

### Without extra space

```ruby
def majority_element(nums)
  nums.sort[nums.size.div 2]
end
```

### With extra space

```ruby
def majority_element(nums)
  size = nums.size.div 2
  nums.each_with_object({}) do |num, hash|
    hash[num] ||= 0
    hash[num] += 1
    return num if hash[num] > size
  end
end
```
