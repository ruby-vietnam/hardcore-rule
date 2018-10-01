#Problem 1
```javascript
/**
 * @param {number[]} nums
 * @return {number}
 */
var singleNumber = function(nums) {
    let v = 0;
    for (i =0; i<nums.length; i++) {
        v = v ^ nums[i];
    }
    return v;
};
```
