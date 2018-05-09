# @param {Integer[]} nums
# @return {Integer}
def maximum_product(nums)
    nums.sort!.reverse!
    [nums[0] * nums[-1] * nums[-2], nums[0] * nums[1] * nums[2]].max
end
