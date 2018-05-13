## Problem 1

https://leetcode.com/problems/valid-anagram/description/

```ruby
# @param {String} s
# @param {String} t
# @return {Boolean}
def is_anagram(s, t)
    hash_s = Hash.new { |hash, key| hash[key] = 0 }
    hash_t = Hash.new { |hash, key| hash[key] = 0 }
    s.each_char { |c| hash_s[c] += 1}
    t.each_char { |c| hash_t[c] += 1}
    hash_s.keys.length == hash_t.keys.length && 
        hash_s.keys.all? { |key| hash_s[key] == hash_t[key] }
end
```

## Problem 2

https://leetcode.com/problems/encode-and-decode-tinyurl/description/

(Sorry, I'm lazy)

```
# Encodes a URL to a shortened URL.
#
# @param {string} longUrl
# @return {string}
def encode(longUrl)
    longUrl
end

# Decodes a shortened URL to its original URL.
#
# @param {string} shortUrl
# @return {string}
def decode(shortUrl)
    shortUrl
end


# Your functions will be called as such:
# decode(encode(url))
```


## Problem 3

https://leetcode.com/submissions/detail/130896863/

```ruby
#
# [23] Merge k Sorted Lists
#
# https://leetcode.com/problems/merge-k-sorted-lists
#
# algorithms
# Hard (27.76%)
# Total Accepted:    186.3K
# Total Submissions: 671.1K
# Testcase Example:  '[]'
#
#
# Merge k sorted linked lists and return it as one sorted list. Analyze and
# describe its complexity.
#
#
# Definition for singly-linked list.
# class ListNode
#     attr_accessor :val, :next
#     def initialize(val)
#         @val = val
#         @next = nil
#     end
# end

class Heap
  def initialize
    @storage = []
    @length = 0
  end

  def pop
    return nil if @length <= 0
    swap(0, @length - 1)
    @length -= 1
    heap_down(0)
    @storage[@length]
  end

  def push(node)
    @length += 1
    @storage[@length - 1] = node
    heap_up(@length - 1)
  end

  def heap_down(position)
    while position < @length
      min_pos = find_min_pos(position, position * 2 + 1, position * 2 + 2)
      return if min_pos == position
      swap(position, min_pos)
      position = min_pos
    end
  end

  def heap_up(position)
    while position > 0
      parent = (position - 1) / 2
      return if parent < 0 || @storage[parent].val <= @storage[position].val
      swap(parent, position)
      position = parent
    end
  end

  def find_min_pos(a, b, c)
    min = a
    min = b if b < @length && @storage[b].val < @storage[min].val
    min = c if c < @length && @storage[c].val < @storage[min].val
    min
  end

  def swap(a, b)
    tmp = @storage[a]
    @storage[a] = @storage[b]
    @storage[b] = tmp
  end
end

# @param {ListNode[]} lists
# @return {ListNode}
def merge_k_lists(lists)
  heap = Heap.new
  lists.each do |head|
    heap.push(head) if head
  end

  final_head = nil
  final_tail = nil

  loop do
    node = heap.pop
    break if node.nil?
    heap.push(node.next) if node.next

    if final_tail.nil?
      final_head = final_tail = ListNode.new(node.val)
    else
      new_node = ListNode.new(node.val)
      final_tail.next = new_node
      final_tail = new_node
    end
  end
  final_head
end
```

## Problem Bonus

https://leetcode.com/problems/serialize-and-deserialize-binary-tree/description/

```ruby
# Definition for a binary tree node.
# class TreeNode
#     attr_accessor :val, :left, :right
#     def initialize(val)
#         @val = val
#         @left, @right = nil, nil
#     end
# end

# Encodes a tree to a single string.
#
# @param {TreeNode} root
# @return {string}
def serialize(root)
    data = []
    queue = [root]
    loop do
        break if queue.length == 0
        node = queue.shift
        if node.nil?
            data << 'null'
        else
            data << node.val
            queue << node.left
            queue << node.right
        end
    end
    data.pop while data.last == 'null'
    data
end

# Decodes your encoded data to tree.
#
# @param {string} data
# @return {TreeNode}
def deserialize(data, i = 0)
    if i < data.length
        root = TreeNode.new(data[i])
        root.left = deserialize(data, i * 2 + 1)
        root.right = deserialize(data, i * 2 + 2)
        root
    else
        nil
    end
end


# Your functions will be called as such:
# deserialize(serialize(data))
```
