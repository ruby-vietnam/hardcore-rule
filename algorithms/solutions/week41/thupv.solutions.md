## Problem 1
Link: https://leetcode.com/problems/single-number
 * 16 / 16 test cases passed.
 * Status: Accepted

```javascript
/**
 * @param {number[]} nums
 * @return {number}
 */
var singleNumber = function(nums) {
    for(var i=1; i<nums.length; i++){
        nums[0] = nums[0] ^ nums[i]
    }
    return nums[0];
};

```
