## [Problem 1. Middle of the Linked List](https://leetcode.com/problems/middle-of-the-linked-list/description/)

```python
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def middleNode(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        dummyHead = ListNode(0)
        dummyHead.next = head 
        # two-pointer approach 
        slow = fast = dummyHead 
        while fast.next != None: 
            slow = slow.next 
            fast = fast.next 
            if fast.next == None: 
                return slow 
            fast = fast.next
        return slow.next 
```

## [Problem 2. Scheduling (Shortest Job First or SJF)](https://www.codewars.com/kata/scheduling-shortest-job-first-or-sjf/train/python)

```python 
def SJF(jobs, index):
    #implment Shortest Job First
    # idea: sort the `jobs` array (stable) with original job indexes memorized. 
    jobsSortedWithIndexes = sorted(enumerate(jobs), key=lambda x:x[1])
    res = 0
    for jobWithIndex in jobsSortedWithIndexes:
        res += jobWithIndex[1]
        if jobWithIndex[0] == index:
            break 
    return res 
```

## [Problem 4. Twice Linear](https://www.codewars.com/kata/twice-linear/train/python)

```python 
def dbl_linear(n):
	# your code
    array = [1] 
    count = 0 
    idx2, idx3 = 0, 0
    while len(array) <= n+1: 
        #print(array) 
        if 2 * array[idx2] + 1 < 3 * array[idx3] + 1:
            array.append(2 * array[idx2]+1)
            idx2 += 1 
        elif 2 * array[idx2] + 1 > 3 * array[idx3] + 1:
            array.append(3 * array[idx3]+1)
            idx3 += 1 
        else: 
            idx2 += 1 
            
    return array[n] 
```
