## Problem 1

```ruby
class MinStack
  attr_reader :stack, :min_stack

  def initialize
    @stack = []
    @min_stack = []
  end

  def push(x)
    stack.push(x)

    if min_stack.empty? || min_stack.last >= x
      min_stack.push(x)
    end
  end

  def pop
    stack.pop.tap do |x|
      if x == min_stack.last
        min_stack.pop
      end
    end
  end

  def top
    stack.last
  end

  def get_min
    min_stack.last
  end
end
```
