# Problem 1 

## [Middle of the Linked List](https://leetcode.com/problems/middle-of-the-linked-list/description/)

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
    result = head
    while !head.nil? do
        return result if head.next.nil?
        return result.next if head.next.next.nil?
        head = head.next.next
        result = result.next
    end
end
```

