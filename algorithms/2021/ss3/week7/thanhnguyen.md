# 1. (Easy) [169. Majority Element](https://leetcode.com/problems/majority-element/)
## Approach 1:
### 1.1 Solution

---
- Time Complexity: O(n)
- Space Complexity: O(n)
### 1.2 Code
```
 /  test cases passed.
Status: Accepted
Runtime:  ms
Memory Usage:  MB
```

```python

```


# 2. (Easy) [905. Sort Array By Parity](https://leetcode.com/problems/sort-array-by-parity/)
## Approach 1: An order list and retrieve value by index
### 1.1 Solution
-


### 1.1 Code
```python
```

# 3. (Medium) [15. 3Sum](https://leetcode.com/problems/3sum/)
## Approach 1: Two Pointer

### 1.1 Solution
- First, sort the sums to increase order and use a list to store results
- Second: go through the list ordered
  - call the current value is "current"
  - two pointer is the next of the "current" called left_pointer and the right_pointer is the last number in the right
    - If the left_pointer still smaller than the right_pointer we do check:
      - Call current_sum = sums[left_pointer] + sums[right_pointer]
      - if current_sum < -current, mean we need to move the left pointer closer to the right_pointer to get higher value, we +1 to the left_pointer
      - if current_sum > -current, mean we need to move the right pointer closer to the left_pointer to get lower value, we -1 to the right_pointer
      - - if current_sum == -current mean we hae current + sums[left_pointer] + sums[right_pointer] = 0
        - add [current, sums[left_pointer], sums[right_pointer]] to the results
        - then we need to move the left_pointer closer to the right_pointer by +1 the left_pointer and make sure the value of left_pointer change to avoid the duplicate

---
- Time Complexity: O(n^2)
- Space Complexity:

### 1.2 Code

```
318 / 318 test cases passed.
Status: Accepted
Runtime: 868 ms
Memory Usage: 17.4 MB
```

```python
class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        # sort list
        nums.sort()

        return self.findTriple(nums)

    def findTriple(self, nums):
        results = []
        for i, x in enumerate(nums):
            # avoid duplicate since same value
            if i > 0 and nums[i] == nums[i - 1]:
                continue

            current = x
            left_pointer = i + 1
            right_pointer = len(nums) - 1

            while left_pointer < right_pointer:
                _sum = nums[left_pointer] + nums[right_pointer]
                if _sum == -current:
                    results.append([current, nums[left_pointer], nums[right_pointer]])
                    left_pointer = left_pointer + 1
                    while left_pointer < right_pointer and nums[left_pointer] == nums[left_pointer - 1]:
                        left_pointer = left_pointer + 1
                elif _sum < -current:
                    left_pointer = left_pointer + 1
                else:
                    right_pointer = right_pointer - 1

        return results

```

# 4. (Medium) [16. 3Sum Closest](https://leetcode.com/problems/3sum-closest/)
## Approach 1:
### 1.1 Solution

### 1.2 Code

```
 /  test cases passed.
Status: Accepted
Runtime:  ms
Memory Usage:  MB
```

```python
```

# 4. (Hard) []()
## Approach 1:
### 1.1 Solution

### 1.2 Code

```
 /  test cases passed.
Status: Accepted
Runtime:  ms
Memory Usage:  MB
```

```python
```

# 5. (Hard) [23. Merge k Sorted Lists](https://leetcode.com/problems/merge-k-sorted-lists/)
## Approach 1:
### 1.1 Solution

### 1.2 Code

```
 /  test cases passed.
Status: Accepted
Runtime:  ms
Memory Usage:  MB
```

```python
```

