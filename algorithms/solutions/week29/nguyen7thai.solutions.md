## Problem 1
https://leetcode.com/problems/count-and-say/description/

```
/**
 * @param {number} n
 * @return {string}
 */
var countAndSay = function(n) {
    var string = "1"
    var result = "1"
    for(var i = 1; i < n ; i++) {
        result = ""
        var count = 0
        for( var j = 0; j < string.length; j++) {
            count++
            if ((string[j] !== string[j+1]) || (j == string.length - 1)) {
                result += count + string[j]
                count = 0
            }
        }
        string = result
    }
    return result
};
```
