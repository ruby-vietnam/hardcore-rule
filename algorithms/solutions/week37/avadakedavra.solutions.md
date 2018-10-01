## Problem 1
# Given an integer, write a function to determine if it is a power of three.
# ruby
# @param {Integer} n
# @return {Boolean}


def is_power_of_three?(n)
  (0..50).each do |i|
    return true if 3**i == n
    return false if n < 3**i
  end
end
