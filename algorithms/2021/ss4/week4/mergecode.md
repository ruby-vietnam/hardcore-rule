# 1. Best Time to Buy and Sell Stock
https://leetcode.com/problems/best-time-to-buy-and-sell-stock/submissions/

## 1.1. Summary
- Traversal the array, we find mininum element as we saw in first k items

## 1.2. Code

``` python
class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        if not prices:
            return 0
        
        min_ = prices[0]
        res = 0
        
        for idx in range(1, len(prices)) :
            price = prices[idx]
            
            if min_ > price:
                min_ = price
            
            res = max(res, price - min_)
            
        return res
```

# 2.  Two Sum

https://leetcode.com/problems/two-sum/
## 2.1. Summary

- Create number2idx mapper


## 2.2. Code

```python

class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        mapper = {}
        
        for idx, num in enumerate(nums):            
            mapper[num] = idx
        
        for idx, num in enumerate(nums):
            if target - num in mapper and mapper[target-num] != idx:
                return sorted([idx, mapper[target-num]])        
```

# 3. Merge Intervals

https://leetcode.com/problems/merge-intervals/

## 3.1. Summary

- Sort array in order to check overlapping
- Recursively merge

## 3.2. Code

```python
class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        intervals = sorted(intervals, key= lambda d: d[0])
        
        def _check_overlap(a, b):
            sa, ea = a
            sb, eb = b
            
            if ea < sb:
                return False
            
            return True
        
        def _merge_overlap(a, b):
            sa, ea = a
            sb, eb = b
            
            s = min(sa, sb)
            e = max(ea, eb)
            
            return [s,e]
        
        if not intervals:
            return []
        
        i = 0
        
        current_ = intervals[i]
        
        res = []
        
        while i < len(intervals):
            while i < len(intervals) - 1 and _check_overlap(current_, intervals[i+1]):
                current_ = _merge_overlap(current_, intervals[i+1])
                i += 1
            
            res.append(current_)
            
            if i < len(intervals) - 1:
                current_ = intervals[i+1]
            
            i += 1
        
        return res                          
```


# 4. Find First and Last Position of Element in Sorted Array

https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/

## 4.1. Summary

- We search by binary search tree
- Trick: at comparision equal, you need to pick leftmost or rightmost in order to search numbers


## 4.2. Code

```python
class Solution:
    def searchRange(self, nums: List[int], target: int) -> List[int]:
        
        l, r = 0, len(nums) - 1
        s, e = -1, -1
        
        # finding start
        while l <= r:
            mid = l + (r-l) // 2
            
            if target == nums[mid]:
                s = mid
            
            if nums[mid] < target:
                l = mid + 1
            elif nums[mid] > target:
                r = mid - 1
            else:
                # go left most                
                r = mid - 1
            
        l, r = 0, len(nums) - 1
        
        while l <= r:
            mid = l + (r-l) // 2
                        
            if target == nums[mid]:
                e = mid
            
            if nums[mid] < target:
                l = mid + 1
            elif nums[mid] > target:
                r = mid - 1
            else:
                # go left most                
                l = mid + 1
            
        
        return s, e                            
```

# 5. Candy

https://leetcode.com/problems/candy/solution/

## 5.1: Summary