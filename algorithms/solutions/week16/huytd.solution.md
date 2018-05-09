# Problem 1: Contains Duplicate II

URL: https://leetcode.com/problems/contains-duplicate-ii/description/

Status:
```
  ✔ Accepted
  ✔ 23/23 cases passed (72 ms)
  ✔ Your runtime beats 93.9 % of javascript submissions
```

Solution: Sliding window solution, but use a Set, so we can have just 1 loop, if the current item is exist in the set, so we found a duplicated, if not, we add it to the set, and if the length of the set is longer than K, we start removing old items.

```javascript
var containsNearbyDuplicate = function(nums, k) {
    let set = new Set();
    for (let i = 0; i < nums.length; i++) {
        if (i - k > 0) set.delete(nums[i-k-1]);
        if (set.has(nums[i])) return true;
        set.add(nums[i]);
    }
    return false;
};
```

# Problem 2: Find Peak Element

URL: https://leetcode.com/problems/find-peak-element/description/

Status:

```
  ✔ Accepted
  ✔ 58/58 cases passed (56 ms)
  ✔ Your runtime beats 61.48 % of javascript submissions
```

What's going on? I'm just submited and passed. The solution is... find max. Well, O(n) solution:

```javascript
var findPeakElement = function(nums) {
    let max = nums[0]; let maxi = 0;
    for (let i = 0; i < nums.length; i++) {
        if (nums[i] > max) {
            max = nums[i];
            maxi = i;
        }
    }
    return maxi;
};
```

Binary search solution:

```javascript
var findPeakElement = function(nums) {
    let first = 0;
    let last = nums.length - 1;
    while (first < last) {
        let mid = ~~((first + last) / 2);
        if (mid + 1 <= last && nums[mid] < nums[mid + 1])
            first = mid + 1;
        else
            last = mid;
    }
    return first;
};
```
