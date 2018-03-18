# Problem 1: Maximum Product of Three Numbers

URL: https://leetcode.com/problems/maximum-product-of-three-numbers/description/

Status:

```
  ✔ Accepted
  ✔ 83/83 cases passed (124 ms)
  ✔ Your runtime beats 83.91 % of javascript submissions
```

Approach: Sort the array first, then:

- If there are negative items, it's possible that the smallest two negative numbers can multiply with the largest number to make the max product
- If there are no negative numbers, just multiply the largest 3 items of the array

```javascript
var maximumProduct = function(nums) {
    let len = nums.length;
    nums.sort((a, b) => (~~a) - (~~b));
    return Math.max(nums[0] * nums[1] * nums[len-1], nums[len-1] * nums[len-2] * nums[len-3]);
};
```

# Problem 2: Divide two Integers

URL: https://leetcode.com/problems/divide-two-integers/description/

Status:
```
  ✔ Accepted
  ✔ 988/988 cases passed (76 ms)
  ✔ Your runtime beats 85.71 % of javascript submissions
```

Solution:

```javascript
const MAX_INT = 2147483647;

var divide = function(dividend, divisor) {
    let isNeg = (dividend > 0 && divisor < 0) || (dividend < 0 && divisor > 0);
    dividend = Math.abs(dividend);
    divisor = Math.abs(divisor);
    let r = 0;
    while (dividend >= divisor) {
        let n = divisor;
        let i = 1;
        while (dividend >= n) {
            dividend -= n;
            r += i;
            i = i * 2;
            n = n * 2;
        }
    }
    r = (isNeg) ? -r : r;
    if (r > MAX_INT) return MAX_INT;
    if (r < -MAX_INT) return -(MAX_INT + 1);
    return r;
};
```
