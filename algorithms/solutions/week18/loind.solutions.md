# Problem 1:

```ruby
class MinStack
  def initialize()
    @arr = []
    @min = nil
  end

  def push(x)
    @arr.push(x)
    @min = x if @min.nil? || @min > x
  end

  def pop
    @arr.pop
    reset_min
  end

  def top
    @arr.last
  end

  def get_min
    @min
  end

  private

  def reset_min
    @min = @arr[0]
    @arr.each do |e|
    @min = e if @min > e
  end
end
```
