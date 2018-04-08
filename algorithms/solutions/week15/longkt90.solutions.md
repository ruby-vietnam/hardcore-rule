# Problemm 1:

URL: https://leetcode.com/problems/move-zeroes/description/

Status;
```
  ✔ Accepted
```

```ruby
def move_zeroes(nums)
  left = 0
  right = nums.size - 1
  while left < right do

    while nums[left] != 0 && left < right do
      left += 1
    end

    while nums[right] == 0 && right > left do
      right -= 1
    end

    i = left
    while i < right  do
      nums[i] = nums[i+1]
      i += 1
    end
    nums[right] = 0 if i > left
    right -= 1
  end
end
```
