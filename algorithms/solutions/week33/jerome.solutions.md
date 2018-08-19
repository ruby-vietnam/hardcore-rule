## Problem 1 (https://leetcode.com/problems/middle-of-the-linked-list/description/)
```ruby
# Definition for singly-linked list.
# class ListNode
#   attr_accessor :val, :next
#   def initialize(val)
#       @val = val
#       @next = nil
#   end
# end

# @param {ListNode} head
# @return {ListNode}

def middle_node(head)
  count = 0
  mid = head

  while head
    count += 1
    mid = mid.next if count.even?
    head = head.next
  end

  mid
end

```
