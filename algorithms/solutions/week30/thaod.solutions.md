## Problem 1

```javascript
function miniMaxSum(arr) {
  const sortedArr = arr.sort();
  const middle = sortedArr[1] + sortedArr[2] + sortedArr[3];
  console.log(`${sortedArr[0] + middle} ${middle + sortedArr[4]}`);
}
```
