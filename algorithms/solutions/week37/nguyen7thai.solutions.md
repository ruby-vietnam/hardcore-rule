## Problem 1
https://leetcode.com/problems/power-of-three/description/

```
/**
 * @param {number} n
 * @return {boolean}
 */
var isPowerOfThree = function(n) {
    let i = Math.log(n) / Math.log(3)
    return 3 ** parseInt(i) === n
};
```
