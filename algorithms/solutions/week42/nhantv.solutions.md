# Problem 1: Two Sum II - Input array is sorted

https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/

```
Runtime: 44 ms
Your runtime beats 100.00 % of ruby submissions.
```

```ruby
# @param {Integer[]} numbers
# @param {Integer} target
# @return {Integer[]}
def two_sum(numbers, target)
  h = {}
  numbers.each.with_index do |n, i|
    return [h[n].next, i.next] if h[n]
    h[target - n] = i
  end
end
```
