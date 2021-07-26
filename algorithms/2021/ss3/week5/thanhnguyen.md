# 1. (Easy) [168. Excel Sheet Column Title](https://leetcode.com/problems/excel-sheet-column-title/)
## Approach 1:
### 1.1 Solution
-
---
- Time Complexity:
- Space Complexity:
### 1.2 Code
```
 /  test cases passed.
Status: Accepted
Runtime:  ms
Memory Usage:  MB
```

```python
```

# 2. (Easy) [70. Climbing Stairs](https://leetcode.com/problems/climbing-stairs/)
## Approach 1:
### 1.1 Solution
-


### 1.1 Code
```python
```

# 3. (Medium) [198. House Robber](https://leetcode.com/problems/house-robber/)
## Approach 1: Recursion with memorization

### 1.1 Solution
- At position i, robber had to decide with 2 options(we will select max of results):
  - rob that position and move to i + 2
  - ignore that position and move to i + 1
- That mean: nums = [..] -> length is N will have recursion:
                             robFrom(0)
           robFrom(1)                             robFrom(2)
robFrom(2)           robFrom(3)       robFrom(3)              robFrom(4)
- We use an dict to save the duplicate as memorization, for ex: robFrom(2), robFrom(3)
### 1.2 Code

```
68 / 68 test cases passed.
Status: Accepted
Runtime: 32 ms
Memory Usage: 14.4 MB
```
class Solution:
    def rob(self, nums: List[int]) -> int:
        self.memorization = {}
        return self.robFrom(0, nums)

    def robFrom(self, i, nums):
        # out of the house
        if i >=len(nums):
            return 0

        # re-use if exist
        if i in self.memorization:
            return self.memorization[i]

        # calculate max benefit of choice
        max_benefit = max(
            # choice current house and the i+2
            self.robFrom(i+2, nums) + nums[i],
            # not choice current house, move next
            self.robFrom(i+1, nums),
        )

        # save for re-use
        self.memorization[i] = max_benefit

        return max_benefit

```python
```

# 4. (Medium) [213. House Robber II](https://leetcode.com/problems/house-robber-ii/)
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

# 4. (Hard) [1473. Paint House III](https://leetcode.com/problems/paint-house-iii/)
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