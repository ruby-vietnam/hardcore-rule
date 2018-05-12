# Problem 1: Valid Anagram

https://leetcode.com/problems/valid-anagram/description/

```
Runtime: 64 ms
Your runtime beats 100.00 % of ruby submissions.
```

```ruby
# @param {String} s
# @param {String} t
# @return {Boolean}
def is_anagram(s, t)
  arr_s = Array.new(26, 0)
  arr_t = Array.new(26, 0)
  s.each_char do |c|
    arr_s[c.ord - 97] += 1
  end
  t.each_char do |c|
    arr_t[c.ord - 97] += 1
  end
  arr_s == arr_t
end
```

# Problem 3: Merge k Sorted Lists

```
Runtime: 80 ms
Your runtime beats 52.78 % of ruby submissions.
```

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
  lists = lists.select { |list| list }
  return [] if lists.length.zero?
  (lists.length / 2 - 1).downto(0) do |i|
    make_piece_of_heap(lists, i)
  end
  head = tail = lists[0]
  lists[0] = lists[0].next
  while lists.length > 1
    unless lists[0]
      lists[0] = lists[-1]
      lists.pop
    end
    make_piece_of_heap(lists, 0)
    tail.next = lists[0]
    tail = tail.next
    lists[0] = lists[0].next
  end
  tail.next = lists[0]
  head
end

def make_piece_of_heap(lists, index)
  node_len = lists.length / 2
  while index < node_len
    new_index = index * 2 + 1
    if lists[new_index.next] && lists[new_index].val > lists[new_index.next].val
      new_index = new_index.next
    end
    if lists[index].val > lists[new_index].val
      lists[index], lists[new_index] = lists[new_index], lists[index]
      index = new_index
    else
      return
    end
  end
end
```
