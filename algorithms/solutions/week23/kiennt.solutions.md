# Problem1

```python
class ListNode(object):
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution(object):
    def len(self, node):
        count = 0
        while node != None:
            count += 1
            node = node.next
        return count

    def move(self, node, step):
        count = 0
        while count < step:
            count += 1
            node = node.next
        return node

    def findIntersectionNode(self, node1, node2):
        if node1 == None or node2 == None:
            return None
        if node1 == node2:
            return node1
        return self.findIntersectionNode(node1.next, node2.next) 

    def getIntersectionNode(self, headA, headB):
        lenA = self.len(headA)
        lenB = self.len(headB)
        if lenA > lenB:
            maxNode, minNode, diff = headA, headB, lenA - lenB
        else:
            maxNode, minNode, diff = headB, headA, lenB - lenA
        maxNode = self.move(maxNode, diff)
        return self.findIntersectionNode(maxNode, minNode)
```