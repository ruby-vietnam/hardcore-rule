## Problem 1

```ruby
class MyStack
  def initialize
    @data = []
  end

  def push(x)
    data.push(x)
  end

  def pop
    new_data = []

    while data.size > 1
      item = data.shift
      new_data.push(item)
    end

    data.shift.tap do
      @data = new_data
    end
  end

  def top
    new_data = []

    while data.size >= 1
      item = data.shift
      new_data.push(item)
    end

    @data = new_data
    item
  end

  def empty
    data.empty?
  end

  private

  attr_reader :data
end
```
