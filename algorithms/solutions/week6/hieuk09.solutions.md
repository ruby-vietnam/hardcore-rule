## Problem 1

```ruby
def find_shortest_sub_array(nums)
  result = {}
  max_num = nums.first

  nums.each_with_index do |num, index|
    if result[num]
      result[num][0] += 1
      result[num][2] = index
    else
      result[num] = [1, index, index]
    end

    if result[num][0] > result[max_num][0] || (result[num][0] == result[max_num][0] && distance(result[num]) < distance(result[max_num]))
      max_num = num
    end
  end

  distance(result[max_num])
end

def distance(cache)
  cache[2] - cache[1] + 1
end
```
