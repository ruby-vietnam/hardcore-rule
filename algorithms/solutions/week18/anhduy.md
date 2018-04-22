# 155

```ruby
class MinStack

=begin
    initialize your data structure here.
=end
    def initialize()
      @arr = []
      @min = 18446744073709551616
    end


=begin
    :type x: Integer
    :rtype: Void
=end
    def push(x)
      if x <= @min
        @min = x
      end
      @arr << {value: x, min: @min}
    end


=begin
    :rtype: Void
=end
    def pop()
      value = @arr[-1]
      @arr = @arr[0..-2]
      if @arr.length == 0
        @min = 18446744073709551616
      else
        @min = @arr[-1][:min]
      end
      value[:value]
    end


=begin
    :rtype: Integer
=end
    def top()
      @arr[-1][:value]
    end


=begin
    :rtype: Integer
=end
    def get_min()
      @arr[-1][:min]
    end


end
```
