## Problem 1
https://leetcode.com/problems/non-decreasing-array/description/

```
/**
 * @param {number[]} nums
 * @return {boolean}
 */
var checkPossibility = function(nums) {
    var count = 0
    for(var i = 0; i < nums.length-1; i++) {
        var prev = nums[i-1]
        var curr = nums[i]
        var next = nums[i+1]
        if (curr > next) {
            count++
            if (i === 0){
                nums[i] = nums[i+1]
            } else if (next > prev) {
                nums[i] = nums[i+1]
            } else if (next < prev) {
                nums[i+1] = nums[i]
            }
        }
    }
    return count <= 1
};
```
