## Problem 1
https://leetcode.com/problems/reverse-integer/description/

```
/**
 * @param {number} x
 * @return {number}
 */
var reverse = function(x) {
    const MIN = -1 * 2**31
    const MAX = 2**31 - 1
    let s = x.toString()
    let sign = s[0] === '-' ? s[0] : ''
    let sub = sign === '-' ? s.slice(1) : s
    sub = sub.split('').reverse().join('')
    const result = parseInt(`${sign}${sub}`)
    if (result < MIN || result > MAX) {
        return 0
    }
    return result
};
```
