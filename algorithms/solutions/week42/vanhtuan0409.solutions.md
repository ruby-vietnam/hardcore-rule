# Week 42

### Two Sum II (Easy)

```js
/**
 * @param {number[]} numbers
 * @param {number} target
 * @return {number[]}
 */
var twoSum = function(numbers, target) {
  let left = 0, right = numbers.length - 1;
  while (left < right) {
    const sum = numbers[left] + numbers[right]
    if (sum === target) {
      return [left +1, right +1];
    }
    if (sum < target) {
      left++;
    } else {
      right--;
    }
  }
  throw new Error('Expected a solution')
}
```

### Merge Interval (Medium)

```js
/**
 * Definition for an interval.
 * function Interval(start, end) {
 *     this.start = start;
 *     this.end = end;
 * }
 */
/**
 * @param {Interval[]} intervals
 * @return {Interval[]}
 */
var merge = function(intervals) {
  const res = [];
  intervals.sort(compare)
  for (let interval of intervals) {
    const lastInterval = res[res.length - 1]
    if (isOverlap(lastInterval, interval)) {
      res[res.length - 1] = mergeInterval(lastInterval, interval)
    } else {
      res.push(interval)
    }
  }
  return res;
};

function isOverlap(interval1, interval2) {
  if (!interval1 || !interval2) {
    return false;
  }
  return interval1.start <= interval2.end && interval1.end >= interval2.start;
}

function mergeInterval(interval1, interval2) {
  return new Interval(
    Math.min(interval1.start, interval2.start),
    Math.max(interval1.end, interval2.end),
  )
}

function compare(interval1, interval2) {
  if (interval1.start - interval2.start === 0) return interval1.end - interval2.end;
  return interval1.start - interval2.start;
}
```

### Maximum Swap (Medium)

```js
/**
 * @param {number} num
 * @return {number}
 */
var maximumSwap = function(num) {
  if (num < 10) return num;
  const digits = num.toString().split('').map(Number);

  let maxDigit = digits[digits.length - 1], maxIndex = digits.length - 1;
  let swapLeft = -1, swapRight = -1;
  for (let i = digits.length - 2; i >= 0; i--) {
    const digit = digits[i]
    if (digit > maxDigit) {
      maxDigit = digit;
      maxIndex = i;
      continue;
    }
    if (digit < maxDigit) {
      swapLeft = i;
      swapRight = maxIndex;
    }
  }

  if (swapLeft === -1) return num;
  // swap digits
  const tmp = digits[swapLeft];
  digits[swapLeft] = digits[swapRight];
  digits[swapRight] = tmp;
  return Number(digits.join(''))
};
```
