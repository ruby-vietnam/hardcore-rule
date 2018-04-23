# Problem 1: [Min stack](https://leetcode.com/problems/min-stack/description/)

```python
class MinStack:
    def __init__(self):
        """
        initialize your data structure here.
        """
        self.min_index = []
        self.elements = []

    def push(self, x):
        """
        :type x: int
        :rtype: void
        """
        self.elements.append(x)
        if not self.min_index or self.elements[-1] < self.elements[self.min_index[-1]]:
            self.min_index.append(len(self.elements) - 1)

    def pop(self):
        """
        :rtype: void
        """
        if not self.elements:
            return
        if self.min_index[-1] == len(self.elements) - 1:
            self.min_index.pop()
        self.elements.pop()

    def top(self):
        """
        :rtype: int
        """
        if not self.elements:
            return -1
        return self.elements[-1]

    def getMin(self):
        """
        :rtype: int
        """
        if not self.elements:
            return -1
        return self.elements[self.min_index[-1]]
``
