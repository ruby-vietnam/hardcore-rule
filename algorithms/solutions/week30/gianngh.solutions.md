# Problem 1

```javascript
function main() {
  let a_temp = readLine()
    .split(" ")
    .map(Number);
  let sum = a_temp.reduce((acc, value) => (acc += value));
  let min = sum - Math.max.apply(null, a_temp);
  let max = sum - Math.min.apply(null, a_temp);
  console.log(min + " " + max);
}
```
