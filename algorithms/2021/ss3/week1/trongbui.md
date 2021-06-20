# Week 1

# Problem 1
https://leetcode.com/problems/toeplitz-matrix/

A key thing to do for this problem is to check if in any certain slot, its value should equal to previous diagonal slot.

```
matrix[i][j] == matrix[i-1][j-1]`
```

This also apply in case when memory is limited. We can even load only two slot into the memory which are `matrix[i][j]` and `matrix[i-1][j-1]` and compare them together then move on to next slot.

![wb-hardcore-week6-problem1](https://user-images.githubusercontent.com/7964573/122669924-9ad27100-d1e9-11eb-86fb-a97de095abcf.png)

```python
class Solution:
    def isToeplitzMatrix(self, matrix: List[List[int]]) -> bool:
        n, m = len(matrix), len(matrix[0])
        
        # compare bottom-left sub-matrix (n-1)(m-1)
        for row in range(1, n):
            for col in range(1, m):
                if matrix[row][col] != matrix[row-1][col-1]:
                    return False
        
        return True
```
```
483 / 483 test cases passed.
Status: Accepted
Runtime: 80 ms
Memory Usage: 14.3 MB
```

Time complexity is O(nm) which is best possible complexity we can have.

Space complexity: O(1).
