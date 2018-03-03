# Problemm 1:  Linked List Cycle

URL: https://leetcode.com/problems/linked-list-cycle/description/

Status;
```
  ✔ Accepted
  ✔ 16/16 cases passed (72 ms)
```

```javascript
var hasCycle = function(head) {
    var fast = head;
    var slow = head;
    while(fast && fast.next && fast.next.next && slow && slow.next) {
      fast = fast.next.next;
      slow = slow.next;
      if(fast === slow)
        return true;
    }
    return false;
};
```

# Problemm 3:

URL: https://leetcode.com/problems/odd-even-linked-list/description/

Status:
```
  ✔ Accepted
  ✔ 70/70 cases passed (48 ms)
```

```ruby
def odd_even_list(head)
    return unless head
    even_list = head.next
    current = head
    t = nil
    odd = true
    while current && current.next do
      t = current.next
      current.next = t.next
      break unless t.next
      odd = !odd
      current = t
    end

    if odd
      current.next = even_list
    else
      t.next = even_list
    end
    head
end

```