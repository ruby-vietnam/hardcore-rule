## Problem 1

```ruby
def middle_node(head)
  array = []

  while (head)
    array << head
    head = head.next
  end

  array[array.length / 2]
end
```
