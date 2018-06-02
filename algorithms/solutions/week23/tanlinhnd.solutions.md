# Problem 1: [Intersection of Two Linked Lists](https://leetcode.com/problems/intersection-of-two-linked-lists/description/)

```python
# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def getIntersectionNode(self, headA, headB):
        """
        :type head1, head1: ListNode
        :rtype: ListNode
        """
        lenA = self.getLength(headA)
        lenB = self.getLength(headB)
        diff = abs(lenA - lenB)
        if lenB > lenA:
            headB = self.move(headB, diff)
        else:
            headA = self.move(headA, diff)
        while True:
            if headA == headB:
                return headA
            else:
                headA = headA.next
                headB = headB.next
            
    def getLength(self, node):
        tmp = 0
        while node:
            node = node.next
            tmp = tmp + 1
        return tmp
    
    def move(self, node, step):
        for i in range(step):
            node = node.next
        return node
```
