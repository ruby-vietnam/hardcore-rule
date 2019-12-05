## Problem 1 - [Implement Stack using Queues](https://leetcode.com/problems/implement-stack-using-queues/)
```python
class MyStack(object):

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.stack = []

    def push(self, x):
        """
        Push element x onto stack.
        :type x: int
        :rtype: void
        """
        self.stack.append(x)

    def pop(self):
        """
        Removes the element on top of the stack and returns that element.
        :rtype: int
        """
        if self.empty():
            return None
        return self.stack.pop()

    def top(self):
        """
        Get the top element.
        :rtype: int
        """
        if self.empty():
            return None
        return self.stack[-1]

    def empty(self):
        """
        Returns whether the stack is empty.
        :rtype: bool
        """
        return len(self.stack) == 0
```

## Problem 2 - [Minimum Genetic Mutation](https://leetcode.com/problems/minimum-genetic-mutation/)
```python
class Solution(object):
    def minMutation(self, start, end, bank):
        """
        :type start: str
        :type end: str
        :type bank: List[str]
        :rtype: int
        """
        if end not in bank:
            return -1

        def related(gene1, gene2):
            return sum(map(lambda (x, y): x ^ y > 0, zip(map(ord, gene1), map(ord, gene2)))) == 1

        current_queue, new_queue, i = [start], [], 1
        current_bank, new_bank = bank, []
        while len(current_queue) > 0:
            for gene1 in current_queue:
                for gene2 in current_bank:
                    if related(gene1, gene2):
                        if gene2 == end:
                            return i
                        new_queue.append(gene2)
                    else:
                        new_bank.append(gene2)
            current_queue, current_bank, i = new_queue, new_bank, i + 1
            new_queue, new_bank = [], []

        return -1
```

## Problem 3 - [Range Sum Query - Immutable](https://leetcode.com/problems/range-sum-query-immutable/)
```python
class NumArray(object):

    def __init__(self, nums):
        """
        :type nums: List[int]
        """
        self.total, self.n = [], len(nums)
        if len(nums) > 0:
            self.total.append(nums[0])
            for num in nums[1:]:
                self.total.append(self.total[-1] + num)


    def sumRange(self, i, j):
        """
        :type i: int
        :type j: int
        :rtype: int
        """
        if self.n == 0:
            return 0

        ii, jj = max(i, 0), min(j, self.n)
        return self.total[jj] if ii == 0 else self.total[min(j, self.n)] - self.total[max(i - 1, 0)]
```
