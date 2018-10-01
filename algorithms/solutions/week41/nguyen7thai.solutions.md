## Problem 1
https://leetcode.com/problems/single-number/description/

```
/**
 * @param {number[]} nums
 * @return {number}
 */
var singleNumber = function(nums) {
    return nums.reduce((sum, i) => sum ^ i)
};
```
