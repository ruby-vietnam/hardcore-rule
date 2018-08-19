## Problem 1
https://leetcode.com/problems/middle-of-the-linked-list/description/

```
# Definition for singly-linked list.
# class ListNode
#     attr_accessor :val, :next
#     def initialize(val)
#         @val = val
#         @next = nil
#     end
# end

# @param {ListNode} head
# @return {ListNode}
def middle_node(head)
    slow = head
    fast = head
    while fast && fast.next do
        slow = slow.next
        fast = fast.next.next
    end
    slow
end
```
