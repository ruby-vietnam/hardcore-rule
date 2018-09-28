##Problem 1:
# Given two sorted integer arrays nums1 and nums2, merge nums2 into nums1 as one sorted array.
# Ruby

# @param {Integer[]} nums1
# @param {Integer} m
# @param {Integer[]} nums2
# @param {Integer} n
# @return {Void} Do not return anything, modify nums1 in-place instead.
def merge(nums1, m, nums2, n)
  pos1 = 0
  pos2 = 0
  (m..(m+n-1)).each do |i|
    while nums1[pos1] <= nums2[pos2] do
      break if pos1 > i-1
      nums1[i+1-pos1] = nums1[i-pos1]
      pos1 += 1
      break if pos1 > i-1
    end
    pos1 > (i-1) ? nums1[pos1] = nums2[pos2] : nums1[i-pos1] = nums2[pos2]
    pos2 += 1
  end
  nums1.first(m+n)
end
