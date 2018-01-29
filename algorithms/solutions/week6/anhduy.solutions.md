# 697. Degree of an Array

```ruby
def find_shortest_sub_array(nums)
  counting = []
  max = 0
  result = 0
  nums.each_with_index do |num, index|
    if counting[num]
      counting[num][:count] = counting[num][:count] + 1
      counting[num][:stop] = index
    else
      counting[num] = {start: index, count: 1, stop: index}
    end
    if counting[num][:count] > max
      max = counting[num][:count]
      result = counting[num][:stop] - counting[num][:start] + 1
    elsif counting[num][:count] == max && counting[num][:stop] - counting[num][:start] < result
      result = counting[num][:stop] - counting[num][:start] + 1
    end
  end
  return result
end
```
