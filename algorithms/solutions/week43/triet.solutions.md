## Problem 3

```ruby
class NumArray

=begin
    :type nums: Integer[]
=end
    def initialize(nums)
      sum = 0
      @nums = nums.map { |n| sum += n; sum }
    end


=begin
    :type i: Integer
    :type j: Integer
    :rtype: Integer
=end
    def sum_range(i, j)
      return @nums[j] if i == 0
      @nums[j] - @nums[i-1]
    end
end
```
