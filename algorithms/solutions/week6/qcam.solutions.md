# Problem 1

```rb
# @param {Integer[]} nums
# @return {Integer}
def find_shortest_sub_array(nums)
    cache = {}
    max_degree = 0

    for i in 0..(nums.length - 1)
        num = nums[i]
        if cache.has_key?(num)
            cache[num][:occurrences] += 1
            cache[num][:end_index] = i
            max_degree = cache[num][:occurrences] >= max_degree ? cache[num][:occurrences] : max_degree
        else
            cache[num] = {
                occurrences: 1,
                start_index: i,
                end_index: i,
            }
            max_degree = max_degree < 1 ? 1 : max_degree
        end
    end

    max = cache.select { |_, v| v[:occurrences] == max_degree }.map { |k, v| v[:end_index] - v[:start_index]}.min
    max + 1
end
```
