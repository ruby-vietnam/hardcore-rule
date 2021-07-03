# 1. Happy Number
https://leetcode.com/problems/happy-number/

Use a map to store numberr we used to process to detect cycle loop.

```python
class Solution:
    def isHappy(self, n: int) -> bool:
        mem = {}
        while True:
            # store memory about processing this value to detect cycle loop
            mem[n] = True
            s = 0
            while n != 0:
                s += (n % 10) ** 2
                n = n // 10
                
            # replace n
            n = s
            
            # check if the number is 1
            if n == 1:
                return True
            
            # check if loop endlessly
            if n in mem:
                return False
            
            # otherwise, keep looping
```
```
402 / 402 test cases passed.
Status: Accepted
Runtime: 36 ms
Memory Usage: 14.4 MB
```

It's hard to detect time and space complexity, the program either terminated by founding the number 1 or loop endlessly detected, in both case, we don't simply know exactly how much loop we need to run before terminating.

# 2. Longest Happy String
https://leetcode.com/problems/longest-happy-string/

Using greedy algorithm to always selecting most occurrences character to append to string `s` if possible, 
otherwise select the second most occurrences character.

Data structure needs to support selecting most and second most occurrence and also map 1-1 beween character and occurrence. 
For simplicity, I use a list of tuple and sorting for this, we can use heap as well.

```python
class Solution:
    def longestDiverseString(self, a: int, b: int, c: int) -> str:
        arr = [('a', a), ('b', b), ('c', c)]
        
        s = ""
        while True:
            # sort by occurrences
            arr.sort(key=lambda x: x[1], reverse=True)
            
            # get most occurrences character and check if it is valid to append to s
            ch, occ = arr[0]
            if occ != 0 and (len(s) < 2 or s[-1] != ch or s[-2] != ch):
                s += ch
                arr[0] = (ch, occ-1)
            else:
                # get second most occurrences and append to s
                ch, occ = arr[1]
                if arr[1][1] != 0:
                    s += ch
                    arr[1] = (ch, occ-1)
                else:
                    # can not found new valid character, stop
                    break
            
        return s
```
```
33 / 33 test cases passed.
Status: Accepted
Runtime: 28 ms
Memory Usage: 14.4 MB
```

Time complexity: inside each loop we use sort function but it actually fast due to sorting array of 3 items, not depends on input, so total time spending is O(a+b+c).

Space complexity: O(1)
