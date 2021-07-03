# 1. Happy Number

## 1.1 Problem

https://leetcode.com/problems/happy-number/


## 1.2. Solution 

- Get list digits from number
- Calculate Sum of square of all digits
  - if sum = 1 => is happy number. Stop.
  - if sum <> 1, check the sum with a set of previous sum.
  	- if the sum never appear yet, put it into a set
  	- if the sum appear before => is un-happy number. Stop.

## 1.3. Implement

```python
class Solution:
    def sum_squares(self, n: int) -> int:
        digits = [int(x) for x in str(n)]
        result = 0
        for digit in digits:
            result += pow(digit, 2)
        return result

    def isHappy(self, n: int) -> bool:
        prev_sums = set()
        sum_square = n
        while True:
            sum_square = self.sum_squares(sum_square)
            if sum_square == 1:
                return True
            elif sum_square in prev_sums:
                return False
            prev_sums.add(sum_square)
```

```text

402 / 402 test cases passed.
Status: Accepted
Runtime: 28 ms
Memory Usage: 14.1 MB

```

# 2. Happy String

## 2.1. Problem

https://leetcode.com/problems/the-k-th-lexicographical-string-of-all-happy-strings-of-length-n/

## 2.2. Solution

We have 3 binary tree with (n-1) levels. For given k, we need to find the tree that `k` belong to.
After that, we can use Depth First Search method on the selected tree to find the string.


## 2.3. Implement
```python
class Solution:
    @staticmethod
    def dfs(tree: list[str], n: int, k: int) -> str:
        counter = 0
        while len(tree) > 0:
            node = tree.pop(0)
            if len(node) == n:
                counter += 1
                if counter == k:
                    return node
            else:
                for c in ['a', 'b', 'c']:
                    if c != node[-1]:
                        tree.append(node + c)

        return ""

    def getHappyString(self, n: int, k: int) -> str:
        tree_size = 2**(n-1)
        if k <= tree_size:
            return self.dfs(['a'], n, k)
        elif k <= 2 * tree_size:
            return self.dfs(['b'], n, k - tree_size)
        elif k <= 3 * tree_size:
            return self.dfs(['c'], n, k - 2 * tree_size)
        else:
            return ""

```

Result
```text
345 / 345 test cases passed.
Status: Accepted
Runtime: 60 ms
Memory Usage: 14.3 MB
```