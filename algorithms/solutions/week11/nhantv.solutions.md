# Problem 1: Linked List Cycle

https://leetcode.com/problems/linked-list-cycle/description/

```
Runtime: 10 ms
Your runtime beats 29.58 % of cpp submissions.
```

- We create 2 points are first point and slow point, if Linked list has cycle they are going to face each other.
- Fast point will move 2 nodes at each step.
- Slow point will move 1 node at each step.

```c++
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
  bool hasCycle(ListNode *head) {
    ListNode *slow, *fast;
    slow = fast = head;
    while(fast && fast->next) {
      fast = fast->next->next;
      slow = slow->next;
      if(fast == slow) {
        return true;
      }
    }
    return false;
  }
};
```

# Problem 3: Odd Even Linked List

https://leetcode.com/problems/odd-even-linked-list/description/

```
Runtime: 44 ms
Your runtime beats 100.00 % of ruby submissions.
```

- We separate the linked list to 2 linked lists, one store odd node and one store even node. Eventually we merge two linked lists.

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
def odd_even_list(head)
  return [] unless head
  tail = head
  head2 = nil
  tail2 = nil
  index = 1
  while tail && tail.next
    if index.odd?
      if tail2
        tail2.next = tail.next
        tail2 = tail2.next
      else
        head2 = tail2 = tail.next
      end
      tail.next = tail.next.next
      tail2.next = nil
    else
      tail = tail.next
    end
    index += 1
  end
  tail.next = head2
  head
end
```
