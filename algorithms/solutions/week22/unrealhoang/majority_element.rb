# @param {Integer[]} nums
# @return {Integer}
def majority_element(nums)
    count = {}
    nums.each do |num|
        count[num] ||= 0
        count[num] += 1
    end
    count.max_by { |k, v| v }[0]
end
