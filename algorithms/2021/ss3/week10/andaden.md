# 1. Reverse Bits

https://leetcode.com/problems/reverse-bits/

## 1.1. Summary

 - Loop through each bit from tail to head.

## 1.2. Code

```js
/**
 * @param {number} n - a positive integer
 * @return {number} - a positive integer
 */
var reverseBits = function(n) {
    let i = 32;
    let res = 0;
    while (i > 0) {
        let bit = n & 1;
        res = res * 2 + bit;
        n >>= 1;
        i--;
    }
    return res;
};
```

# 2. Number of 1 Bits

https://leetcode.com/problems/number-of-1-bits/

## 2.1. Summary

 - Loop through each bit by right shift the number.
 - At each bit, the number of 1 bit is the result of number & 1

## 2.2. Code

```js
/**
 * @param {number} n - a positive integer
 * @return {number}
 */
var hammingWeight = function(n) {
    let count = 0;
    while (n > 0) {
        count += n & 1;
        n = n >>> 1;
    }
    return count;
};
```

# 4. Container With Most Water

https://leetcode.com/problems/container-with-most-water/


## 4.1. Summary
 - Start with the maximum width container and go to a shorter width container if there is a vertical line longer than the current containers shorter line.
 - This way we are compromising on the width but we are looking forward to a longer length container.
 - Using two pointers

## 4.2. Code

```js
var maxArea = function(height) {
    let left = 0,
        right = height.length - 1,
        max = 0;
    while (left < right) {
        max = Math.max(max, Math.min(height[left], height[right]) * (right - left));
        if (height[left] < height[right]) {
            left++;
        } else {
            right--;
        }
    }
    return max;
};
```
