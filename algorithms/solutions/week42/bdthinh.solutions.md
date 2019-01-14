## Problem 1
Problem: https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/

```js
const twoSum = (numbers, target)  => {
  const len = numbers.length - 1;
  let i = 0;
  let j = 1;

  numbers.some((number, index) => {
    let begin = index;
    let end = len;
    while (begin < end) {
      const current = numbers[begin] + numbers[end];

      if (current === target) {
         [i, j] = [begin, end];
        return true;
      }
      if (current > target) {
        end--;
      } else {
        begin++;
      }
    }
  })
  return [i + 1, j + 1];
};

```

## Problem 2

https://leetcode.com/problems/merge-intervals

```js
const mergeAble = (intervalA, intervalB) => {
  const isBOverlapA = intervalA.start <= intervalB.start && intervalB.start <= intervalA.end;
  const isAOverlapB = intervalB.start <= intervalA.start && intervalA.start <= intervalB.end;
  const isAInB = intervalB.start <= intervalA.start && intervalA.end <= intervalB.end;
  const isBInA = intervalA.start <= intervalB.start && intervalB.end <= intervalA.end;
  return (isBInA || isAInB || isBOverlapA || isAOverlapB);
}

const mergeBetween = (intervalA, intervalB) => {
  if (mergeAble(intervalA, intervalB)) {
    return new Interval(
      Math.min(intervalA.start, intervalB.start),
      Math.max(intervalA.end, intervalB.end)
    );
  }
  return intervalA;
}

const compareIntervals = (a,b) => {
  if (a.start > b.start) {
    return 1;
  }
  if (a.start < b.start) {
    return -1;
  }
  return 0;
}

const merge = intervals =>
  intervals
    .sort(compareIntervals)
    .reduce((result, interval) => (
      _.uniqWith([
        ...result.map(item => mergeBetween(item, interval)),
        interval,
      ], (a,b) => mergeAble(a,b))
    ),[]);
```

## Problem 3

https://leetcode.com/problems/maximum-swap

```js
const maximumSwap = num => {
  let record = {};
  let chars = `${num}`.split('');

  chars.forEach((digit, index) => record[digit] = index);

  for (i = 0; i < chars.length; i++) {
    for (d = 9; d > parseInt(chars[i]); d--) {
      if (record[d] > i) {
        [chars[i], chars[record[d]]] = [chars[record[d]], chars[i]];
        return parseInt(chars.join(''));
      }
    }
  }

  return num;
}

```
