## Problem 1

```javascript
/**
 * @param {number[]} nums
 * @return {boolean}
 */
const checkPossibility = nums => {
  let c = 0;
  let n = nums.length;

  for (let i = 0; i < n; i++) {
    if (nums[i] > nums[i + 1]) {
      ++c;
      if (i === 0) {
        nums[i] = nums[i + 1];
      } else if (nums[i - 1] > nums[i + 1]) {
        nums[i + 1] = nums[i];
      } else if (nums[i - 1] < nums[i + 1]) {
        nums[i] = nums[i - 1];
      }
    }
  }

  return c <= 1;
}
```
