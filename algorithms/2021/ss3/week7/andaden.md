# 3. 3Sum

https://leetcode.com/problems/3sum/

## 3.1. Summary

- Sort input array
- Feach each `i`, find `j` and `k` by increase j and decrease k.
- When nums[i] > 0 break the loop cause nums[j] && nums[k] are also larger than 0.

## 3.2. Code

```js
var threeSum = function(nums) {
    if (nums.length < 3) return []
    const res = []
    nums = nums.sort((a, b) => a - b)
    for (let i = 0; i < nums.length - 2; i++) {
        if (nums[i] > 0) break
        if (i > 0 && nums[i] == nums[i - 1]) continue
        let j = i + 1
        let k = nums.length - 1
        while (j < k) {
            const sum = nums[i] + nums[j] + nums[k]
            if (sum == 0 ) {
                res.push([nums[i], nums[j], nums[k]])
                while (nums[j] == nums[j + 1]) j++
                while (nums[k] == nums[k - 1]) k--
                j++
                k--
            } else if (sum < 0) {
                j++                       
            } else {
                k--
            }
        }
    }
    return res;
};
```