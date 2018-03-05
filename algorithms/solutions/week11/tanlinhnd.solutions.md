# Problem 1:

URL: https://leetcode.com/problems/linked-list-cycle/description/

Solution: Floyd's Tortoise and Hare algorithms (https://en.wikipedia.org/wiki/Cycle_detection#Tortoise_and_hare)

![Floyd's Tortoise and Har](https://upload.wikimedia.org/wikipedia/commons/thumb/5/5f/Tortoise_and_hare_algorithm.svg/560px-Tortoise_and_hare_algorithm.svg.png)
```
# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def hasCycle(self, head):
        """
        :type head: ListNode
        :rtype: bool
        """
        fast = slow = head
        while fast is not None and fast.next is not None:
            fast = fast.next.next
            slow = slow.next
            if fast == slow:
                return True
        return False   
```

# Problem 3:

URL: https://leetcode.com/problems/odd-even-linked-list/description/

Solution:

```
# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def oddEvenList(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        if not head or not head.next:
            return head
        odd, even = head, head.next
        evenhead = head.next
        while even and even.next:
            odd.next = odd.next.next
            odd = odd.next
            even.next = even.next.next
            even = even.next
        odd.next = evenhead
        return head
```
