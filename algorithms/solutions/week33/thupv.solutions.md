## Problem 1
Link: https://leetcode.com/problems/middle-of-the-linked-list

 * 15 / 15 test cases passed.
 * Status: Accepted

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
    node = head
    middle_node = head
    while !node.nil?
        node = node.next
        return middle_node if node.nil?
        node = node.next
        middle_node = middle_node.next
    end
    middle_node
end
```
