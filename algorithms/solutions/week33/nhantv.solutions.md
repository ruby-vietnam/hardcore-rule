# Problem 1: Middle of the Linked List

https://leetcode.com/problems/middle-of-the-linked-list/description/

```
Runtime: 48 ms
Your runtime beats 42.86 % of ruby submissions.
```

```ruby
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
  mid = head
  while head.next && head.next.next
    head = head.next.next
    mid = mid.next
  end
  head.next ? mid.next : mid
end
```
