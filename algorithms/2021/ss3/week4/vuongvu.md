# 1. Two Sum

https://leetcode.com/problems/two-sum/

## 1.1. Summary

- loop through all numbers
- use a memo object to store numbers that we've read
- check new numbers to see if there's a pair in the memo

## 1.2. Code

```js
const twoSum = function (nums, target) {
  const memo = {};

  for (let i = 0; i < nums.length; i++) {
    const current = nums[i];
    const pair = target - current;

    if (pair in memo) return [memo[pair], i];

    memo[current] = i;
  }
};
```

# 2. Valid Parentheses

https://leetcode.com/problems/valid-parentheses/

## 2.1. Summary

- if the string has an odd number total brackets return false
- loop through the bracket list
- use a stack to check open-close brackets
  - if current bracket is an open one
    - store it to the stack
  - if it is a close bracket
    - if stack length is 0 or current close bracket is not matched with the last open bracket in the stack, return false
    - else pop the open-close bracket to the stack
- when we loop through all brackets, if there's still left over bracket in the stack, return false, else it's true

## 2.2. Code

```js
const openBrackets = ["(", "[", "{"];
const bracketPairs = {
  ")": "(",
  "]": "[",
  "}": "{",
};

const isValid = function (s) {
  const brackets = s.split("");

  if (brackets.length % 2 !== 0) return false;

  const stack = [];

  for (let i = 0; i < brackets.length; i++) {
    const current = brackets[i];

    if (openBrackets.includes(current)) {
      stack.push(current);
    } else {
      if (
        stack.length === 0 ||
        bracketPairs[current] !== stack[stack.length - 1]
      ) {
        return false;
      }

      stack.pop();
    }
  }

  return stack.length === 0;
};
```

# 3. Generate Parentheses

https://leetcode.com/problems/generate-parentheses/

## 3.1. Summary

- use a recursive function to generate all possible results
  - start with an open bracket "(", the next posible will be either "(" or ")" and so on
  - stop when the string length is double the input n

## 3.2. Code

```js
const generateParenthesis = function (n) {
  return generate("(", n).split(",");
};

const getNextPosible = (str, n) => {
  const openCount = str
    .split("")
    .reduce((count, cur) => count + (cur === "(" ? 1 : 0), 0);
  const closeCount = str.length - openCount;

  const nextPosible = [];

  if (openCount < n) nextPosible.push("(");
  if (closeCount < openCount) nextPosible.push(")");

  return nextPosible;
};

const generate = (str, n) => {
  if (str.length === n * 2) return str;

  const nextPosible = getNextPosible(str, n);

  if (nextPosible.length === 2) {
    return `${generate(`${str}${nextPosible[0]}`, n)},${generate(
      `${str}${nextPosible[1]}`,
      n
    )}`;
  }

  return generate(`${str}${nextPosible[0]}`, n);
};
```
