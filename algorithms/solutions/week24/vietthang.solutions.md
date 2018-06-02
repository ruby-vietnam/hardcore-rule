# Problem 1

```js
/**
 * @param {number} c
 * @return {boolean}
 */
var judgeSquareSum = function(c) {
    for (let i = Math.floor(Math.sqrt(c)); i >= 0; i--) {
        if (Number.isInteger(Math.sqrt(c - i * i))) return true
    }
    
    return false
};
```
