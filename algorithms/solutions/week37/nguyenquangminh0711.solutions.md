## Problem 1 [Accepted]

O(log(3)n)

The naive solution is just to ternary search. The other solution is to calculate log(3) of n and check its integer nature. But still worse.

https://leetcode.com/problems/power-of-three/description/

```ruby
# @param {Integer} n
# @return {Boolean}
EPSILON = 1e-12
def is_power_of_three(n)
    return false if n <= 0
    log = Math.log(n, 3)
    return (log - log.floor).abs < EPSILON || (log - log.ceil).abs < EPSILON
end
```

## Problem 2 [Accepted]

Use the binary search to find the index of x in the array
- If index < 0 => return first k elements
- If index > length of array => return last k elements
- Otherwise, start from index, threads toward two sides. At each step, compare left and right elements to get the closer element.

O(max(log(n), k))

```ruby
# @param {Integer[]} arr
# @param {Integer} k
# @param {Integer} x
# @return {Integer[]}
def find_closest_elements(arr, k, x)   
    return arr if arr.length <= k

    index = findIndex(arr, x)
    return arr[0..k-1] if index <= 0
    return arr[arr.length-k..arr.length-1] if index >= arr.length - 1
    
    result = [arr[index]]
    leftIndex = index - 1
    rightIndex = index + 1
    while result.length < k
        if leftIndex < 0
            result << arr[rightIndex]
            rightIndex += 1
        elsif rightIndex >= arr.length
            result.unshift(arr[leftIndex])
            leftIndex -= 1
        elsif x - arr[leftIndex] <= arr[rightIndex] - x
            result.unshift(arr[leftIndex])
            leftIndex -= 1
        else
            result << arr[rightIndex]
            rightIndex += 1
        end
    end
    result
end

def findIndex(arr, x)
    left = 0
    right = arr.length - 1
    while left < right
        mid = (left + right) / 2
        if arr[mid] == x
            return mid
        elsif arr[mid] < x
            left = mid + 1
        else
            right = mid - 1
        end
    end
    right
end
```

## Problem 3 [Accepted]

O(n^2 * log(n))

Sort the array, then run through the array, choose 2 numbers. Use binary search to find the last closet number to target. 

```ruby
# @param {Integer[]} nums
# @param {Integer} target
# @return {Integer}
def three_sum_closest(nums, target)
    nums.sort!
    closest_sum = nums[0] + nums[1] + nums[2]
    puts "closest sum = #{closest_sum}"
    (0..nums.length - 3).each do |i|
        (i + 1..nums.length - 2).each do |j|
            sum = nums[i] + nums[j]
            sum += nums[find_next(nums, j, target - sum)]
            closest_sum = sum if (target - closest_sum).abs > (target - sum).abs
        end
    end
    closest_sum
end

def find_next(nums, j, x)
    left = j + 1
    right = nums.length - 1
    while left <= right
        mid = (left + right) / 2
        if nums[mid] == x
            return mid
        elsif nums[mid] < x
            left = mid + 1
        else
            right = mid - 1
        end
    end
    if left >= nums.length
        right
    elsif right <= j
        left
    elsif (x - nums[left]).abs < (x - nums[right]).abs
        left
    else
        right
    end
end
```
