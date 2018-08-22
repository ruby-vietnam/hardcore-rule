# @param {Integer[]} nums
# @return {Integer}
def rob(nums)
    max_rob_i1 = 0
    max_rob_i2 = 0
    nums.count.times do |i|
        if nums[i] + max_rob_i2 > max_rob_i1
            t = nums[i] + max_rob_i2
            max_rob_i2 = max_rob_i1
            max_rob_i1 = t
        else
            max_rob_i2 = max_rob_i1
        end
    end
    max_rob_i1
end
