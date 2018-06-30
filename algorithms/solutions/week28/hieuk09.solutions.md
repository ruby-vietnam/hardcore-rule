## Problem 1

### Solution 1 (brute-force - time limit exceeded)

```ruby
def check?(nums)
  size = nums.size

  !(size - 1).times.any? do |index|
    nums[index] > nums[index + 1]
  end
end

def check_possibility(nums)
  size = nums.size

  size.times.any? do |index|
    if index == 0
      dup = nums.dup
      dup[index] = nums[index + 1]
      check?(dup)
    elsif index == size - 1
      dup = nums.dup
      dup[index] = nums[index - 1]
      check?(dup)
    else
      dup_1 = nums.dup
      dup_2 = nums.dup
      dup_1[index] = nums[index + 1]
      dup_2[index] = nums[index - 1]
      check?(dup_1) || check?(dup_2)
    end
  end
end
```

### Solution 2

```ruby
def check?(nums)
  size = nums.size

  !(size - 1).times.any? do |index|
    nums[index] > nums[index + 1]
  end
end

def check_possibility(nums)
  size = nums.size
  odd_nums = []

  (size - 1).times do |index|
    if nums[index] > nums[index + 1]
      odd_nums << index
    end
  end

  if odd_nums.size > 1
    false
  elsif odd_nums.empty?
    true
  else
    index = odd_nums.first

    if index == 0
      true
    else
      num = nums[index]

      dup_1 = nums.dup
      dup_2 = nums.dup
      dup_1[index] = nums[index + 1]
      dup_2[index + 1] = nums[index]
      check?(dup_1) || check?(dup_2)
    end
  end
end
```

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
