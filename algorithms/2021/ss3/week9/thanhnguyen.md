# 1. (Ease) [1967. Number of Strings That Appear as Substrings in Word](https://leetcode.com/problems/number-of-strings-that-appear-as-substrings-in-word/)
## Approach:
### 1.1 Solution
- Use 1 to represent pattern in word
- Use 0 to represent pattern not in word
- Return the sum is the number of strings appear as substring in word

### 1.2 Code
```python
class Solution:
    def numOfStrings(self, patterns: List[str], word: str) -> int:
        return sum([1 if p in word else 0 for p in patterns])
```

# 2. (Ease) [1961. Check If String Is a Prefix of Array](https://leetcode.com/problems/check-if-string-is-a-prefix-of-array/)
## Approach:
### 2.1 Solution
- Go through the list words and check it join all word from begin to that point equal to s

### 2.2 Code
```python
class Solution:
    def isPrefixString(self, s: str, words: List[str]) -> bool:
        for i, w in enumerate(words):
            if s == ''.join(words[:i+1]):
                return True
        return False

```

# 3. (Medium) [1968. Array With Elements Not Equal to Average of Neighbors](https://leetcode.com/problems/array-with-elements-not-equal-to-average-of-neighbors/)
## Approach:
### 3.1 Solution
- The middle number will not equal to average of neighbors when both neighbors smaller or bigger than the middle.
- So that, we need to put the smallest first, then the biggest and continue with the smaller and the bigger.
- To do so, the list need to be sorted and use 2 pointer as left and right to get the value need to push to the result.

### 3.2 Code
```python
class Solution:
    def rearrangeArray(self, nums: List[int]) -> List[int]:
        nums.sort()
        result = []
        length = len(nums)

        l, r = 0, length - 1

        while len(result) < length:
            result.append(nums[l])
            l += 1

            if l < r:
                result.append(nums[r])
                r -= 1

        return result
```
