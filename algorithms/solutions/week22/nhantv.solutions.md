# Problem 1: Majority Element

https://leetcode.com/problems/majority-element/description/

```
Runtime: 60 ms
Your runtime beats 64.44 % of ruby submissions.
```

```ruby
# @param {Integer[]} nums
# @return {Integer}
def majority_element(nums)
  hash = {}
  nums.each do |num|
    hash[num] ||= 0
    hash[num] += 1
    return num if hash[num] > nums.length / 2
  end
end
```

# Problem 2: Bulb Switcher

https://leetcode.com/problems/bulb-switcher/description/

```
Runtime: 36 ms
Your runtime beats 66.67 % of ruby submissions.
```

```ruby
# @param {Integer} n
# @return {Integer}
def bulb_switch(n)
  Math.sqrt(n).to_i
end
```

# Problem bonus: Range Sum Query - Mutable

https://leetcode.com/problems/range-sum-query-mutable/description/

```
9 / 10 test cases passed.
Time Limit Exceeded
```

```ruby
class NumArray

=begin
    :type nums: Integer[]
=end
    def initialize(nums)
      @nums = nums
      @bit = []
      make_bit
    end


=begin
    :type i: Integer
    :type val: Integer
    :rtype: Void
=end
    def update(i, val)
      @nums[i] = val
      while(i < @nums.length)
        @bit[i] = update_bit(i)     
        i += 1
        i = i + (i & -i) - 1
      end
    end


=begin
    :type i: Integer
    :type j: Integer
    :rtype: Integer
=end
    def sum_range(i, j)
      @bit[-1]
      sum(j) - sum(i - 1)
    end
    
    private
    def make_bit
      0.upto(@nums.length - 1) do |index|
        @bit[index] = update_bit(index)
      end
    end
    def update_bit(index)
      index += 1
      start = index & index - 1
      sum = 0
      while(start < index)
        sum += @nums[start]
        start += 1
      end
      sum
    end
    def sum(index)
      index += 1
      sum = 0
      while(index > 0)
        sum += @bit[index - 1]
        index = index & (index - 1)
      end
      sum
    end
end

# Your NumArray object will be instantiated and called as such:
# obj = NumArray.new(nums)
# obj.update(i,val)
# param_2 = obj.sum_range(i,j)
```
