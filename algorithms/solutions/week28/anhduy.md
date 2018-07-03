# 665

```ruby
def check_possibility(nums)    
  i = 0
  count = 0

  while (count < 2 && i < nums.length - 1) do
    if nums[i] > nums[i+1]
      if i - 1 >= 0
        if nums[i-1] > nums[i+1]
           nums[i+1] = nums[i]
        else 
           nums[i] = nums[i+1]
	end
      else
        nums[i] = nums[i+1]
      end
      count += 1
    end
    i += 1
  end

  if count > 1
    return false
  else
    return true
  end
end

```

# 46

```ruby

def permute(nums)
  result = []
  dfs(nums, [], [], result)
  result
end

def dfs(nums, track, current, result)
  if current.length == nums.length
    result << current.dup
    return
  end

  nums.each_with_index do |num, i|
    if !track[i]
      track[i] = true
      current << num
      dfs(nums, track, current, result)
      track[i] = false
      current.delete_at(current.length - 1)
    end
  end
end
```
