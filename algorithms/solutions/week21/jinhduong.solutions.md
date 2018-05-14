# #1
```js
/**
 * @param {string} s
 * @param {string} t
 * @return {boolean}
 */
var isAnagram = function (s, t) {
    if (s.length !== t.length) return -1;
    for (let i = 0, l = s.length - 1; i <= l; i++) {
        if (s[i] !== t[l - i]) return -1;
        else if (i === l - i) return 1;
    }
    return 1;
};
```
