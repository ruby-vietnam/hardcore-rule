# https://leetcode.com/problems/house-robber/description/

# # Solution1: Brute force
# def max_sum(index, curr_sum, nums)
#   return curr_sum if index > nums.size
#   [
#     max_sum(index + 2, curr_sum + nums[index + 2].to_i, nums),
#     max_sum(index + 3, curr_sum + nums[index + 3].to_i, nums)
#   ].max
# end

# # @param {Integer[]} nums
# # @return {Integer}
# def rob(nums)
#   [
#     max_sum(0, nums[0].to_i, nums),
#     max_sum(1, nums[1].to_i, nums)
#   ].max
# end

# # Timeout
# puts rob([155,44,52,58,250,225,109,118,211,73,137,96,137,89,174,66,134,26,25,205,23 9,85,146,73,55,6,122,196,128,50,61,230,94,208,46,243,105,81,157,89,205,78,249,203,238,239,217,212,241,242,157,79,133,66,36,165])

# Solution2: DP
# @param {Integer[]} nums
# @return {Integer}
def rob(nums)
  return 0 if (nums.size == 0)
  memo = []
  memo[0] = 0
  memo[1] = nums[0]

  1.upto(nums.size - 1) do |idx|
    memo[idx + 1] = [memo[idx], memo[idx - 1] + nums[idx]].max
  end

  memo[nums.size]
end
