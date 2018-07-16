# Solutions

### Problem 1
Link: https://www.hackerrank.com/challenges/mini-max-sum/problem

```python
#!/bin/python3

import os
import sys

# Complete the miniMaxSum function below.
def miniMaxSum(arr):
    min = arr[0]
    max = 0
    sum = 0
    for i in arr:
        if min > i:
            min = i
        if max < i:
            max = i
        sum = sum + i
    print(str(sum - max) + ' ' + str(sum - min))


if __name__ == '__main__':
    arr = list(map(int, input().rstrip().split()))

    miniMaxSum(arr)
```
