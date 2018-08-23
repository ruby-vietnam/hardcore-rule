## Problem 1

```javascript
/**
 * Problem: https://leetcode.com/problems/house-robber
 */

/**
 * @param {number[]} nums
 * @return {number}
 */
const rob = nums => {
  if(nums.length == 0) return 0;
  if(nums.length == 1) return nums[0];

  const max = new Array(nums.length);
  max[0] = nums[0];
  max[1] = Math.max(nums[0], nums[1]);

  for (let i = 2; i < nums.length; i++) {
    max[i] = Math.max(max[i - 1], max[i - 2] + nums[i]);
  }

  return max[nums.length - 1];
};
```
