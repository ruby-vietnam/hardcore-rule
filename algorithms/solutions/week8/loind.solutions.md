## Problem 1
Use Trie to solve this problem

```ruby
class Node
  attr_accessor :endword, :data, :children

  def initialize(data)
    @data = data
    @children = {}
    @endword = false
  end

  def insert(char)
    return @children[char] if have?(char)
    child = Node.new(char)
    @children[char] = child
  end

  def have?(char)
    @children[char] && true
  end

  def get(char)
    @children[char]
  end
end

class Trie
  attr_reader :root

  def initialize
    @root = Node.new(nil)
  end

  def insert(word)
    node = @root
    word.each_char do |char|
      child = node.insert(char)
      node = child
    end
    node.endword = true
  end

  def word_included(word)
    count = 0
    node = @root
    word.each_char do |char|
      return 0 if node.data && !node.endword
      count += 1
      node = node.get(char)
    end
    count
  end
end

def build_trie(words)
  trie = Trie.new
  words.each do |word|
    trie.insert(word)
  end
  trie
end

def longest_word(words)
  trie = build_trie(words)

  max = 0
  result = ''
  words.each do |word|
    count = trie.word_included(word)
    if max < count
      max = count
      result = word
    elsif max == count && result > word
      result = word
    end
  end
  result
end
```

