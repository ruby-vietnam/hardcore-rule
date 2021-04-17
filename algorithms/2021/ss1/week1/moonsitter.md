# 234. Palindrome Linked List (Easy)
_Leetcode: https://leetcode.com/problems/palindrome-linked-list/_
## Approach
```python
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def isPalindrome(self, head: ListNode) -> bool:
        slow, fast = head, head
        stack = []
        while (fast is not None) and (fast.next is not None):
            stack.append(slow.val)
            slow = slow.next
            fast = fast.next.next
        if fast is not None:
            slow = slow.next
        while slow is not None:
            if slow.val != stack.pop():
                return False
            slow = slow.next
        return True 
```
## Submission Detail
```
Runtime: 832 ms, faster than 35.41% of Python3 online submissions for Palindrome Linked List.
Memory Usage: 47 MB, less than 50.45% of Python3 online submissions for Palindrome Linked List.
```
