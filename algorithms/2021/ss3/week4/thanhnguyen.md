# 1. (Easy) [1. Two Sum](https://leetcode.com/problems/two-sum)
## Approach 1: Brute Force
### 1.1 Solution
- Loop through each element of the list, check if there is a pair with x in the rest of list adding to become target
---
- Time Complexity: O(n^2)
- Space Complexity: O(1)
### 1.2 Code
```
54 / 54 test cases passed.
Status: Accepted
Runtime: 3256 ms
Memory Usage: 14.2 MB
```

```python
class Solution(object):
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        for i, n in enumerate(nums):
            for j, m in enumerate(nums[i+1:]):
                if n + m == target:
                    return [i, i + j + 1]
```

## Approach 2: Two-pass Hash Table
### 1.1 Solution
- Use a hash table to save the number and index we go through, start with empty.
- If there is target - x in the hash then return the value since we find out the pair
- If not have target - x in the hash then save pair(number:index) to the hash
---
- Time Complexity: O(n)
- Space Complexity: O(n)

### 1.2 Code
```
54 / 54 test cases passed.
Status: Accepted
Runtime: 680 ms
Memory Usage: 14.5 MB
```

```python
class Solution(object):
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        look_for = {}

        for i, n in enumerate(nums):
            if target - n in look_for.keys():
                return look_for[target - n], i
            else:
                look_for[n] = i
```

# 2. (Easy) [20. Valid Parentheses](https://leetcode.com/problems/valid-parentheses/)
## Approach 1:
### 1.1 Solution
- if s contain (), [], {} replace them with empty
- continue check s after the trim, until s is "" then return True

Reason:
{ { ( { } ) } }
      |_|

{ { (      ) } }
    |______|

{ {          } }
  |__________|

{                }
|________________|
VALID EXPRESSION!


### 1.1 Code
```python
class Solution(object):
    def isValid(self, s):
        """
        :type s: str
        :rtype: bool
        """
        def validate_s(s):
            condition = "()" in s or "[]" in s or "{}" in s
            if condition:
                if "()" in s:
                    s = s.replace("()", "")
                if "[]" in s:
                    s = s.replace("[]", "")
                if "{}" in s:
                    s = s.replace("{}", "")

                return validate_s(s)

            return s == ""

        return validate_s(s)
```

# 3. (Medium) [22. Generate Parentheses](https://leetcode.com/problems/generate-parentheses/)
## Approach 1: Backtracking(DFS)
### 1.1 Solution
#### Analyst
- Our stack with have length is 2 * n. And value could add to base on some rules:
  - Only start with open parentheses
  - First, if count of open parentheses smaller than n, could adding open parentheses
  - Then, if count of close parentheses smaller than count of open parenthese, could adding close parentheses
  - Until the len of stack equal to 2 * n then adding the result to the list by join the value in stack
- Go backtracking by pop value out and continue recursion within above condition

#### Example: n = 3
open = 0, close = 0, stack = [], results = []

open < n -> add ( -> call time 1 :
    open = 1, close = 0, stack = ["("], results = []
open < n -> add ( -> call time 2:
    open = 2, close = 0, stack = ["(", "("], results = []
open < n -> add ( -> call time 3:
    open = 3, close = 0, stack = ["(", "(", "("], results = []
close < open -> add ) -> call time 4:
    open = 3, close = 1, stack = ["(", "(", "(", ")"], results = []
close < open -> add ) -> call time 5:
    open = 3, close = 2, stack = ["(", "(", "(", ")", ")"], results = []
close < open -> add ) -> call time 6:
    open = 3, close = 3, stack = ["(", "(", "(", ")", ")", ")"], results = []
len(stack) == 3 * 2 -> add results :
    open = 3, close = 3, stack = ["(", "(", "(", ")", ")", ")"], results = ["((()))"]  -> add results

pop value out on close < open in time 6 -> done:
    open = 3, close = 2, stack = ["(", "(", "(", ")", ")"], results = ["((()))"]
pop value out on close < open in time 5 -> done:
    open = 3, close = 1, stack = ["(", "(", "(", ")"], results = ["((()))"]
pop value out on close < open in time 4 -> done:
    open = 3, close = 0, stack = ["(", "(", "("], results = ["((()))"]
pop value out on open < n in time 3(open=2, close=0)
-> continue -> close < open -> add ), mean open=2, close=1 -> call time 7:
    open = 2, close = 1, stack = ["(", "(", ")"], results = ["((()))"]
open < n -> add ( -> call time 8:
    open = 3, close = 1, stack = ["(", "(", ")", "("], results = ["((()))"]
close < open -> add ) -> call time 9:
    open = 3, close = 2, stack = ["(", "(", ")", "(", ")"], results = ["((()))"]
close < open -> add ) -> call time 10:
    open = 3, close = 3, stack = ["(", "(", ")", "(", ")", ")"], results = ["((()))"]
len(stack) == 3 * 2 -> add results :
    open = 3, close = 3, stack = ["(", "(", ")", "(", ")", ")"], results = ["((()))", "(()())"]  -> add results

pop value out on close < open in time 10 -> done:
    open = 3, close = 2, stack = ["(", "(", ")", "(", ")"], results = ["((()))", "(()())"]
pop value out on close < open in time 9 -> done:
    open = 2, close = 2, stack = ["(", "(", ")", "("], results = ["((()))", "(()())"]
pop value out on open < n in time 8, open to 2, close to 1
-> continue -> close < open -> add ), mean open=2, close=2 -> call time 11:
    open = 2, close = 2, stack = ["(", "(", ")", ")"], results = ["((()))", "(()())"]
open < n -> add ( -> call time 12:
    open = 3, close = 2, stack = ["(", "(", ")", ")", "("], results = ["((()))", "(()())"]
close < open -> add ) -> call time 13:
    open = 3, close = 2, stack = ["(", "(", ")", ")", "(", ")"], results = ["((()))", "(()())"]
len(stack) == 3 * 2 -> add results :
    open = 3, close = 3, stack = ["(", "(", ")", ")", "(", ")"], results = ["((()))", "(()())", "(())()"]  -> add results

...
### 1.2 Code

```
8 / 8 test cases passed.
Status: Accepted
Runtime: 36 ms
Memory Usage: 14.6 MB
```

```python
class Solution:
    def generateParenthesis(self, n: int) -> List[str]:
        results = []
        def backtrack(S = [], open = 0, close = 0):
            if len(S) == 2 * n:
                results.append("".join(S))
                return

            if open < n:
                S.append("(")
                backtrack(S, open+1, close)
                S.pop()

            if close < open:
                S.append(")")
                backtrack(S, open, close+1)
                S.pop()

        backtrack()
        return results
```