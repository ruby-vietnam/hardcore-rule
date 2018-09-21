# Problem 1
```javascript
/**
 * @param {number} x
 * @return {number}
 */
var reverse = function(x) {
  let y = ""
  if (x < 0) {
    y = "-"
  }
  let result = parseInt(recur(Math.abs(x), y));
  if (x == 0 || result > (Math.pow(2, 31) -1) || result < (-Math.pow(2, 31))) {
        return 0;
  }
  return result;
};

function recur(x, y) {
  if (x == 0) return y;
  return recur(parseInt(x/10), y.toString() + (x%10).toString())
}
```
