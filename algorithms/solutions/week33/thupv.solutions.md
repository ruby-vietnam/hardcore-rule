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
    count = 0
    while !node.nil?
        count += 1
        node = node.next
        if count == 2
            middle_node = middle_node.next
            count = 0
        end
    end
    middle_node
end
```
