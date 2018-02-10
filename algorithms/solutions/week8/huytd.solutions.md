# Problem 1: Longest Word in Dictionary

URL: https://leetcode.com/problems/longest-word-in-dictionary/discuss/109151/Java-solution-(easy-to-understand)

Status:
```
  ✔ Accepted
  ✔ 57/57 cases passed (153 ms)
  ✔ Your runtime beats 80 % of javascript submissions
```

<details open>
  <summary><b>Scanning approach:</b> O(n^2) - Accepted</summary>
The scanning approach, first, we sort the `words` array so it will be increased in alphabet order.

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

**Implementation:**

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

**Complexity:**

Let's assume `words.sort()` takes `O(n*logn)`, and `set.has()` takes `O(n)`, the algorithm should takes `O(n^2)`.
</details>

<details open>
  <summary><b>Trie + DFS approach:</b> Accepted</summary>
In this approach, we will build a Trie from the `words` array, then traversal with DFS to find the longest
string possible with the following algorithm:
  
- At each node, find the current string, it's the path from the root of the trie to the current node.
- If this string exist in `words` array, and this word is longer than the current building word, set the building word to this word
- In case the current string has the same length as the building words, we need to check for alphabet order of the two string, the lower one will be selected.
- Add all of the childs of the current node to queue and continue the DFS.
- If this string does not exist in `words` array, we can drop this branch.

Trie Implementation:
```javascript
class Node {
  constructor() {
    this.childs = Object.create(null);
  }

  insert(s) {
    if (s) {
      let c = s[0];
      if (!this.childs[c]) {
        this.childs[c] = new Node();
      }
      this.childs[c].insert(s.substr(1));
    }
  }
}
```

Algorithm Implementation:
```javascript
var longestWord = function(words) {
  let trie = new Node();
  let queue = []; let longest = "";
  for (let i = 0; i < words.length; i++) {
    trie.insert(words[i]);
  }
  for (let key in trie.childs) {
    queue.push([trie.childs[key], key]);
  }
  while (queue.length) {
    let [node, str] = queue.shift();
    if (words.indexOf(str) !== -1) {
      if (longest.length < str.length) {
        longest = str;
      }
      if (longest.length) {
        if (longest > str) {
          longest = str;
        }
      }
      for (let key in node.childs) {
        queue.push([node.childs[key], str + key]);
      } 
    }
  }
  return longest;
};
```
</details>
