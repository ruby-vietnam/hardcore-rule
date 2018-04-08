# Problem 1: Move Zeroes

```
Runtime: 72 ms
Your runtime beats 26.47 % of ruby submissions.
```

```ruby
# @param {Integer[]} nums
# @return {Void} Do not return anything, modify nums in-place instead.
def move_zeroes(nums)
  number_of_zero = 0
  nums.length.times do |i|
    if nums[i] == 0
      number_of_zero += 1
    else
      next if number_of_zero == 0
      nums[i], nums[i - number_of_zero] = nums[i - number_of_zero], nums[i]
    end
  end
end
```

# Problem 2: Ugly Number II

https://leetcode.com/problems/ugly-number-ii/description/

```
Runtime: 1784 ms
Best runtime: 84 ms =_="
```

```ruby
# @param {Integer} n
# @return {Integer}
def nth_ugly_number(n)
  array = [1]
  i = 0
  until i == n do
    min = array.delete(array.min)
    array << min * 2 << min * 3 << min * 5
    i += 1
  end
  min
end
```
