# 234. Palindrome Linked List

Approach: convert into an array. Sorry, I'm lazy.

```
def is_palindrome(head)
    array = []
    array << head.val and head = head.next until head.nil?
    (0..(array.length / 2)).all? { |i| array[i] == array[array.length - i - 1]}
end
```

```
Runtime: 324 ms, faster than 71.03% of Ruby online submissions for Palindrome Linked List.
Memory Usage: 221.5 MB, less than 60.69% of Ruby online submissions for Palindrome Linked List.
```

# 46. Permutations

Approach: maintain an result array and a flag hash. Recursively loop through 1
-> n, add not flagged number into the result array and continue to next
iteration.

```ruby
# @param {Integer[]} nums
# @return {Integer[][]}

def do_permute(current, hash, result)
    if current.length >= hash.length
        result << current.dup
    else
        hash.keys.each do |num|
            next if hash[num]

            hash[num] = true
            current.push(num)

            do_permute(current, hash, result)

            current.pop
            hash[num] = false
        end
    end
end

def permute(nums)
    flags = nums.sort.each_with_object({}) do |num, hash|
        hash[num] = false
    end
    current = []
    result = []
    do_permute(current, flags, result)
    result
end
```

```
Runtime: 60 ms, faster than 77.78% of Ruby online submissions for Permutations.
Memory Usage: 210.3 MB, less than 20.56% of Ruby online submissions for Permutations.
```
