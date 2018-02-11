# Problem 1: Longest Word in Dictionary

https://leetcode.com/submissions/detail/140428475/

Use Trie + DFS
```
Runtime: 428 ms
Your runtime beats 29.63 % of ruby submissions.
```
```ruby
# @param {String[]} words
# @return {String}
class TrieNode
  attr_accessor :is_word, :next 
  def initialize
    @is_word = false
    @next = {}
  end
end
def build_trie(words)
  trie = {}
  words.each do |word|
    next if word == ""
    root = trie
    node = nil
    (0...word.length).each do |i|
      if root[word[i]]
        node = root[word[i]]
      else
        node = TrieNode.new
        root[word[i]] = node
      end
      root = node.next
    end
    node.is_word = true   
  end
  trie
end
def find_longest_word(trie)
  longest_word = ""
  trie.each do |key, value|
    next unless value.is_word
    word = key + find_longest_word(value.next)

    length_longest_word = longest_word.length
    length_word = word.length
    first_condition = length_word > length_longest_word
    second_condition = word < longest_word && length_word == length_longest_word
    longest_word = word if first_condition || second_condition
  end
  longest_word
end
def longest_word(words)
  return "" if words == nil || words == []
  trie = build_trie(words)
  find_longest_word(trie)
end
```
