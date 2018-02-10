# Problem 1: Longest Word in Dictionary

URL: https://leetcode.com/problems/longest-word-in-dictionary/discuss/109151/Java-solution-(easy-to-understand)

Status:
```
  ✔ Accepted
  ✔ 57/57 cases passed (153 ms)
  ✔ Your runtime beats 80 % of javascript submissions
```

The bad approach, first, we sort the `words` array so it will be increased in alphabet order.

Then we create a `Set` to track the string building, this set will contains all of the string that has been built.

Then we loop through the `words` array, for each step, if the current string can be built from previous strings, the portion
of the string excluding its last character should be found in the building set.

```javascript
// Find the substring exclude the last character
// For example: Hello -> Hell
let previousWord = words[i].substring(0, words[i].length - 1);
// and
set.has(previousWord) == true
```

If so, we put the current string into the set, and update the `result` to the current word.

When the algorithm stops, the last string which recorded into `result` is the longest word that can be built 
from the previous array elements.

Implementation:

```javascript
var longestWord = function(words) {
  words.sort();
  let set = new Set();
  let result = "";
  for (let i = 0; i < words.length; i++) {
    if (words[i].length === 1 || set.has(words[i].substring(0, words[i].length - 1))) {
      set.add(words[i]);
      if (result.length < words[i].length) result = words[i];
    }
  }
  return result;
};
```

Complexity:

Let's assume `words.sort()` takes `O(n*logn)`, and `set.has()` takes `O(n)`, the algorithm should takes `O(n^2)`
