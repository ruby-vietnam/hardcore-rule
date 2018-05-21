## Problem 1

```Go
func isAnagram(s string, t string) bool {
    mS := map[rune]int{}
    for _, r := range s{
        v, exists:= mS[r]
        if exists {
            mS[r] = v+1
        }else{
            mS[r] = 1
        }
    }
    
    for _, r := range t {
        v, exists:= mS[r]
        if exists {
            mS[r] = v-1
        }else{
            return false
        }
    }
    
    for _, value := range mS {
        if value > 0 {
            return false
        }
    }
    
    return true
}
```

```Ruby
# @param {String} s
# @param {String} t
# @return {Boolean}
def is_anagram(s, t)
  ms = {}
  s.each_char do |r|
    ms[r] = if ms.key?(r)
              ms[r] + 1
            else
              1
            end
  end

  t.each_char do |r|
    return false unless ms.key?(r)
    ms[r] = ms[r] - 1
  end

  ms.each do |_, value|
    return false if value.positive?
  end

  true
end
```

## Problem 3
Use heap 

```ruby
# Definition for singly-linked list.
# class ListNode
#     attr_accessor :val, :next
#     def initialize(val)
#         @val = val
#         @next = nil
#     end
# end

# @param {ListNode[]} lists
# @return {ListNode}
def merge_k_lists(lists)
     h = Heap.new

  # push all list to heap
  lists.each do |list|
    current_node = list
    until current_node.nil?
      h.push(current_node.val)
      current_node = current_node.next
    end
  end

  return nil if h.empty?

  # pop heap to build new sorted list
  sorted_list = ListNode.new(h.pop)
  current_node = sorted_list

  until h.empty?
    val = h.pop
    new_node = ListNode.new(val)
    current_node.next = new_node
    current_node = current_node.next
  end

  sorted_list

end


# HEAP
class Heap
  attr_accessor :array_rep

  def initialize
    @array_rep ||= []
  end

  def size
    @array_rep.length
  end

  def empty?
    @array_rep.length.zero?
  end

  def push(v)
    @array_rep << v
    up(@array_rep.length - 1)
  end

  def up(i)
    until i.zero?
      parent_index = (i - 1) / 2

      break if parent_index == i
      return unless @array_rep[i] < @array_rep[parent_index]

      swap(i, parent_index)
      i = parent_index
    end
  end

  def down(i)
    until i > @array_rep.length - 1
      break if (i + 1) * 2 - 1 >= @array_rep.length

      min_node_index = (i + 1) * 2 - 1

      min_node_index += 1 if min_node_index + 1 < @array_rep.length &&
                             @array_rep[min_node_index + 1] < @array_rep[min_node_index]
      break if @array_rep[i] <= @array_rep[min_node_index]

      swap(i, min_node_index)
      i = min_node_index
    end
  end

  def pop
    return if empty?

    # get max
    top = @array_rep.first

    n = @array_rep.length

    # swap end node to top
    swap(0, n - 1)

    # remove end node
    @array_rep.pop
    # shift down
    down(0)
    top
  end

  def swap(i, j)
    @array_rep[i], @array_rep[j] = @array_rep[j], @array_rep[i]
  end
end
```

