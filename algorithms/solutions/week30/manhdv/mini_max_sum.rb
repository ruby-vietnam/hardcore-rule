# https://www.hackerrank.com/challenges/mini-max-sum/problem

#!/bin/ruby

require 'json'
require 'stringio'

# Complete the miniMaxSum function below.
def miniMaxSum(arr)
  min = 10**9 + 1
  max = 0
  sum = 0

  arr.each do |num|
    sum += num
    max = num if num > max
    min = num if num < min
  end

  print sum - max
  print ' '
  print sum - min
end

arr = gets.rstrip.split(' ').map(&:to_i)

miniMaxSum arr
