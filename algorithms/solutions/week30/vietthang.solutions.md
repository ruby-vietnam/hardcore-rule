# Problem 1

```js
// Complete the miniMaxSum function below.
function miniMaxSum(arr) {
    arr = arr.sort();
    let min = sum(arr.slice(0, 4));
    let max = sum(arr.slice(1, 5));
    return `${min} ${max}`;
}

function sum(arr) {
    return arr.reduce((acc, el) => el + acc, 0);
}
```
