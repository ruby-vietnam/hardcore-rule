# 1. Excel Sheet Column Title

https://leetcode.com/problems/excel-sheet-column-title/

## 1.1. Summary

- use recursive function to convert each letter one by one
- convert from the last letter by using the mod operator

## 1.2. Code

```js
const allLetters = ["A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M", "N", "O", "P", "K", "R", "S", "T", "U", "V", "W", "X", "Y", "Z"];

const LETTERS_LENGTH = 26;

const convertToTitle = function (number) {
  if (number <= LETTERS_LENGTH) return allLetters[number - 1];

  const lastLetterIndex = number % LETTERS_LENGTH || LETTERS_LENGTH;
  const lastLetter = allLetters[lastLetterIndex - 1];
  const restNum = (number - lastLetterIndex) / LETTERS_LENGTH;

  return `${convertToTitle(restNum)}${lastLetter}`;
};
```

# 2. Climbing Stairs

https://leetcode.com/problems/climbing-stairs/

## 2.1. Summary

- use a recursive function with a cache param

## 2.2. Code

```js
const climbStairs = function (n, cache = {}) {
  if (n in cache) return cache[n];
  if (n === 0) return 1;
  if (n < 0) return 0;

  const climb2Step = climbStairs(n - 2, cache);
  const climb1Step = climbStairs(n - 1, cache);
  cache[n] = climb1Step + climb2Step;

  return cache[n];
};
```

# 3. House Robber

https://leetcode.com/problems/house-robber/

## 3.1. Summary

- use a recursive function with a cache param
- the rob job will start from 0 or 1
- each house rob will be 2 or 3 indexes apart from the current house
- compare each path to get the most amount

## 3.2. Code

```js
const rob = function (nums) {
  const robJob = robCache(nums);
  return Math.max(robJob(0), robJob(1));
};

const robCache = function (nums) {
  const cache = {};

  return function robStep(n, money = 0) {
    const key = `${money}_${n}`;

    if (key in cache) return cache[key];
    if (n > nums.length - 1) return money;

    cache[key] = Math.max(
      robStep(n + 2, money + nums[n]),
      robStep(n + 3, money + nums[n])
    );

    return cache[key];
  };
};
```

# 4. House Robber ||

https://leetcode.com/problems/house-robber-ii/

## 4.1. Summary

- use a recursive function with a cache param
- the rob job will start from 0 or 1 or 2
- each house rob will be 2 or 3 indexes apart from the current house
- depend on the start index, the search will end by the last house or the house before the last
- compare each path to get the most amount

## 4.2. Code

```js
const rob = function (nums) {
  if (nums.length === 1) return nums[0];

  const robStartFirstHouse = robCache(nums, 0);
  const robStartSecondHouse = robCache(nums, 1);
  const robStartThirdHouse = robCache(nums, 2);

  return Math.max(
    robStartFirstHouse(),
    robStartSecondHouse(),
    robStartThirdHouse()
  );
};

const robCache = function (nums, startIndex) {
  const cache = {};

  return function robStep(n = startIndex, money = 0) {
    const key = `${money}_${n}`;

    if (key in cache) return cache[key];

    if (startIndex === 0) {
      if (n > nums.length - 2) return money;
    } else {
      if (n > nums.length - 1) return money;
    }

    cache[key] = Math.max(
      robStep(n + 2, money + nums[n]),
      robStep(n + 3, money + nums[n])
    );

    return cache[key];
  };
};
```
