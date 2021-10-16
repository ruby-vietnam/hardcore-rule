## 1. [121] Best Time to Buy and Sell Stock
https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

### 1.1 Approach
- Loop though prices, find min in each iteration
- Update max profit from current price with min price above

### 1.2 Code
```js
/**
 * @param {number[]} prices
 * @return {number}
 */
var maxProfit = function (prices) {
    let maxP = 0;
    let min = prices[0]
    for (let i = 1; i < prices.length; i++) {
      min = Math.min(min, prices[i])
      maxP = Math.max(prices[i] - min, maxP)
    }
    return maxP;
  };
```

---

## 2. [1] Two Sum
https://leetcode.com/problems/two-sum/

### 2.1 Approach
- Build up a hashtable {[value of nums[i]]:i} to keep track the relation from value to index
- In each iteration (i), if from hashtable we can find item with key is (target - nums[i]) then we return it otherwise we update the hashtable with current value and index

### 2.2 Code
```js
/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number[]}
 */
var twoSum = function (nums, target) {
  let htb = {} //hashtable
  for (let i = 0; i < nums.length; i++) {
    if (htb[target - nums[i]] != null) {
      return [i, htb[target - nums[i]]]
    } else {
      htb[nums[i]] = i
    }
  }
};
```

---

## 3. [56] Merge Intervals
https://leetcode.com/problems/merge-intervals/
### 3.1 Approach

- Sort the intervals base on the start of each item
- In each iteration, merge each item to then next on, if not mergeable, increasing the step

### 3.2 Code

```js
/**
 * @param {number[][]} intervals
 * @return {number[][]}
 */
var merge = function (intervals) {
  intervals.sort((a, b) => a[0] - b[0])
  let i = 0;
  while (i < intervals.length - 1) {
    let nm = mergable(intervals[i], intervals[i + 1]);
    if (nm.length) {
      intervals[i] = nm;
      intervals.splice(i + 1, 1);
    } else {
      i++;
    }
  }
  return intervals;
};
function mergable(a, b) {
  return (a[1] >= b[0]) ? [a[0], Math.max(b[1], a[1])] : []
}
```

---

## 1. []

### 1.1 Approach

-

### 1.2 Code

```js
```
