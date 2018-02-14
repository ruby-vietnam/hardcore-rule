# Problem 1

Link: https://leetcode.com/problems/longest-word-in-dictionary/description/

## Solution

### Description

1. Having a cache for word building blocks, e.g `"a"`, `"ap"` are the building
   blocks for `"app"`.
2. For each word of the unique, sorted dictionary, cache it when it is `a-z` or
   it could be built up by previous cached words.

### Code

```
57 / 57 test cases passed.
Status: Accepted
Runtime: 93 ms
Your runtime beats 88.89 % of ruby submissions.
```

```ruby
require "set"

def longest_word(words)
  cache = Set.new
  longest = ""

  words.uniq.sort.each do |word|
    wl = word.length()

    if wl == 1 || cache.include?(word[0..wl-2])
      longest = wl > longest.length ? word : longest
      cache = cache.add(word)
    end
  end

  longest
end
```
