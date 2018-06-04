# Week 24

## Problem 1 - [Sum of Square Numbers](https://leetcode.com/problems/sum-of-square-numbers/)

```javascript
/**
 * @param {number} c
 * @return {boolean}
 */

const isSquare = (n) => {
  const i = Math.round(Math.sqrt(n));
  return i*i === n;
}

var judgeSquareSum = function(c) {
  for (let i = 0; 2 * i * i <= c; ++i) {
    const j = (c - i * i);
    if (isSquare(j)) { return true; }
  }

  return false;
};
```

## Problem 2 - [Largest Number](https://leetcode.com/problems/largest-number/)

```javascript
/**
 * @param {number[]} nums
 * @return {string}
 */
var largestNumber = function(nums) {
  return nums
    .map(num => String(num))
    .sort((a, b) => Number(b + a) - Number(a + b))
    .join('')
    .replace(/^0*0$/g, 0);
};
```

## Problem 3 - [Coin Change](https://leetcode.com/problems/coin-change/)

```javascript
/**
 * @param {number[]} coins
 * @param {number} amount
 * @return {number}
 */

var coinChange = function(coins, amount) {
  const bound = Math.min(...coins);
  const cache = {};
  const attemp = (_amount) => {
    if (cache[_amount]) { return cache[_amount]; }
    if (_amount === 0) { return 0; }
    if (_amount < bound) { return; }

    cache[_amount] = coins.reduce(
      (_min, coin) => {
        const next = attemp(_amount - coin);
        return next > -1 ? Math.min(next + 1, _min) : _min
      }, _amount + 1
    );

    if (cache[_amount] === _amount + 1) { cache[_amount] = -1; }
    return cache[_amount];
  }

  const res = attemp(amount);
  return res < amount + 1 ? res : -1;
};
```
