## Problem 1

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
  count = 0
  mid = head
  node = head
  until node.nil? do
    count += 1
    if count % 2 == 0 
      mid = mid.next
    end
    node = node.next
  end
  
  output = []
  until mid.nil? do
    output << mid.val
    mid = mid.next
  end
  output
end
```
