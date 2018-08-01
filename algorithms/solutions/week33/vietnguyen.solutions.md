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

