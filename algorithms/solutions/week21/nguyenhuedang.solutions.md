## Problem 1 - [Valid Anagram](https://leetcode.com/problems/valid-anagram/description/)

```javascript
var isAnagram = function(s, t) {
  if (s.length !== t.length) { return false; }
  const hash = {};
  for (let i = 0; i < s.length; ++i) {
    const si = s.charCodeAt(i);
    const ti = t.charCodeAt(i);
    hash[si] = (hash[si] || 0) + 1;
    hash[ti] = (hash[ti] || 0) - 1;
  }
  return Object.values(hash).every(i => i === 0)
};
```
