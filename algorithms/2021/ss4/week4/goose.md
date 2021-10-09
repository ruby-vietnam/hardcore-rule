# 1. Merge Intervals
https://leetcode.com/problems/merge-intervals/

## 1.1. Approach
Loop through the array, for each interval check if this interval belongs to current group (overlapping)
- If yes, push it to the current group
- If no, merge all intervals the current group and empty it

## 1.2. Code
```js
/**
 * @param {number[][]} intervals
 * @return {number[][]}
 */
var merge = function (intervals) {
  // Sort interval by start
  intervals.sort((a, b) => a[0] - b[0]);

  let result = [];
  let currentGroup = [];
  let currentGroupEnd = null;

  function mergeCurrentGroup() {
    const currentGroupStart = currentGroup[0][0];
    result.push([currentGroupStart, currentGroupEnd]);
    currentGroup = [];
    currentGroupEnd = null;
  }

  for (let interval of intervals) {
    if (currentGroupEnd === null) {
      currentGroup.push(interval);
      currentGroupEnd = interval[1];
      continue;
    }

    if (interval[0] <= currentGroupEnd) {
      currentGroup.push(interval);
      currentGroupEnd = Math.max(currentGroupEnd, interval[1]);
    } else {
      mergeCurrentGroup();
      currentGroup.push(interval);
      currentGroupEnd = interval[1];
    }
  }

  if (currentGroup.length) mergeCurrentGroup();

  return result;
};
```

# 2 Find First and Last Position of Element in Sorted Array
https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/

## 2.1. Approach
Using a modified version of binary search. Done it in two pass to find first and last index.

## 2.2. Code
```js
/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number[]}
 */
var searchRange = function (nums, target) {
  // Do it in two pass
  function find(position) {
    let lo = 0;
    let hi = nums.length - 1;

    while (true) {
      let mid = lo + Math.round((hi - lo) / 2);
      if (hi - lo === 1) {
        const indexes = position === 'first' ? [lo, hi] : [hi, lo];
        const found = indexes.find(index => nums[index] === target);
        return found !== undefined ? found : -1;
      }

      const condition =
        position === 'first' ? target > nums[mid] : target >= nums[mid];
      if (condition) lo = mid;
      else hi = mid;
    }
  }

  if (nums.length === 0) return [-1, -1];
  if (nums.length === 1) return nums[0] === target ? [0, 0] : [-1, -1];
  return [find('first'), find('last')];
};
```

# 3. Candy
https://leetcode.com/problems/candy/

## 3.1. Approach
Set the candy for the first index to 1. During iteration, we will encouter 3 scenario:
- The next element is bigger: just increment lastCandy by 1
- The next element is equal: since equal element doesn't have any constraint, just set it as low as we can (in this case 1)
- The next element is smaller: find the longest decrease chain from this index. For example, with this ratings [5,6,1,0,-1], the longest decrease chain from index 3 is [1,0,-1]. So what is the smallest amount of candy that we can give, it's [3,2,1]. But there's a catch, sometimes there are not enough "space" for 3: [1,2,3,2,1] (invalid because 2 < 3). In this case, we need to increase the lastCandy to have enough "space" for the decreasing chain: [1,4,3,2,1]

## 3.2. Code
```js
/**
 * @param {number[]} ratings
 * @return {number}
 */
var candy = function (ratings) {
  let MIN = 1;
  let totalCandies = 0;
  let lastCandy = null;

  for (let i = 0; i < ratings.length; ) {
    if (i === 0) {
      totalCandies += MIN;
      lastCandy = MIN;
      i++;
      continue;
    }

    if (ratings[i] === ratings[i - 1]) {
      totalCandies += MIN;
      lastCandy = MIN;
      i++;
      continue;
    }

    if (ratings[i] > ratings[i - 1]) {
      totalCandies += lastCandy + 1;
      lastCandy = lastCandy + 1;
      i++;
      continue;
    }

    if (ratings[i] < ratings[i - 1]) {
      let j = i;
      while (true) {
        totalCandies += j - i + 1;
        if (j >= ratings.length - 1) break;
        if (ratings[j] <= ratings[j + 1]) break;

        j++;
      }

      const lengthOfDecreaseStreak = j - i + 1;
      if (lastCandy - MIN < lengthOfDecreaseStreak) {
        totalCandies += lengthOfDecreaseStreak - (lastCandy - MIN);
      }

      lastCandy = MIN;
      i = j + 1;
      continue;
    }
  }

  return totalCandies;
};
```