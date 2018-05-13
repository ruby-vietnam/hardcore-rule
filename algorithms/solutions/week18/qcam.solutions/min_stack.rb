class Stack
  def initialize()
    @items = []
    @size = 0
  end

  def push(item)
    @items[size()] = item
    @size = size() + 1
  end

  def pop()
    if empty?()
      raise "failed to pop stack, stack is empty"
    else
      item = items()[size() - 1]
      @items.delete_at(size() - 1)
      @size = size() - 1

      return item
    end
  end

  def top()
    return nil if empty?()

    items()[size() - 1]
  end

  private

  attr_reader :size, :items

  def empty?()
    size() == 0
  end
end

class MinStack
  def initialize()
    @actual_stack = Stack.new()
    @min_stack = Stack.new()
  end

  def push(item)
    @actual_stack.push(item)

    min = min_stack().top()

    if min.nil?() || min >= item
      @min_stack.push(item)
    end
  end

  def pop()
    item = @actual_stack.pop()

    if item == min_stack().top()
      @min_stack.pop()
    end

    return item
  end

  def top()
    actual_stack().top()
  end

  def get_min()
    min_stack().top()
  end

  private

  attr_reader :min_stack, :actual_stack
end
