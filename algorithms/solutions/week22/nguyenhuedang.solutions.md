## Problem 1 - [Majority Element](https://leetcode.com/problems/majority-element/description/)

```javascript
/**
 * @param {number[]} nums
 * @return {number}
 */
var majorityElement = function(nums) {
  let major = -1;
  let count = 0;

  for (const i of nums) {
    if (major === i) { count++; }
    else if (count === 0) {
      count = 1;
      major = i
    } else {
      count--;
    }
  }

  return major;
};
```

## Problem 2 - [Bulb Switcher](https://leetcode.com/problems/bulb-switcher/description/)

```javascript
/**
 * @param {number} n
 * @return {number}
 */

var bulbSwitch = function(n) {
  return Math.floor(Math.sqrt(n))
};
```
