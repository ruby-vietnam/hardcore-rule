# Problem 1: Non-decreasing Array

https://leetcode.com/problems/non-decreasing-array/description/

```
Runtime: 56 ms
Your runtime beats 100.00 % of ruby submissions.
```

```ruby
# @param {Integer[]} nums
# @return {Boolean}
def check_possibility(nums)
  is_modified = false
  0.upto(nums.length - 2) do |i|
    if nums[i] > nums[i + 1]
      if is_modified
        return false
      else
        if i > 0 && nums[i - 1] > nums[i + 1]
          nums[i + 1] = nums[i]
        end
        is_modified = true
      end
    end
  end
  true
end
```

Problem 2: Permutations

https://leetcode.com/problems/permutations/description/

```
Runtime: 44 ms
Your runtime beats 100.00 % of ruby submissions
```

```ruby
# @param {Integer[]} nums
# @return {Integer[][]}
def permute(nums)
  return [nums] if nums.length <= 1
  result = []
  0.upto(nums.length - 1) do |i|
    permute(nums - [nums[i]]).each do |sub_permute|
      result.push([nums[i]] + sub_permute)
    end
  end
  result
end
```
