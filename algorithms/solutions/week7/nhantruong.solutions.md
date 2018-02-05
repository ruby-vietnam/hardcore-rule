# Problem 1: First Unique Character in a String
https://leetcode.com/problems/first-unique-character-in-a-string/description/

```
Runtime: 257 ms
Your runtime beats 87.50 % of ruby submissions.
```

```ruby
# @param {String} s
# @return {Integer}
def first_uniq_char(s)
  hash = {}
  s.each_byte do |c|
    hash[c] ||= 0
    hash[c] += 1
  end
  s.each_byte.with_index do |c, index|
    return index if hash[c] == 1
  end
  -1
end
```

# Problem 2: Symmetric Tree
https://leetcode.com/problems/symmetric-tree/

```
Runtime: 2520 ms
Your runtime beats 0 % of ruby submissions. T_T
```

```ruby
# Definition for a binary tree node.
# class TreeNode
#     attr_accessor :val, :left, :right
#     def initialize(val)
#         @val = val
#         @left, @right = nil, nil
#     end
# end

# @param {TreeNode} root
# @return {Boolean}
def is_symmetric(root)
  return true if root.nil?
  nodes = [root]
  while true 
    tam = []
    done = true
    nodes.each do |node|
      if node
        left = node.left
        right = node.right
        done = false
      else
        left = nil
        right = nil
      end
      tam.push(left)
      tam.push(right)
    end
    nodes = tam
    break if done
    return false unless is_symmetric_array(nodes)
  end
  return true
end

def is_symmetric_array(array)
  len = array.length
  (len/2).times do |i|
    left = array[i].val if array[i]
    right = array[len - i - 1].val if array[len - i - 1]
    return false if left != right
  end
  return true
end
```

# Problem 3: Candy
https://leetcode.com/problems/candy

```
Runtime: 95 ms
Your runtime beats 100.00 % of ruby submissions.
```
_Will update ideas on Monday 😅_

```ruby
# @param {Integer[]} ratings
# @return {Integer}
def sum_list(n)
    (n * (n+1)) / 2
end
def candy(ratings)
  total_candy = 0
  sign_array = []
  sign_index = 0
  negative_flag = true
  not_equal_flag = true
  ratings.each.with_index do |value, index|
    if index == 0
      sign_array[sign_index] = 1
    elsif ratings[index] > ratings[index - 1]
      if negative_flag
        total_candy -= 1
        sign_index += 1
        sign_array[sign_index] = 1
        negative_flag = false
        not_equal_flag = true
      end
      sign_array[sign_index] += 1
    elsif ratings[index] < ratings[index - 1]
      unless negative_flag
        sign_index += 1
        sign_array[sign_index] = 0
        negative_flag = true
        not_equal_flag = true
      end
      sign_array[sign_index] += 1
      total_candy += 1 if sign_array[sign_index] >= sign_array[sign_index - 1] && sign_index > 0 && not_equal_flag
    else
      sign_index += 1
      sign_array[sign_index] = 1
      not_equal_flag = false
    end
  end
  sign_array.each.with_index do |value, index|
    total_candy += sum_list(value)
  end
  total_candy
end
```

# Bonus 2: Insert Delete GetRandom O(1)
https://leetcode.com/problems/insert-delete-getrandom-o1/description/

```
Runtime: 111 ms
Your runtime beats 83.33 % of ruby submissions.
```

```ruby
class RandomizedSet

=begin
    Initialize your data structure here.
=end
    def initialize()
      @hash = {}
      @array = []
    end


=begin
    Inserts a value to the set. Returns true if the set did not already contain the specified element.
    :type val: Integer
    :rtype: Boolean
=end
    def insert(val)
      return false if @hash[val]
      @array.push(val)
      @hash[val] = @array.length - 1
      true
    end


=begin
    Removes a value from the set. Returns true if the set contained the specified element.
    :type val: Integer
    :rtype: Boolean
=end
    def remove(val)
      return false unless @hash[val]
      index = @hash[val]
      arr_len = @array.length - 1
      @array[index] = @array[arr_len]
      @hash[@array[index]] = index
      @hash.delete(val)
      @array.pop
      true
    end


=begin
    Get a random element from the set.
    :rtype: Integer
=end
    def get_random()
      @array[rand(@array.length)]
    end


end

# Your RandomizedSet object will be instantiated and called as such:
# obj = RandomizedSet.new()
# param_1 = obj.insert(val)
# param_2 = obj.remove(val)
# param_3 = obj.get_random()
```
