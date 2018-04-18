# Problem 1: Min Stack

https://leetcode.com/problems/min-stack/description/

- Tạo 1 stack bình thường để lưu stack(`@stack`), 1 stack khác để lưu min(`@min`).
- Ý tưởng về stack `@min` là: Giá trị của phần trên luôn luôn bé hơn hoặc bằng giá trị của phần dưới, giông như cái tháp vậy.
  + Cách lưu stack min:
    + Nếu stack rỗng và sau khi push x vào stack thì x hiển nhiên là min.
    + Sau một thời gian push các giá trị vào stack thì ta gặp y với y <= x thì sẽ push y vào stack `@min`.
    + Nếu `@stack` pop giá trị là min ra khỏi `@stack` thì `@min` cũng pop giá trị min đó ra khỏi stack `@min`.
  + Cách lấy min của `@stack`: ta chỉ việc lấy top của stack `@min`.

```
Runtime: 52 ms
Your runtime beats 100.00 % of ruby submissions.
```

```ruby
class MinStack

=begin
    initialize your data structure here.
=end
    def initialize()
      @stack = []
      @min = []
    end


=begin
    :type x: Integer
    :rtype: Void
=end
    def push(x)
      @stack.push(x)
      @min.push(x) if @min.length.zero? || @min.last >= x
    end


=begin
    :rtype: Void
=end
    def pop()
      x = @stack.pop
      @min.pop if @min.last == x
    end


=begin
    :rtype: Integer
=end
    def top()
      @stack.last
    end


=begin
    :rtype: Integer
=end
    def get_min()
      @min.last
    end
end
  ```
  
