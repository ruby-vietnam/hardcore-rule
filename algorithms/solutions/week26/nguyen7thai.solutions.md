## Problem 1
https://leetcode.com/problems/find-the-difference/description/

```
/**
 * @param {string} s
 * @param {string} t
 * @return {character}
 */
var findTheDifference = function(s, t) {
    var hash = {}
    for (var i in s) {
        hash[s[i]] = (hash[s[i]] || 0) + 1
    }
    for (var j in t) {
        hash[t[j]] = (hash[t[j]] || 0) - 1
        if (hash[t[j]] < 0) {
            return t[j]
        }
    }
};
```
