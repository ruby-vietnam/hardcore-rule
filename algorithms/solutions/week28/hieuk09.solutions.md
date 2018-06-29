## Problem 2

```ruby
def permute(nums)
  check = Array.new(nums.size) { 0 }
  result = []
  accumulator = []
  run(nums, check, 0, result, accumulator)

  result
end

def run(nums, check, count, result, accumulator)
  if count == nums.size
    result << accumulator
  else
    nums.each_with_index do |num, index|
      if check[index] == 0
        check[index] = 1
        run(nums, check, count + 1, result, accumulator + [num])
        check[index] = 0
      end
    end
  end
end
```
