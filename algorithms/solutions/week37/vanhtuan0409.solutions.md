# Week 37

### Power of Three (easy)

```js
// https://leetcode.com/problems/power-of-three/description/

/**
 * @param {number} n
 * @return {boolean}
 */
var isPowerOfThree = function(n) {
  // 3^33 is maximum int that still smaller than Number.MAX_SAFE_INTEGER
  return (
    n === Math.pow(3, 0) ||
    n === Math.pow(3, 1) ||
    n === Math.pow(3, 2) ||
    n === Math.pow(3, 3) ||
    n === Math.pow(3, 4) ||
    n === Math.pow(3, 5) ||
    n === Math.pow(3, 6) ||
    n === Math.pow(3, 7) ||
    n === Math.pow(3, 8) ||
    n === Math.pow(3, 9) ||
    n === Math.pow(3, 10) ||
    n === Math.pow(3, 11) ||
    n === Math.pow(3, 12) ||
    n === Math.pow(3, 13) ||
    n === Math.pow(3, 14) ||
    n === Math.pow(3, 15) ||
    n === Math.pow(3, 16) ||
    n === Math.pow(3, 17) ||
    n === Math.pow(3, 18) ||
    n === Math.pow(3, 19) ||
    n === Math.pow(3, 20) ||
    n === Math.pow(3, 21) ||
    n === Math.pow(3, 22) ||
    n === Math.pow(3, 23) ||
    n === Math.pow(3, 24) ||
    n === Math.pow(3, 25) ||
    n === Math.pow(3, 26) ||
    n === Math.pow(3, 27) ||
    n === Math.pow(3, 28) ||
    n === Math.pow(3, 29) ||
    n === Math.pow(3, 30) ||
    n === Math.pow(3, 31) ||
    n === Math.pow(3, 32) ||
    n === Math.pow(3, 33)
  );
};
```
