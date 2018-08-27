# Problem 1
 ```javascript
/**
 * @param {number[]} nums
 * @return {number}
 */
var rob = function(nums) {
  let odd = 0;
  let even = 0;
  for (let i = 0; i < nums.length; i++) {
      if (i % 2) {
        odd += nums[i];
        odd = Math.max(odd, even);
      } else {
        even += nums[i];
        even = Math.max(odd, even);
      }
    }
  return Math.max(odd, even);
}
```
