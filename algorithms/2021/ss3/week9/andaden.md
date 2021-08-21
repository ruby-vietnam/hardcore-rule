# 1. Number of Strings That Appear as Substrings in Word

https://leetcode.com/problems/number-of-strings-that-appear-as-substrings-in-word/

## 1.1. Summary

 - Loop through patterns and check if pattern is existed in the word.

## 1.2. Code

```js
/**
 * @param {string[]} patterns
 * @param {string} word
 * @return {number}
 */
var numOfStrings = function(patterns, word) {
    return patterns.reduce((acc, p) => {
        return word.includes(p) ? acc + 1 : acc;
    }, 0);
};
```

# 2. Check If String Is a Prefix of Array

## 2.1. Summary

 - Loop through words and join word. Return true if the joined string is equal to s.

https://leetcode.com/problems/check-if-string-is-a-prefix-of-array/

## 2.2. Code

```js
/**
 * @param {string} s
 * @param {string[]} words
 * @return {boolean}
 */
var isPrefixString = function(s, words) {
    let prefix = '';
    for (let i = 0; i < words.length; i++) {
        prefix = `${prefix}${words[i]}`;
        if (prefix === s) return true;
    }
    return false;
};
```

# 3. Array With Elements Not Equal to Average of Neighbors

https://leetcode.com/problems/array-with-elements-not-equal-to-average-of-neighbors/

## 3.1. Summary
 - If an item is equal to the average of its neighbors, it and neighbors are in order.
 - Go through item in array `nums` except first and last item.
   - If the item and its neighbors are in order, swap it with the next item.

## 3.2. Code

```js
/**
 * @param {number[]} nums
 * @return {number[]}
 */
var rearrangeArray = function(nums) {
    const swap = (nums, x, y) => {
        const temp = nums[x];
        nums[x] = nums[y];
        nums[y] = temp;
    }
    for (let i = 1; i < nums.length - 1; i++) {
        if ((nums[i] > nums[i-1] && nums[i] < nums[i+1])
            || (nums[i] < nums[i-1] && nums[i] > nums[i+1]) ) {
            swap(nums, i, i+1);
        }
    }
    return nums;
};
```
