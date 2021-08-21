# 1. Number of Strings That Appear as Substrings in Word

https://leetcode.com/problems/number-of-strings-that-appear-as-substrings-in-word/

## 1.1. Summary

## 1.2. Code

```js
const numOfStrings = function (patterns, word) {
  return patterns.reduce((total, current) => {
    return word.match(current) ? total + 1 : total;
  }, 0);
};
```

# 2. Check If String Is a Prefix of Array

https://leetcode.com/problems/check-if-string-is-a-prefix-of-array/

## 2.1. Summary

## 2.2. Code

```js
const isPrefixString = function (s, words) {
  let concatStr = "";
  let i = 0;
  while (concatStr.length <= s.length || i < words.length) {
    concatStr += words[i];
    if (concatStr === s) return true;
    i++;
  }

  return false;
};
```

# 3. Array With Elements Not Equal to Average of Neighbors

https://leetcode.com/problems/array-with-elements-not-equal-to-average-of-neighbors/

## 3.1. Summary

- use a pointer to loop through the array
- extract all numbers which not suit the condition and append them to the tail of the new array
- run it again until there's no number that need to change

## 3.2. Code

```js
const rearrangeArray = function (nums) {
  const temp = [];
  const newArr = [nums[0]];
  let i = 1;
  let prev = nums[0];
  let current;
  let next;
  let isKeepPrev = false;

  while (i < nums.length) {
    prev = isKeepPrev ? prev : nums[i - 1];
    current = nums[i];
    next = nums[i + 1];

    if ((prev + next) / 2 === current) {
      temp.push(current);
      isKeepPrev = true;
    } else {
      newArr.push(current);
      isKeepPrev = false;
    }

    i++;
  }

  return temp.length ? rearrangeArray(newArr.concat(temp)) : newArr;
};
```
