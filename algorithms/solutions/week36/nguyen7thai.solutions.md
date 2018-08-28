## Problem 1
https://leetcode.com/problems/climbing-stairs/description/

```
/**
 * @param {number} n
 * @return {number}
 */
var climbStairs = function(n) {
    let a1 = 1
    if (n === 1) {
        return a1
    }
    let a2 = 2
    if (n === 2) {
        return a2
    }
    for(let i=3; i<=n; i++) {
        var a3 = a1 + a2
        a1 = a2
        a2 = a3
    }
    return a3
};
```
