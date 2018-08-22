# Problem 1

```ruby
def get_mid_node(slow_node, fast_node)
    return slow_node if !fast_node || !fast_node.next
    get_mid_node(slow_node.next, fast_node.next.next)
end

def middle_node(head)
    get_mid_node(head, head)
end
```
