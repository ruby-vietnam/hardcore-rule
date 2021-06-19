# Week 5

## Problem 1
https://leetcode.com/problems/number-of-good-pairs/

Brute force solution is using two loops to check every possible pairs we can have.

```python
class Solution:
    def numIdenticalPairs(self, nums: List[int]) -> int:
        r = 0
        for i in range(len(nums)-1):
            for j in range(i+1, len(nums)):
                if nums[i] == nums[j]:
                    r += 1
        return r
```

Above solution has time complexity O(n^2), we can sacrifice space complexity to reduce time complexity here by using a hashmap to store how many times we have encounter certain values before.

```python
class Solution:
    def numIdenticalPairs(self, nums: List[int]) -> int:
        r = 0
        mem = {}
        for i in range(len(nums)):
            if nums[i] in mem:
                r += mem[nums[i]]
                mem[nums[i]] += 1
            else:
                mem[nums[i]] = 1
        return r
```
```
48 / 48 test cases passed.
Status: Accepted
Runtime: 32 ms
Memory Usage: 14.3 MB
```

Time complexity: O(n)

Space complexity: O(n)

## Problem 2
https://leetcode.com/problems/partition-array-for-maximum-sum

Base on the problem, we can have brute force solution pretty straightforward as below using recursive:

```python
class Solution:
    def maxSumAfterPartitioning(self, arr: List[int], k: int) -> int:
        n = len(arr)
        
        def partition(start_idx):
            if start_idx >= n:
                return 0
            
            max_sum = 0
            # recursively try all possible partitions within k length, start from start_idx
            for i in range(1, min(k+1, n-start_idx+1)):
                s = max(arr[start_idx:start_idx+i]) * i + partition(start_idx+i)
                if s > max_sum:
                    max_sum = s
                    a = arr[start_idx:start_idx+i]
            return max_sum
        return partition(0)
```

Using recursive solves the problem, but it is not an optional solution (TLE) because we have called `partition(start_idx)` many times with same `start_idx` value, which is an overlapping.

We can easily see that we can use DP for our problem because it is overlapping and final optional solution combines of sub-optimal solutions.

```
Input: [1,15,7,9,2,5,10] with k = 3 and n = 7
Use an array to keep largest sum value starts from a index, let's go from right to left:

- i = 6: [10] -> sum is 10 (now mem = [0, 0, 0, 0, 0, 0, 10])
- i = 5: [5, 10] -> sum is 20 = [5, 10] (now mem = [0, 0, 0, 0, 0, 20, 10])
- i = 4: [2, 5, 10] -> sum is 30 = [2, 5, 4] (now mem = [0, 0, 0, 0, 30, 20, 10])
- i = 3: [9, 2, 5, 10] -> sum is 39 = [9] + [2, 5, 10] = [9] + mem[4] (now mem = [0, 0, 0, 39, 30, 20, 10])
- i = 2: [7, 9, 2, 5, 10] -> sum is 48 = [7, 9] + [2, 5, 10] = [9, 9] + mem[4] (now mem = [0, 0, 48, 39, 30, 20, 10])
...
```

```python
class Solution:
    def maxSumAfterPartitioning(self, arr: List[int], k: int) -> int:
        n = len(arr)
        
        # mem[i] holds largest sum from index i to the end
        mem = [0 for _ in range(n)]
        
        # bottom-up
        for i in range(n-1, -1, -1):
            max_sum = 0
            max_val = 0
            # try out all possible partitions
            for j in range(1, min(k+1, n-i+1)):
                # update max value so far
                if arr[i+j-1] > max_val:
                    max_val = arr[i+j-1]
                # get the sum
                s = max_val * j + (mem[i+j] if i+j < n else 0)
                if s > max_sum:
                    max_sum = s
            mem[i] = max_sum
        return mem[0]
```
```
52 / 52 test cases passed.
Status: Accepted
Runtime: 288 ms
Memory Usage: 14.3 MB
```

Time complexity: O(kn) due to two loops

Space complexity: O(n) for memory array
