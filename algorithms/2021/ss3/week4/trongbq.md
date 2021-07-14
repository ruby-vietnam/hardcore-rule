# 1. Valid Parentheses
https://leetcode.com/problems/valid-parentheses/

Use stack to check valid pair of parentheses.

```python
class Solution:
    def isValid(self, s: str) -> bool:
        mem = {")": "(", "}": "{", "]": "["}
        stack = []
        for c in s:
            if c not in mem:
                stack.append(c)
                continue
                
            # there are no more characters to check
            if len(stack) == 0:
                return False
            
            # check if current character match with top of stack
            if mem[c] != stack[-1]:
                return False
            
            # found a match character
            stack.pop()
            
        return len(stack) == 0
```
```
91 / 91 test cases passed.
Status: Accepted
Runtime: 32 ms
Memory Usage: 14.2 MB
```

Time complexity: O(n)

Space complexity: O(n) for stack and hash


# 2. Generate Parentheses
https://leetcode.com/problems/generate-parentheses

```python
class Solution:
    def generateParenthesis(self, n: int) -> List[str]:
        def generate(nl, nr, s):
                if nl == 0 and nr == 0:
                    result.append(s)
                    return
                
                # we can either append left or right parentheses
                # if we still have remaining left parenthese to spend
                if nl > 0:
                    generate(nl-1, nr, s + "(")
                # we can only use right parentheses when we spent left parentheses (of same pair) before
                if nr > nl:
                    generate(nl, nr-1, s + ")")
                    
        result = []
        generate(n, n, "")
        
        return result
```
```
8 / 8 test cases passed.
Status: Accepted
Runtime: 32 ms
Memory Usage: 14.5 MB
```
