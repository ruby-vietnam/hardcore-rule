#!/usr/bin/env python3.7

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    """
    Problem 1: https://leetcode.com/problems/middle-of-the-linked-list/description/
    """

    def middleNode(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        the_middle = head
        the_last = head
        if head is None:
            return head

        if the_middle.next is None:
            return head

        while the_last is not None and the_last.next is not None:
            the_middle = the_middle.next
            the_last = the_last.next
            if the_last is None:
                break
            the_last = the_last.next
        return the_middle


if __name__ == '__main__':
    print('Solution 1 passed all testcase: https://leetcode.com/problems/middle-of-the-linked-list/description/')