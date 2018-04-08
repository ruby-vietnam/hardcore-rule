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
