## Problem 1

```js
var getIntersectionNode = function(headA, headB) {
  var iter = headA;
  var check = {};

  while (iter) {
    check[iter.val] = 1;
    iter = iter.next;
  }

  iter = headB;

  while (iter) {
    if (check[iter.val] == 1) {
      return iter;
    }

    iter = iter.next;
  }

  return null;
};
```
