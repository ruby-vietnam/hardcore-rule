#!/bin/ruby

require 'json'
require 'stringio'

def miniMaxSum(arr)
    arr = arr.sort()

    # (╯°□°）╯︵ ┻━┻
    print arr[0..3].sum()
    print ' '
    print arr[1..4].sum()
end

arr = gets.rstrip.split(' ').map(&:to_i)

miniMaxSum arr
