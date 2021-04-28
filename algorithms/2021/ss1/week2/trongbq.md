# Week 2
## Problem 1
https://leetcode.com/problems/last-stone-weight/

### Brute Force
**How**:

Repeat until there is one or zero stones left:
  - Select 2 stones with largest weight buy sorting the list.
  - Smash them together follow the rule
We can select 2 largest stones by sorting all stones by weight each iteration.

**Analysis**

The outer loop iterate maximum n-1 times (every smashing has stone left to push back on the list), sort stone take nlogn so the total running time is O(n^2logn).

There is only single variable to store remaning stone, so space complexity is O(1).

```python
class Solution:
    def lastStoneWeight(self, stones: List[int]) -> int:
        while len(stones) > 1:
						# sort stones and get two largest stones out and smash them
            stones.sort()
            rem = abs(stones.pop() - stones.pop())
            # if there is remaining, append to list of stones
            if rem != 0:
                stones.append(rem)
        return stones[0] if len(stones) > 0 else 0
```
```
70 / 70 test cases passed.
Status: Accepted
Runtime: 36 ms
Memory Usage: 14.3 MB
```

### Use heap data structure
**How**:

We just need to take two heaviest stones and don't care about remaining stones, so sorting all stones seems wasted.
Heap supports take the min (max) value by logn time.

**Analysis**:

Heap operations (`heapify`, `heappop`, and `heappush`) take O(logn) running time, so time complexity overall is O(nlogn).

Space complexity is still O(1)

```python
class Solution:
    def lastStoneWeight(self, stones: List[int]) -> int:
        # little trick to make min-heap works as max-heap in Python
        stones = [-a for a in stones]
        heapq.heapify(stones)
        
        while len(stones) > 1:
            sm = abs(heapq.heappop(stones) - heapq.heappop(stones))
            if sm != 0:
                heapq.heappush(stones, -sm)
        return -stones[0] if len(stones) > 0 else 0
```

```
70 / 70 test cases passed.
Status: Accepted
Runtime: 32 ms
Memory Usage: 14.3 MB
```
## Problem 2
https://leetcode.com/problems/last-stone-weight-ii/

**How**
1. Why does the rock smashing refer to the difference of two sums: S1 and S2, is there anything proving that the difference of these two sets is the result we're looking for?
2. Why is it related to 0/1 knapsack?

Question 1:
> Why does the rock smashing refer to the difference of two sums: S1 and S2

```
Starting with 2 stones:
a - b
Get the 3rd stone c:
c - (a - b) = c - a + b
Take the 4th stone as d:
d - (c - (a - b)) = d - c + a - b = (d + a) - (c + b)
Get the 3rd stone is e:
e - (d - (c - (a - b))) = e - d + c - a + b = (e + c + b) - (d + a)
```

Thus, it can be seen that the nature of beating stones is to keep hitting each other until the end, and is equal to the difference of two sums: `diff = S1 - S2`.

As in the example, `S1 = [e, c, b]`, `S2 = [d, a]`

> Does anything prove that difference of these two sets is the result we need?

```
Suppose S1> = S2
S1 + S2 = S
S1 - S2 = diff => diff = S - S2 - S2 = S - 2 * S2
```

S stays the same (the sum of all stones).
So to find the smallest diff, S2 must be the largest,
but S2 cannot exceed S/2 so the problem is to find S2 which is maximum sum and does not exceed S/2

Question 2: Why is it related to 0/1 knapsack?

S2 = sum of some stones in set S2 => need to find some stones whose total is the greatest (<= S/2).

This is similar to 0/1 knapsack where its problem is to find objects whose total weight <= W has the greatest value. Here, the weight is S/2 and find the greatest value is sum of stones.

**Analysis**

Let's call maximum stone weight is m.

Time complexity is nlogn for sorting stones and O(nm/2) for two loops so overall complexity is O(nm).

Space complexity is obviously O(nm).

```python
class Solution:
    def lastStoneWeightII(self, stones: List[int]) -> int:
        stone_sum = sum(stones)
        max_s2 = stone_sum // 2
        n = len(stones)
        
        stones.sort()
        
        # s[i][j] is maximum sum of stones in stones[:i+1] until j
        s = [[0 for _ in range(max_s2+1)] for _ in stones]
        for i in range(n):
            for j in range(1, max_s2+1):
                s[i][j] = max(s[i-1][j], 
                              s[i-1][j-stones[i]] + stones[i] if j >= stones[i] else 0)
                
        return stone_sum - 2*s[n-1][max_s2]
```
```
86 / 86 test cases passed.
Status: Accepted
Runtime: 84 ms
Memory Usage: 14.8 MB
```

We can reduce space complexity from 2D array into 1D array, time complexity is still O(nm) but space complexity is O(m).

```python
class Solution:
    def lastStoneWeightII(self, stones: List[int]) -> int:
        stone_sum = sum(stones)
        max_s2 = stone_sum // 2
        n = len(stones)
        
        stones.sort()
        
        # s[j] is maximum sum of stones in stones[:i+1] until j
        s = [0 for _ in range(max_s2+1)]
        for i in range(n):
            cs = s.copy()
            for j in range(1, max_s2 + 1):
                s[j] = max(cs[j], cs[j-stones[i]] + stones[i] if j >= stones[i] else 0)

        return stone_sum - 2*s[max_s2]
```

```
86 / 86 test cases passed.
Status: Accepted
Runtime: 80 ms
Memory Usage: 14.8 MB
```

## Problem 3
https://leetcode.com/problems/find-k-th-smallest-pair-distance/

### Brute force
**How**:

Generate all pairs and store distance values of all pairs, sort these distances and return value at k-1 index (zero-based array).

**Analysis**:

For each iteration, we select a pair so number of pairs is nC2 = n*(n-1)/2, so the space complexity is O(n^2).

We have two loops with time complexity n^2 and one sort call with n*(n-1)/2\*log(n*(n-1)/2) so final time complexity is O(n^2log(n^2)).

```python
class Solution:
    def smallestDistancePair(self, nums: List[int], k: int) -> int:
        pds = []
        for i in range(len(nums)-1):
            for j in range(i+1, len(nums)):
               pds.append(abs(nums[i] - nums[j]))
        pds.sort()
        return pds[k-1]
```
```
TLE (as expected :D)
```
### Binary Search
**How**:

Based on the description, we don't look for specific pair that produce k-th smallest distance, but we look for the k-th smallest distance itself. This seems similar to binary search. 

We look for k-th smallest distance so the search range which is not the list of given numbers but it is a range from 0 to max(nums) - min(nums), and it is sorted natually, this is satisfied binary search characteristics: in sorted array, looking for k-th number.

Follow binary search, we need to find `mid` and decide to go left or right.

The decision to go left or right based on which side contains k-th smallest distance(by counting number of pairs that have distance less than or equal `mid`, or greater than `mid` value)

Example

```
nums = [1,3,6,7,12]
k = 2
range: 0 -> max(nums) - min(nums) = 12 - 1 = 11

1st iteration (left = 0, right = 11):
		mid = 5
		number of pairs have distance less than or equal 5: 6
		k-th smallest distance on the left side: right = mid
2nd iteration (left = 0, right = 5)
		mid = 2
		number of items have distance less than or equal 2: 2
		k-th smallest distance on the left side: right = mid
3rd iteration (left = 0, right = 2):
		mid = 1
		number of items have distance less than or equal 1: 1
		k-th smallest distance on the right side: left = mid + 1
4th iteration (left = 2, right = 2):
		left == right => return left
```

**Analysis**

`count` function contains two nested loops so overall running time is O(n^2). Binary search take logn iterations, so overall time complexity is O(n^2logn).

Space complexity is O(1).


```python
class Solution:
    def smallestDistancePair(self, nums: List[int], k: int) -> int:
        def count(distance):
            c = 0
            for i in range(len(nums)-1):
                for j in range(i+1, len(nums)):
                    if abs(nums[i] - nums[j]) <= distance:
                        c += 1
            return c
        
        left, right = 0, max(nums)
        while left < right:
            mid = left + (right - left) // 2
            # if number of distances greater than or equal k then search on left side
            if count(mid) >= k:
                right = mid
            else:
                left = mid + 1
        return left
```

```
TLE (welcome to Python :D)
```

### Binary Search Improvement
We can not reduce Binary Search further, bottleneck here is `count` function still O(n^2), we need to work on this one.

Notice that we need to count number of pairs that have distance less than a target distance. If the array is sorted, counting this number is faster using a running index, stops right away when pair's distance > target distance.

When the next number come in, it can re-use this running index and move forward without starting from beginning again since `nums[next_number] >= nums[current_number]`.

**Analysis**

This analysis for time complexity involve armotized running time because inner loop only run n time in total, time complexity is O(n) for `count` function, which is O(nlogn) in total for this algorithm.

Space complexity is O(1).


```python
class Solution:
    def smallestDistancePair(self, nums: List[int], k: int) -> int:
        nums.sort()
        
        def count(distance):
            c = 0
            j = 1
            for i in range(len(nums)-1):
                # look for index j where all values in nums[j+1:] have distances with nums[i] > distance  
                while j < len(nums) and nums[j] - nums[i] <= distance:
                    j += 1
                c += j - i - 1
            return c
        
        left, right = 0, nums[-1] - nums[0]
        while left < right:
            mid = left + (right - left) // 2
            # if number of distances greater than or equal k then search on left side
            if count(mid) >= k:
                right = mid
            else:
                left = mid + 1
        return left
```
```
19 / 19 test cases passed.
Status: Accepted
Runtime: 160 ms
Memory Usage: 15.1 MB
```
