## Problem 1
https://leetcode.com/problems/sum-of-square-numbers/description/

```
/**
 * @param {number} c
 * @return {boolean}
 */
var judgeSquareSum = function(c) {
    var hash = {}
    for(var i=0; i * i <= c; i++) {
        j = i * i
        remaining = c - j
        hash[j] = true
        if (hash[remaining]) {
            return true
        }
    }
    return false
};
```
