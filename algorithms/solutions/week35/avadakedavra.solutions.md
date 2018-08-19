## Problem 1: K-based Numbers
## ruby

def k_based_numbers(num, k)
  og_nums = (k - 1) * (k - 1)
  default_num = k - 1
  3..num.to_i do
    temp = og_nums
    og_nums = og_nums * (k - 1) + default_num * (k - 1)
    default_num = temp
  end
  og_nums + default_num
end