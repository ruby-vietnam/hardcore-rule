## Problem 1

```javascript
/**
 * Problem: https://leetcode.com/problems/count-and-say/description/
 */

/**
 * @param {number} n
 * @return {string}
 */
const countAndSay = n => {
  if (n < 1) return;
  if (n === 1) return '1';

  const s = countAndSay(n - 1);
  const ns = s.length;

  if (ns === 1) return `1${s}`;

  const ic = {};
  let c = '';

  for (let i = 1; i <= ns; i++) {
    if (s[i] !== s[i - 1]) {
      c += `${ic[s[i - 1]] ? i - ic[s[i - 1]] : i - 0}${s[i - 1]}`;
      ic[s[i - 1]] = null;
      if (ic[s[i]] === null || ic[s[i]] === undefined) ic[s[i]] = i;
    }
  }

  return c;
};
```
