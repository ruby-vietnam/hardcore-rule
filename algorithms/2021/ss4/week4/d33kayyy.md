# Best Time to Buy and Sell Stock

```python
class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        buy_price = float('+inf')
        max_profit = 0
        for n in prices:
            buy_price = min(n, buy_price)
            max_profit = max(max_profit, n - buy_price)
        return max_profit
```


# Two Sum

```python
class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        table = {}
        for i, n in enumerate(nums):
            idx = table.get(target - n)
            if idx is not None:
                return [idx, i]
            else:
                table[n] = i
```

# Merge Intervals


```python
class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        intervals.sort(key=lambda x: x[0])
        
        res = []
        prev = intervals[0]
        for i in range(1, len(intervals)):
            cur = intervals[i]
            if prev[0] <= cur[0] <= prev[1] <= cur[1] or prev[0] <= cur[0] <= cur[1] <= prev[1]:
                prev = [prev[0], max(cur[1], prev[1])]
            else:
                res.append(prev)
                prev = cur
        res.append(prev)
        return res
```

# Find First and Last Position of Element in Sorted Array

```python
class Solution:
    def searchRange(self, nums: List[int], target: int) -> List[int]:
        result = [-1, -1]
        l, r = 0, len(nums)

        while l < r:
            mid = (l + r) // 2
            if nums[mid] < target:
                l = mid + 1
            else:
                r = mid

        if l >= len(nums) or nums[l] != target:
            return result
        else:
            result[0] = l

        r = len(nums)
        while l < r:
            mid = (l + r) // 2
            if nums[mid] > target:
                r = mid
            else:
                l = mid + 1

        result[1] = l - 1
        return result
```

# Candy 
