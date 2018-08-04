# Problem 1 : Middle of the Linked List

URL: https://leetcode.com/problems/middle-of-the-linked-list/description/


Status:
```
  ✔ Accepted
```
Codes:
```ruby
def middle_node(head)
  fast = head
  while fast = fast&.next do
    fast = fast.next
    head = head.next
  end
  head
end
```
