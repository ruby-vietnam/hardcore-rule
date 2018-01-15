## Problem 2:

https://leetcode.com/problems/sort-colors/description/

### Solution

```ruby
def sort_colors(nums)
  hash = Hash.new(0)
  nums.each do |n|
    hash[n] += 1
  end
  count = 0
  [0, 1, 2].each do |key|
    hash[key].times do |n|
      nums[count] = key
      count += 1
    end
  end
end
```

## Problem 3:

https://leetcode.com/problems/word-frequency/description/

### Solution

```bash
cat words.txt| tr -s ' ' '\n' | sort | uniq -c | sort -r | awk '{print $2" "$1}'
```
