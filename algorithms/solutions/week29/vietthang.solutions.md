# Problem 1

```js
var countAndSay = function(n) {
    return recur(n, 1, "1")
};

var recur = function(n, i,current) {
    if (i === n) return current
    let idx = 0
    let count = 1
    let say = ""
    while (idx < current.length) {
        if (current[idx] != current[idx + 1]) {
            say += count + current[idx]
            count = 1
        } else count++
        idx++
    }
    return recur(n, ++i, say)
};
```
