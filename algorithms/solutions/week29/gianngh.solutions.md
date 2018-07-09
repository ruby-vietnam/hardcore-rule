# Problem 1

```javascript
var countSay = function(cur, iter, n) {
  if (iter == n) return cur;
  let next = "";
  let count = 1;
  for (let i = 1; i < cur.length; ++i) {
    let c = cur.charAt(i);
    if (cur[i] != cur[i - 1]) {
      if (count > 0) {
        next += count.toString();
      }
      next += cur[i - 1];
      count = 1;
    } else {
      ++count;
    }
  }
  if (count > 0) {
    next += count.toString();
  }
  if (cur.length > 0) {
    next += cur[cur.length - 1];
  }
  return countSay(next, iter + 1, n);
};

var countAndSay = function(n) {
  if (n == 0) return "1";
  return countSay("", 0, n);
};
```
