# 1. Majority Element

https://leetcode.com/problems/majority-element/

## 1.1. Summary

- use a map to store the number appearance
- loop through the list and get the most appearance

## 1.2. Code

```js
const majorityElement = function (nums) {
  const appearances = {};
  let maxApp = 0;
  let majorNum;

  nums.forEach((num) => {
    appearances[num] = (appearances[num] || 0) + 1;
    if (appearances[num] > maxApp) {
      maxApp = appearances[num];
      majorNum = num;
    }
  });

  return majorNum;
};
```

# 2. Sort Array By Parity

https://leetcode.com/problems/sort-array-by-parity/

## 2.1. Summary

- use 2 pointers: left to find the odd numbers, right to find the even numbers
- swap 2 numbers
- stop when 2 pointers pass each other

## 2.2. Code

```js
const sortArrayByParity = function (nums) {
  let left = 0;
  let right = nums.length - 1;

  while (left < right) {
    left = findOdd(left, nums);
    right = findEven(right, nums);

    if (left > right) return nums;
    swap(nums, left, right);
  }

  return nums;
};

const findOdd = (pointer, nums) => {
  for (let i = pointer; i < nums.length; i++) {
    if (nums[i] % 2 !== 0) return i;
  }

  return Infinity;
};

const findEven = (pointer, nums) => {
  for (let i = pointer; i > 0; i--) {
    if (nums[i] % 2 === 0) return i;
  }

  return -Infinity;
};

const swap = (nums, left, right) => {
  [nums[left], nums[right]] = [nums[right], nums[left]];
};
```

# 3. 3Sum

https://leetcode.com/problems/3sum/

## 3.1. Summary

- Loop through the list
- Reuse the twoSum function to get the right pair

## 3.2. Code

```js
const twoSum = function (nums, target) {
  const memo = {};
  const results = [];

  for (let i = 0; i < nums.length; i++) {
    const current = nums[i];
    const pair = target - current;
    if (pair in memo) results.push([memo[pair], nums[i]]);
    memo[current] = nums[i];
  }

  return results;
};

const threeSum = function (nums) {
  const results = [];
  const memo = {};

  nums.forEach((num, index) => {
    const twoSumResult = twoSum(nums.slice(index + 1), -num);
    twoSumResult.forEach((twoSumPair) => {
      const newTriplet = [num].concat(twoSumPair).sort();
      const key = newTriplet.join("_");
      if (!memo[key]) {
        memo[key] = true;
        results.push(newTriplet);
      }
    });
  });

  return results;
};
```
