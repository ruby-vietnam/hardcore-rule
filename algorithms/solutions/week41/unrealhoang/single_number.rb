# @param {Integer[]} nums
# @return {Integer}
def single_number(nums)
  t = 0
  nums.each do |num|
    t = t ^ num
  end
  t
end
