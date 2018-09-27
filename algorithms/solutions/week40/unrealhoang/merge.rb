def merge(nums1, m, nums2, n)
  i, j = m - 1, n - 1
  k = m + n - 1

  while i >= 0 && j >= 0
    if nums1[i] > nums2[j]
      nums1[k] = nums1[i]
      i -= 1
    else
      nums1[k] = nums2[j]
      j -= 1
    end

    k -= 1
  end

  while j >= 0
    nums1[k] = nums2[j]
    k -= 1
    j -= 1
  end
end
