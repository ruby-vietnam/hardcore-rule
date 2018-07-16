```python
#!/bin/python

import math
import os
import random
import re
import sys

if __name__ == '__main__':
    arr = map(int, raw_input().rstrip().split())
    x = sum(arr)
    print (x-(max(arr))), (x-(min(arr)))
```
