# Problemm 1: Maximum Product of Three Numbers

URL: https://leetcode.com/problems/maximum-product-of-three-numbers/description/

Status;
```
  ✔ Accepted
  ✔ 83/83 cases passed (96 ms)
  ✔ Your runtime beats 50 % of ruby submissions
```

```ruby
def maximum_product(nums)
  i = j = 0;
  size = nums.size
  # move 3 bigest numbers to the beginning of array
  while i < 3 do
    j = i + 1
    while j < size do
      if nums[i] < nums[j]
        swap_elements(nums, i, j)
      end
      j += 1
    end
    i += 1
  end

  # move 2 smallest numbers to the end of array
  i = size - 1
  while i > size - 3 do
    j = i - 1
    while j > 0 do
      if nums[i] > nums[j]
        swap_elements(nums, i, j)
      end
      j -= 1
    end
    i -= 1
  end
  nums[0] * (nums[1] * nums[2] > nums[size-1] * nums[size-2] ? nums[1] * nums[2] : nums[size-1] * nums[size-2])
end

def swap_elements(nums, i, j)
  nums[i] = nums[i] ^ nums[j]
  nums[j] = nums[i] ^ nums[j]
  nums[i] = nums[i] ^ nums[j]
end

```
