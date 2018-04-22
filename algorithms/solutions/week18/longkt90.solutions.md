# Problem 1
Status:   ✔ Accepted
Approach: use 1 stack but store the value x, and the min of stack

```ruby
class MinStack
  attr_reader :min,
              :stack
  def initialize
    @stack = []
  end

  def push(element)
    @min = element if min.nil? || min > element
    stack.push(element)
    stack.push(min)
  end

  def pop
    stack.pop
    stack.pop
    @min = get_min
  end

  def top
    stack.last(2).first
  end

  def get_min
    stack.last
  end
end
```
