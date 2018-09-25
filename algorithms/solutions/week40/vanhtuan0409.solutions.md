# Week 40

### Merge sorted array (Easy)

```js
// https://leetcode.com/problems/merge-sorted-array/description/

/**
 * @param {number[]} nums1
 * @param {number} m
 * @param {number[]} nums2
 * @param {number} n
 * @return {void} Do not return anything, modify nums1 in-place instead.
 */
var merge = function(nums1, m, nums2, n) {
  let current1 = m - 1;
  let current2 = n - 1;
  for (let i = m + n - 1; i >= 0; i--) {
    if (getValue(nums1, current1) > getValue(nums2, current2)) {
      nums1[i] = nums1[current1];
      current1--;
    } else {
      nums1[i] = nums2[current2];
      current2--;
    }
  }
};

function getValue(arr, index) {
  return index >= 0 ? arr[index] : Number.MIN_SAFE_INTEGER;
}
```
