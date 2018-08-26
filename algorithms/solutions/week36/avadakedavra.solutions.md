## Problem 1
# Source: https://kipalog.com/posts/Ban-ve-phuong-phap-toi-uu-tinh-tong-cac-so-Fibonacci
require 'bigdecimal'
require 'bigdecimal/util'
def climb_stairs(n)
  (((1.0.to_d + 5 ** 0.5) ** (n + 1) - (1.0 - 5 ** 0.5) ** (n + 1)) / ((2.0 ** (n + 1)) * 5 ** 0.5)).round
end
