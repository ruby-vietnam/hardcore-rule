# #1
```js
/**
 * @param {string} s
 * @param {string} t
 * @return {boolean}
 */
var isAnagram = function (s, t) {
    if (s.length !== t.length) return false;

    const s1 = Array.from(s).sort();
    const t1 = Array.from(t).sort();

    for (let i = 0, l = s1.length - 1; i <= l; i++)
        if (s1[i] !== t1[i]) return false;

    return true;
};
```
