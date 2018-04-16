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

# Problem 3: Trapping Rain Water

https://leetcode.com/problems/trapping-rain-water/description/

```
Runtime: 40 ms
Your runtime beats 100.00 % of ruby submissions.
```

```ruby
# @param {Integer[]} height
# @return {Integer}
def count_water(from, to, height)
  min = height[from] > height[to] ? height[to] : height[from]
  sum = 0
  (from + 1).upto(to - 1) do |i|
    sum += min - height[i] if min > height[i] 
  end
  sum
end
def trap(height)
  peaks = []
  sum = 0
  height.length.times do |i|
    left = i > 0 ? height[i - 1] : 0
    right = i < height.length - 1 ? height[i + 1] : 0
    if height[i] > left && height[i] >= right && height[i] > 0
      peaks.push(i)
    end
  end
  i = 0
  while i < peaks.length - 1
    pivot = nil
    j = i
    while j < peaks.length - 1
      j += 1
      if pivot.nil? || height[peaks[i]] <= height[peaks[j]] || height[peaks[pivot]] < height[peaks[j]]
        pivot = j 
      end
      break if height[peaks[i]] <= height[peaks[j]]
    end
    sum += count_water(peaks[i], peaks[pivot], height)
    i = pivot
  end
  sum
end
```
