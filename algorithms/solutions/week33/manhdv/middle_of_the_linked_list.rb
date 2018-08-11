# https://leetcode.com/problems/middle-of-the-linked-list/

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
  one_step_move_start = head
  two_step_move_start = head

  loop do
    break if two_step_move_start&.next.nil?
    two_step_move_start = two_step_move_start.next&.next
    one_step_move_start = one_step_move_start.next
  end

  one_step_move_start
end