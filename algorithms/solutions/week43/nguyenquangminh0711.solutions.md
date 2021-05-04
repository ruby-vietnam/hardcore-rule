## Problem 3

https://leetcode.com/problems/range-sum-query-immutable/submissions/

Use interval tree. O(n log n).

```ruby
class NumArray
  class Segment
    attr_reader :min, :max
    attr_accessor :sum, :left, :right

    def initialize(min, max, sum)
      @min = min
      @max = max
      @sum = sum
    end
  end

  def initialize(nums)
    @nums = nums
    @root = create_tree(0, nums.length - 1)
  end

  def sum_range(i, j)
    sum(i, j, @root)
  end

  private

  def create_tree(min, max)
    return if min > max

    if min == max
      Segment.new(min, max, @nums[min])
    else
      mid = (min + max) / 2

      left = create_tree(min, mid)
      right = create_tree(mid + 1, max)

      segment = Segment.new(min, max, left&.sum.to_i + right&.sum.to_i)
      segment.left = left
      segment.right = right

      segment
    end
  end

  def sum(i, j, segment)
    return 0 if segment.nil?
    return 0 if i > segment.max || j < segment.min
    return segment.sum if i <= segment.min && segment.max <= j
    sum(i, j, segment.left) + sum(i, j, segment.right)
  end
end
```
