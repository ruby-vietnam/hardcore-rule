## Problem 1

```ruby
def move_zeroes(nums)
  queue = Queue.new

  nums.each_with_index do |num, index|
    if num == 0
      queue.push(index)
    else
      unless queue.empty?
        zero_index = queue.pop
        nums[index] = 0
        nums[zero_index] = num
        queue.push(index)
      end
    end
  end
end
```
