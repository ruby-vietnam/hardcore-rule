# Week 4

## Problem 1
https://leetcode.com/problems/determine-color-of-a-chessboard-square/

### Basic

We can see that there is huge repetition, for example, column a has even row is white and odd row is black, while column b is reversed, even row is black and odd row is white. This pattern is repeated for consequence columns.

By using a hashmap to recoding this rule, we can solve the proble quite easily.

**Analysis**

Time complexity: O(1)
Space complexity: O(1) - only a hashmap with 8 elements, but if we assume n is number of `coordinates[1]` then complexity now is O(n).

```python
class Solution:
    def squareIsWhite(self, coordinates: str) -> bool:
        mem = {
            'a': 1,
            'b': 0,
            'c': 1,
            'd': 0,
            'e': 1,
            'f': 0,
            'g': 1,
            'h': 0
        }
        
        return int(coordinates[1]) % 2 != mem[coordinates[0]]
```
```
203 / 203 test cases passed.
Status: Accepted
Runtime: 24 ms
Memory Usage: 14.3 MB
```

### Convert column to number

To avoid using a hashmap, and still want to keep the rule above, we can convert column to number and use condition to return correct answers.

```python
class Solution:
    def squareIsWhite(self, coordinates: str) -> bool:
        # convert column to number, start with 0
        col = ord(coordinates[0]) - ord('a')
        
        row = int(coordinates[1])
        if col % 2 == 0:
            return row % 2 != 1
        return row % 2 != 0
```
```
203 / 203 test cases passed.
Status: Accepted
Runtime: 32 ms
Memory Usage: 14.3 MB
```

This approach take a bit longer to run.

## Convert column to number version 2

Notice that if we convert column to number, start with 1, then if column + row is even then that slot is black, otherwise, it is white.

```python
class Solution:
    def squareIsWhite(self, coordinates: str) -> bool:
        # convert column to number, start with 1
        col = ord(coordinates[0]) - ord('a') + 1
        
        row = int(coordinates[1])
        return (col + row) % 2 != 0
```
```
203 / 203 test cases passed.
Status: Accepted
Runtime: 32 ms
Memory Usage: 14.3 MB
```

Still take a bit longer time to run, so first approach seems to be better, verbose, but better.
