# https://leetcode.com/problems/sum-of-square-numbers/description/
#
# @param {Integer} c
# @return {Boolean}
def judge_square_sum(c)
  # a2 + b2 = c
  # => 2ab <= c
  # => a(or b) <= sqrt(c/2)

  sqrt_c_div_2 = Math.sqrt(c / 2).to_i
  0.upto(sqrt_c_div_2) do |candidate_a|
    candidate_b = Math.sqrt(c - candidate_a ** 2)
    return true if candidate_b == candidate_b.to_i
  end

  false
end