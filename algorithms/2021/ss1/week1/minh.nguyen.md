# 234. Palindrome Linked List

Approach: convert into an array. Sorry, I'm lazy.

```ruby
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

# 336. Palindrome Pairs

Approach: for each character of each word, assuming that character is a "rotate point". From that character, we spread both left and right, until the whole string is visited. Afterward, we get a "missing combination" that makes the word palindrome. Looking up that missing combination in the map of words, we get the partner word.

```ruby
require 'set'

def palindrome_pairs(words)
    words_map = words.each.with_index.with_object({}) do |(word, index), hash|
        hash[word] = index
    end
    indices = Set.new

    words.each_with_index do |word, word_index|
        word.each_char.with_index do |char, char_index|
            (0..1).each do |adjustment|
                can_form_palindrome = true
                missing_combination = ''
                missing_left = false

                i = char_index - 1
                j = char_index + adjustment
                while i >= 0 || j < word.length
                    if i >= 0 && j < word.length
                        if word[i] != word[j]
                            can_form_palindrome = false
                            break
                        end
                    elsif i < 0
                        missing_left = true
                        missing_combination = word[j] + missing_combination
                    else
                        missing_left = false
                        missing_combination = missing_combination + word[i]
                    end
                    i -= 1
                    j += 1
                end
                if can_form_palindrome && words_map[missing_combination] && words_map[missing_combination] != word_index
                    if missing_left
                        indices << [words_map[missing_combination], word_index]
                        indices << [word_index, words_map[missing_combination]] if missing_combination == ''
                    else
                        indices << [word_index, words_map[missing_combination]]
                        indices << [words_map[missing_combination], word_index] if missing_combination == ''
                    end
                end
            end
        end
    end

    indices.to_a.sort
end
```

```
Runtime: 1224 ms, faster than 20.00% of Ruby online submissions for Palindrome Pairs.
Memory Usage: 211.8 MB, less than 50.00% of Ruby online submissions for Palindrome Pairs.
```
