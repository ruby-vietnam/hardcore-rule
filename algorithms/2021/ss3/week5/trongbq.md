# 1. Excel Sheet Column Title
https://leetcode.com/problems/excel-sheet-column-title/

```python
class Solution:
    def convertToTitle(self, columnNumber: int) -> str:
        N = 26
        
        # create mapping from each integer to alphabet character
        mapping = [None] + [chr(65+i) for i in range(N)]
        
        # converse value to base 26
        s = []
        while columnNumber != 0:
            rem = columnNumber % N
            if rem == 0:
                # handle special case when columnNumber is divisible by N
                # we don't have zero value so we can not have such representation in our base 26 alphabet
                # use mapping[N] as an exceeding value
                s.append(mapping[N])
                columnNumber -= N
            else:
                s.append(mapping[rem])
            columnNumber //= N
        
        s.reverse()
        return "".join(s)
```
```
18 / 18 test cases passed.
Status: Accepted
Runtime: 28 ms
Memory Usage: 14.4 MB
```

# 2. Climbing Stairs
https://leetcode.com/problems/climbing-stairs/

Simple DP with memorization

```python
class Solution:
    def climbStairs(self, n: int) -> int:
        def take(i):
            if i > n:
                return 0
            if i == n:
                return 1
            
            if i in mem:
                return mem[i]
            w = take(i+1) + take(i+2)
            mem[i] = w
            return w
        
        mem = {}
        return take(0)
```

Use iterative approach

```python
class Solution:
    def climbStairs(self, n: int) -> int:
        if n == 1:
            return 1
        
        step_a, step_b = 1, 2
        
        for i in range(3, n+1):
            step_a, step_b = step_b, step_a + step_b
            
        return step_b
```
```
45 / 45 test cases passed.
Status: Accepted
Runtime: 32 ms
Memory Usage: 14.2 MB
```

# 3. House Robber
https://leetcode.com/problems/house-robber/

DP with memorization

```python
class Solution:
    def rob(self, nums: List[int]) -> int:
        def rob(n):
            if n < 0:
                return 0
            
            if n in mem:
                return mem[n]
            
            # either choose to rob previous house and skip current house
            # or rob previous of previous house and current house
            val = max(rob(n-1), rob(n-2) + nums[n])
            mem[n] = val
            return val
        
        mem = {}
        return rob(len(nums)-1)
```

Iterative approach

```python
class Solution:
    def rob(self, nums: List[int]) -> int:
        n = len(nums)
        
        rob_a, rob_b = 0, 0
        for i in range(n):
            rob_a, rob_b = rob_b, max(rob_a + nums[i], rob_b)
            
        return rob_b
```

```
68 / 68 test cases passed.
Status: Accepted
Runtime: 28 ms
Memory Usage: 14.2 MB
```
