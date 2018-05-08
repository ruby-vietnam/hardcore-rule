# Problem 1

```js
/**
 * @param {string} s
 * @param {string} t
 * @return {boolean}
 */
var isAnagram = function(s, t) {
    if (s.length != t.length) return false
    let sobj = {}
    let tobj = {}
    
    for (let i = 0; i < s.length; i++) {
        sobj[s[i]] = sobj[s[i]] + 1 || 1
        tobj[t[i]] = tobj[t[i]] + 1 || 1
    }
    
    for (let i in sobj) {
        if (sobj[i] !== tobj[i]) return false
    }
    
    return true
};
```
