# @param {Integer[]} nums
# @param {Integer} k
# @return {Boolean}
def contains_nearby_duplicate(nums, k)
  num_idx = {}
  nums.each_with_index do |num, idx|
    if num_idx[num]
      if idx - num_idx[num] <= k
        return true
      end
    end
    num_idx[num] = idx
  end
  return false
end
