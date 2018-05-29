
Link: https://leetcode.com/problems/sum-of-square-numbers

 * 124 / 124 test cases passed.
 * Status: Accepted
 * Runtime: 108 ms


```ruby
# @param {Integer} c
# @return {Boolean}
def judge_square_sum(c)
  return true if c == 0
  sqrt_c = Math.sqrt(c)
  x = 0;
  while x < sqrt_c do
    y = Math.sqrt(c - x * x)
    return true if y.floor == y
    x = x + 1
  end
  return false
end
```


Link: https://leetcode.com/problems/largest-number

 * 222 / 222 test cases passed.
 * Status: Accepted
 * Runtime: 620 ms


```ruby
# @param {Integer[]} nums
# @return {String}
def compare_number(n1, n2)
  a1 = n1.to_s.chars.map(&:to_i)
  a2 = n2.to_s.chars.map(&:to_i)
  return (a1 + a2).join().to_i < (a2 + a1).join().to_i
end

def largest_number(nums)
  i = 0
  while i < nums.count - 1 do
    j = i + 1
    while j < nums.count do
      if compare_number(nums[i], nums[j])
        nums = swap(nums, i, j)
      end
      j = j + 1
    end
    i = i + 1
  end
  str = nums.join();
  return '0' if str.to_i == 0
  return str  
end

def swap(nums, i, j)
  return nums if i == j 
  nums[i] = nums[i] + nums[j]
  nums[j] = nums[i] - nums[j]
  nums[i] = nums[i] - nums[j]
  nums
end
```