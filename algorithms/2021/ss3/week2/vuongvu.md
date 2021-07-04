# 1. Happy Number

https://leetcode.com/problems/happy-number/

## 1.1. Summary

- if number is 1 then return true
- if number appears in memo object then return false (loops endlessly in a cycle)
- if not in these 2 cases:
  - store the number in memo
  - calculate the sum of all squares
  - rerun the function with the new number

## 1.2. Code

```js
const isHappy = function (n, memo = {}) {
  if (n === 1) return true;
  if (n in memo) return false;

  memo[n] = true;

  const sumOfQuares = `${n}`
    .split("")
    .map((e) => parseInt(e))
    .reduce((sum, num) => sum + num * num, 0);

  return isHappy(sumOfQuares, memo);
};
```

# 2. The k-th Lexicographical String of All Happy Strings of Length n

https://leetcode.com/problems/the-k-th-lexicographical-string-of-all-happy-strings-of-length-n/

## 2.1. Summary

- use a recursive function to find a list of happy strings
- return the string with given index

## 2.2. Code

```js
const happyList = ["a", "b", "c"];

var getHappyString = function (n, k) {
  const list = happyList
    .map((letter) => findString(letter, n - 1))
    .join()
    .split(",");
  return list[k - 1] || "";
};

const findString = (happyStr, n) => {
  if (n === 0) {
    return happyStr;
  }

  const nextLetters = happyList.filter(
    (letter) => letter !== happyStr[happyStr.length - 1]
  );

  return `${findString(`${happyStr}${nextLetters[0]}`, n - 1)},${findString(
    `${happyStr}${nextLetters[1]}`,
    n - 1
  )}`;
};
```

# 3. Longest Happy String

https://leetcode.com/problems/longest-happy-string/

## 3.1. Summary

## 3.2. Code

```js

```
