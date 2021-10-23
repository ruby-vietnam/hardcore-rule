# 1. Longest Substring Without Repeating Characters
https://leetcode.com/problems/longest-substring-without-repeating-characters/

## 1.1. Approach
Maintaining two pointer start and end, which determine the current substring without repeating characters. As we iterate through the string:
- If we encounter a non-repeating character, advance the end pointer by 1
- If we encounter a repeating character, advance the end pointer by 1 and the start pointer to k + 1 (where k is the index of the previous occurence of the repeating character)
While we iterating, keep track of the longest substring and also maintaining a dictionary to speed up the repeat character lookup

## 1.2. Code
```js
/**
 * @param {string} s
 * @return {number}
 */
var lengthOfLongestSubstring = function (s) {
  let map = {};
  let longest = 0;
  let start = 0;
  let end = null;

  function findRepeatIndex(char) {
    const occurrences = map[char];
    if (!occurrences) return null;
    return occurrences.find(index => index >= start);
  }

  for (let i = 0; i < s.length; i++) {
    const char = s[i];
    let repeatIndex = findRepeatIndex(char);
    if (repeatIndex != null) {
      longest = Math.max(longest, end - start + 1);
      start = repeatIndex + 1;
      end = i;
    } else {
      end = i;
      longest = Math.max(longest, end - start + 1);
    }

    if (char in map) map[char].push(i);
    else map[char] = [i];
  }

  return longest;
};
```

# 2 Rotate Array
https://leetcode.com/problems/rotate-array/

## 2.1. Approach
We start at the first index and jump k step forward. We set the value at where we land to value of the index where we start. And also we save the value which we just override into a temp variable. Keep repeating until we find a loop (we end up at an index we have visited). We check if we complete a loop with this condition: total jump length divisible by array length. If we encounter a loop, move on the next index and repeat.

## 2.2. Code
```js
/**
 * @param {number[]} nums
 * @param {number} k
 * @return {void} Do not return anything, modify nums in-place instead.
 */
var rotate = function (nums, k) {
  let currentIndex = 0;
  let temp = nums[currentIndex];
  let jumpDistance = 0;

  while (jumpDistance < nums.length * k) {
    if (jumpDistance % nums.length === 0 && jumpDistance !== 0) {
      currentIndex = (currentIndex + 1) % nums.length;
      temp = nums[currentIndex];
    }

    currentIndex = (currentIndex + k) % nums.length;
    const newIndexValue = nums[currentIndex];
    nums[currentIndex] = temp;
    temp = newIndexValue;

    jumpDistance += k;
  }
};
```