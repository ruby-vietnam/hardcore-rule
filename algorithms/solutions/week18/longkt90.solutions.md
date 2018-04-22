# Problem 1
Status:   ✘ Wrong Answer ✘ 13/18 cases passed (N/A)
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
  end

  def top
    stack.last(2).first
  end

  def get_min
    stack.last
  end
end
```
