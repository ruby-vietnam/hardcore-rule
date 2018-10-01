##Problem 1:
# Given a non-empty array of integers, every element appears twice except for one. Find that single one.
# @param {Integer[]} nums
# @return {Integer}
def single_number(nums)
  res = 0
  nums.each do |i|
    res ^= i
  end
  res
end
