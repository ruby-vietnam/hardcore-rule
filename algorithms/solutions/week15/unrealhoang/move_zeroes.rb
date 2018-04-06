# @param {Integer[]} nums
# @return {Void} Do not return anything, modify nums in-place instead.
def move_zeroes(nums)
  zero_idx = []
  nums.each_with_index do |num, idx|
    if num == 0
      zero_idx << idx
    end
  end
  zero_idx_pointer = 0
  num_count = nums.count - zero_idx.count
  nums.count.times.each do |i|
    nums[i - zero_idx_pointer] = nums[i]
    if i == zero_idx[zero_idx_pointer]
      zero_idx_pointer += 1
    end
    puts nums.join(", ")
  end
  (num_count...nums.count).each do |i|
    nums[i] = 0
  end
  puts nums.join(", ")
end

move_zeroes([0,1,0,3,12])
