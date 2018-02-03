# Problem 1

```ruby
def first_uniq_char(s)
    return -1 if s == ""

    cache = {}

    for i in 0..(s.length - 1)
        char = s[i]
        if cache[char]
            cache[char][:uniq] = false
        else
            cache[char] = {uniq: true, start_at: i}
        end
    end

    cache.select { |k, v| v[:uniq] }.map { |k, v| v[:start_at]}.min || - 1
end
```

# Problem 2

## Recursive

```ruby
def is_symmetric(root)
    return true unless root

    symmetric_pair?(root.left, root.right)
end

def symmetric_pair?(left, right)
    # both of them are nil
    return left == right if left.nil? || right.nil?

    # their values vary
    return false if left.val != right.val

    # they have same values
    symmetric_pair?(left.left, right.right) && symmetric_pair?(left.right, right.left)
end
```

## Iterative

```ruby
def is_symmetric(root)
    return true unless root

    stack = [root.left, root.right]

    while stack.count != 0
        left = stack.pop()
        right = stack.pop()

        if left == nil || right == nil
            return false if left != right
        elsif left.val != right.val
            return false
        else
            if left.left == nil && right.right == nil
                stack.push(left.right, right.left)
            elsif left.right == nil && right.left == nil
                stack.push(left.left, right.right)
            else
                stack.push(left.left, right.right, left.right, right.left)
            end
        end
    end

    return true
end
```

# Problem bonus

```ruby
class Node
  attr_accessor :prev, :next, :value, :key

  def initialize(key, value)
    @key = key
    @value = value
    @next = nil
    @prev = nil
  end
end

class LRUCache
  attr_reader :cache, :head, :tail

  def initialize(capacity)
    @capacity = capacity
    @cache = {}
    @head = nil # least recently used
    @tail = nil # most recently used
    @size = 0
  end

  def put(key, value)
    if @cache.has_key?(key)
      node = cache[key]
      node.value = value
      use_node(node)
      return
    end

    node = Node.new(key, value)

    # eviction
    if @size == @capacity
      least_used = @head
      @cache.delete(least_used.key)
      @head = least_used.next

      if @capacity > 1
        @head.prev = nil
      end

      @size -= 1
    end

    if empty?
      @head = @tail = node
    else
      if @size == 1
        node.prev = @head
        @head.next = node
        @tail = node
      else
        @tail.next = node
        node.prev = @tail
        @tail = node
      end
    end

    @size += 1
    @cache[key] = node
  end

  def get(key)
    return -1 unless @cache.has_key?(key)

    node = @cache[key]
    use_node(node)

    node.value
  end

  private

  def empty?
    @size == 0
  end

  def use_node(node)
    return if node.key == @tail.key

    if node.key == @head.key
      new_head = @head.next
      new_head.prev = nil
      @head = new_head
    else
      # in the middle
      left = node.prev
      right = node.next
      left.next = right
      right.prev = left
    end

    old_tail = @tail
    old_tail.next = node
    node.prev = old_tail
    node.next = nil
    @tail = node
  end
end
```
