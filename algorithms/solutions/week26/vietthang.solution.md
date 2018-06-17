# Problem 1

```js
/**
 * @param {string} s
 * @param {string} t
 * @return {character}
 */
let findTheDifference = function(s, t) {
    let tScore = 0
    let sScore = 0
    
    for (let i = 0; i < s.length; i++) {
        sScore += s.charCodeAt(i)
    }
    
    for (let i = 0; i < t.length; i++) {
        tScore += t.charCodeAt(i)
    }
    
    return String.fromCharCode(tScore - sScore)
}
```
