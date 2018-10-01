# Week 41

### Single number (Easy)

```js
// https://leetcode.com/problems/single-number/description/

/**
 * @param {number[]} nums
 * @return {number}
 */
var singleNumber = function(nums) {
  const counting = new Map();
  for (let num of nums) {
    counting.set(num, (counting.get(num) || 0) + 1);
  }

  for (let [key, value] of counting.entries()) {
    if (value === 1) return key;
  }

  return -1;
};
```

### Palindromic substrings (Medium)

```js
// https://leetcode.com/problems/palindromic-substrings/description/

/**
 * @param {string} s
 * @return {number}
 */
var countSubstrings = function(s) {
  let count = 0;
  for (let i = 0; i < s.length; i++) {
    count += expandPalindromic(s, i, i);
    count += expandPalindromic(s, i, i + 1);
  }
  return count;
};

function expandPalindromic(s, leftIndex, rightIndex) {
  let count = 0;
  while (
    leftIndex >= 0 &&
    rightIndex < s.length &&
    s[leftIndex] === s[rightIndex]
  ) {
    count++;
    leftIndex--;
    rightIndex++;
  }
  return count;
}
```

### Largest rectangle in histogram (Hard)

```js
// https://leetcode.com/problems/largest-rectangle-in-histogram/description/

/**
 * @param {number[]} heights
 * @return {number}
 */
var largestRectangleArea = function(heights) {
  const stack = [];
  let maxArea = 0;
  for (let i = 0; i < heights.length; i++) {
    const currentHeight = heights[i];
    while (true) {
      const topIndex = stack[stack.length - 1];
      if (topIndex === undefined || currentHeight >= heights[topIndex]) break;
      const h = heights[stack.pop()];
      const lowerBound =
        stack[stack.length - 1] !== undefined ? stack[stack.length - 1] : -1;
      const w = i - lowerBound - 1;
      maxArea = Math.max(maxArea, h * w);
    }
    stack.push(i);
  }

  // Handle left over
  for (let i = stack.length - 1; i >= 0; i--) {
    const h = heights[stack.pop()];
    const lowerBound =
      stack[stack.length - 1] !== undefined ? stack[stack.length - 1] : -1;
    const w = heights.length - lowerBound - 1;
    maxArea = Math.max(maxArea, h * w);
  }

  return maxArea;
};
```
