
```python
# Definition for singly-linked list.
class ListNode(object):
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution(object):
    def getIntersectionNode(self, headA, headB):
        if headA is None or headB is None:
            return None
        data = set([])
        prevA = headA
        if prevA is not None :
            data.add(prevA.val)
        else :
            return None
        while prevA.next != None:
            prevA = prevA.next
            data.add(prevA.val)


        prevB = headB
        if prevB is None:
            return None

        if prevB.val in data:
            return prevB
        while prevB.next != None:
            if (prevB.val in data):
                return prevB
            prevB = prevB.next
        return None
```
