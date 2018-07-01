## Problem 1

```ruby
# @param {Integer[]} nums
# @return {Boolean}
def check_possibility(nums)
  error_count = 0

  0.upto(nums.size-2).each do |i|
    next if nums[i] <= nums[i+1]
    error_count += 1
    nums[i+1] = nums[i] if i != 0 && nums[i-1] > nums[i+1]

    return false if error_count > 1
  end

  true
end
```

## Problem 2

```ruby
def generate(n, nums, permutations)
  return permutations << nums.dup if n == 1
  0.upto(n-1) do |i|
    generate(n-1, nums, permutations)
    if n.even?
      nums[n-1], nums[i] = nums[i], nums[n-1]
    else
      nums[n-1], nums[0] = nums[0], nums[n-1]
    end
  end
end

# @param {Integer[]} nums
# @return {Integer[][]}
def permute(nums)
  permutations = []
  generate(nums.size, nums, permutations)
  permutations
end
```

## Problem 3
```ruby
# Encodes a tree to a single string.
#
# @param {TreeNode} root
# @return {string}
def serialize(root)
  return '' unless root
  root.val.to_s + ',' + serialize(root.left) + ',' + serialize(root.right)
end

# Decodes your encoded data to tree.
#
# @param {string} data
# @return {TreeNode}
def deserialize(data)
  data = data.split(',') if data.is_a? String
  value = data.shift
  return nil if value == '' || value == nil
  node = TreeNode.new(value)
  node.left = deserialize(data)
  node.right = deserialize(data)
  return node
end

```

## Problem 4
```ruby
class MedianFinder
  # initialize your data structure here.
  def initialize()
    @numbers = []
  end

  #  :type num: Integer
  #  :rtype: Void
  def add_num(num)
    return @numbers << num if @numbers.size == 0
    low = 0
    high = @numbers.size - 1
    mid = nil

    while low <= high
      mid = (low + high) / 2
      if num == @numbers[mid]
        break
      elsif num < @numbers[mid]
        high = mid - 1
      else
        low = mid + 1
      end
    end

    return @numbers.insert(mid+1, num) if @numbers[mid] <= num
    @numbers.insert(mid, num)
  end

  # :rtype: Float
  def find_median()
    size = @numbers.size
    return @numbers[size/2].to_f if size.odd?
    return (@numbers[size/2 - 1] + @numbers[size/2]) / 2.0
  end
end
```
