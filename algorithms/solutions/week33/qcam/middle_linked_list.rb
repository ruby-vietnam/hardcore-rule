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
  node_count = count(head)
  middle_position = ((node_count + 1) / 2.0).ceil()
  iterate_to(head, middle_position)
end

def count(head, acc = 0)
  if head.nil?
    acc
  else
    count(head.next, acc + 1)
  end
end

def iterate_to(head, position)
  if index == 1
    position
  else
    iterate_to(head.next, position - 1)
  end
end
