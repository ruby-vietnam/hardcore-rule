# Problem 1

```js
/**
 * @param {number[]} nums
 * @return {boolean}
 */
var checkPossibility = function(nums) {
    let wr = 0
    
    for (let i = 1; i < nums.length && wr <= 1; i++) {
        if (nums[i-1] > nums[i]) {
            wr++
            if (i - 2 < 0 || nums[i - 2] < nums[i]) nums[i - 1] = nums[i]
            else nums[i] = nums[i - 1]
        }
    }
    
    return wr <= 1
};
```
