## Problem 1

https://leetcode.com/problems/middle-of-the-linked-list/description/

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
    return nil if head.nil?
    len = 0
    
    node = head
    while node != nil
        len += 1
        node = node.next
    end
    
    count = 0
    node = head
    while node != nil
        return node if count == len / 2 
        count += 1
        node = node.next
    end
end
```
