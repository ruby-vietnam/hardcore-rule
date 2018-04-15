# Problem 1: Isomorphic Strings

https://leetcode.com/problems/isomorphic-strings/description/

Use hash to binding two together

```
Runtime: 84 ms
Your runtime beats 82.76 % of ruby submissions.
```

```ruby
# @param {String} s
# @param {String} t
# @return {Boolean}
def is_isomorphic(s, t)
  return false if s.length != t.length
  hash_s = {}
  hash_t = {}
  s.length.times do |i|
    hash_s[s[i]] ||= t[i]
    hash_t[t[i]] ||= s[i]
    return false if hash_s[s[i]] != t[i] || hash_t[t[i]] != s[i]
  end
  true
end
```

Problem 2: Rotate List

https://leetcode.com/problems/rotate-list/description/

```
Runtime: 40 ms
Your runtime beats 100.00 % of ruby submissions.
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

# @param {ListNode} head
# @param {Integer} k
# @return {ListNode}
def rotate_right(head, k)
  return [] unless head
  len = 0
  temp = head
  while temp
    len += 1
    temp = temp.next
  end
  k %= len
  return head if k == 0
  temp = head
  tail = head
  (len - 1).times do |i|
    tail = temp if i == len - k - 1
    temp = temp.next
  end
  temp.next = head
  head = tail.next
  tail.next = nil
  head
end
```
