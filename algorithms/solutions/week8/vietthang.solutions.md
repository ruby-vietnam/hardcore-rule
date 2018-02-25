# Longest word in dictionary

```js
/**
 * @param {string[]} words
 * @return {string}
 */
var longestWord = function(words) {
    const obj = {}
    let max = 0
    let a = []

    words.forEach(ele => obj[ele] = true)

    for (let i = 0; i < words.length; i++) {

      if (words[i].length >= max) {
        let temp = ""
        let count = 0
        for (let j = 0; j < words[i].length; j++) {
          temp = temp.concat(words[i][j])
          if (obj[temp] === true) {
            count++
          }
        }

        if (count === words[i].length) {
          a.push(words[i])
          if (count > max) {
            a = [words[]]
          }
        } else count = 0
      }
    }

    a = a.sort()

    for (let i = 0; i < a.length; i++) {
      if (a[i].length === max) return a[i]
    }

    return ""
}
```
