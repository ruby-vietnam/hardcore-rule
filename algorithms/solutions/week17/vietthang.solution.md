# Problem 1

```js
/**
 * @param {string} s
 * @param {string} t
 * @return {boolean}
 */
var isIsomorphic = function(s, t) {
    let map = {}
    let amap = {}

    for (let i = 0; i < s.length; i++) {
        if (map[s[i]] === undefined) {
            if (amap[t[i]] !== undefined) return false
            map[s[i]] = t[i]
            amap[t[i]] = s[i]
        }
        else if (map[s[i]] === t[i]) continue

        else return false
    }
    return true
};
```
