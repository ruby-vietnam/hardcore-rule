### Prolem 1 - [Majority Element](https://leetcode.com/problems/majority-element/description/)

Status:
```
  ✔ Accepted
  ✔ 44/44 cases passed (56 ms)
```

```ruby
def majority_element(nums)
  count_hash = {}
  size = nums.size
  nums.each do |e|
    count_hash[e] = count_hash[e].to_i + 1
    return e if count_hash[e] > size / 2
  end
end
```
