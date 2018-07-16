# Mini-Max Sum

```haskell
{-# LANGUAGE FlexibleInstances, UndecidableInstances, DuplicateRecordFields #-}

module Main where

import Control.Monad
import Data.Array
import Data.Bits
import Data.List
import Data.List.Split
import Data.Set
import Debug.Trace
import System.Environment
import System.IO
import System.IO.Unsafe

-- Complete the miniMaxSum function below.
miniMaxSum :: [Int] -> IO ()
miniMaxSum arr = do
  putStrLn $ (show . sum . init $ sorted) ++ " " ++ (show . sum . tail $ sorted)
  where sorted = sort arr

readMultipleLinesAsStringArray :: Int -> IO [String]
readMultipleLinesAsStringArray 0 = return []
readMultipleLinesAsStringArray n = do
    line <- getLine
    rest <- readMultipleLinesAsStringArray(n - 1)
    return (line : rest)

main :: IO()
main = do
    arrTemp <- getLine

    let arr = Data.List.map (read :: String -> Int) . words $ arrTemp

    miniMaxSum arr
```

# Sparse Arrays

```ruby
#!/bin/ruby

require 'json'
require 'stringio'

class TrieNode
  attr_accessor :value, :end_of_word, :children

  def initialize
    self.children = {}
    self.value = 0
    self.end_of_word = false
  end
end

class Trie
  attr_accessor :root
  
  def insert(key)
    length = key.length
    r = root

    i = 0
    while (i < length) do
      if (!r.children[key[i]])
        new_node = TrieNode.new
        r.children[key[i]] = new_node
      end

      r = r.children[key[i]]
      i += 1
    end

    r.value += 1
    r.end_of_word = true
  end

  def search(key)
    length = key.length
    r = root
    i = 0

    while (i < length && r) do
      r = r.children[key[i]]
      i += 1
    end

    (r && r.end_of_word) ? r.value : 0
  end
end

# Complete the matchingStrings function below.
def matchingStrings(strings, queries)
  trie = Trie.new
  trie.root = TrieNode.new

  strings.each do |s|
    trie.insert(s)
  end

  queries.map do |q|
    trie.search(q)
  end
end


fptr = File.open(ENV['OUTPUT_PATH'], 'w')

strings_count = gets.to_i

strings = Array.new(strings_count)

strings_count.times do |i|
    strings_item = gets.to_s.rstrip
    strings[i] = strings_item
end

queries_count = gets.to_i

queries = Array.new(queries_count)

queries_count.times do |i|
    queries_item = gets.to_s.rstrip
    queries[i] = queries_item
end

res = matchingStrings strings, queries

fptr.write res.join "\n"
fptr.write "\n"

fptr.close()
```