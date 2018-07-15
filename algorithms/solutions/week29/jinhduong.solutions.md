# #1
```js
/**
 * @param {number} n
 * @return {string}
 */
var countAndSay = function (n) {
    if (n === 1) return "1";
    else {
        var tmp = '';
        var cur = countAndSay(n - 1);
        for (let i = 0; i < cur.length; i++) {
            let j = i;
            while (j < cur.length && cur[i] == cur[j]) {
                j++
            }
            tmp = tmp + (j - i) + cur[i];
            i = j - 1;
        }
        return tmp;
    }
};
```