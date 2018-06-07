## Problem 1
https://leetcode.com/problems/keyboard-row/description/

```
/**
 * @param {string[]} words
 * @return {string[]}
 */
function constructHash(row1String, row2String, row3String) {
    const result = {}
    let arr = [row1String, row2String, row3String]
    arr.forEach(function(rowString, index) {
        rowString.split('').forEach(function(s) {
            result[s] = index
        })
    })
    return result
}
var findWords = function(words) {
    const rowHash = constructHash('qwertyuiop', 'asdfghjkl', 'zxcvbnm')
    const result = []
    words.forEach(function(word) {
        const category = rowHash[word[0].toLowerCase()]
        let same = true
        for(s of word) {
            if(category !== rowHash[s.toLowerCase()]) {
                same = false
                break
            }
        }
        if (same) {
            result.push(word)
        }
    })
    return result
};
```
