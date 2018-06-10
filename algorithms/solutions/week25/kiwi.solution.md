## Problem 1
```python
from collections import defaultdict
import math
class Solution(object):
    def findWords(self, words):
        data = {1: list('qwertyuio'), 2: list('asdfghjkl'), '3': list('zxcvbnm')}
        keyboard_map = dict()
        for item in list('qwertyuiop'):
            keyboard_map[item] = 1
        for item in list('asdfghjkl'):
            keyboard_map[item] = 2
        for item in list('zxcvbnm'):
            keyboard_map[item] = 3

        combination = 1
        result = []
        for word in words:
            first = 0
            # print('word', word)
            for char in list(word):
                if first == 0:
                    first = keyboard_map[char.lower()]
                elif keyboard_map[char.lower()] != first:
                    first = 5
            # print ('first', first)
            if first == 1 or first == 2 or first == 3:
                result.append(word)
        print('result', result)
        return result
