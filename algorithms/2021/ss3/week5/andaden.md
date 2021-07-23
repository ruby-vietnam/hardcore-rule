# 3. House Robber
https://leetcode.com/problems/house-robber/
## 3.1 Summary

You are a profesional robber planning to rob houses along a street. You cannot rob adjacent houses.

Given an integer array nums representing the amount of money of each house, return the maximum amount of money you can rob tonight without alerting the police.

## 3.2 Code
```js
/**
 * @param {number[]} nums
 * @return {number}
 */
var rob = function(nums) {
    let r = 0, notR = 0;
    for (let i = 0; i < nums.length; i++ ) {
        const currentRob = notR + nums[i];
        notR = Math.max(notR, r);
        r = currentRob;
    }
    return Math.max(r, notR);
};
```

# 4. House Robber II
 https://leetcode.com/problems/house-robber-ii/
 
 ## 4.1 Summary
 
 The same to #3 but the first house and the last house are ajacent.
 
 Since House[1] and House[n] are adjacent, they cannot be robbed together. Therefore, the problem becomes to rob either House[1]-House[n-1] or House[2]-House[n], depending on which choice offers more money.

 ## 4.2. Code
```js
/**
 * @param {number[]} nums
 * @return {number}
 */
var rob = function(nums) {
    const N = nums.length;
    if (N==0 ) return 0;
    if (N == 1) return nums[0];
    const rob1 = houses => {
        let beRob = 0, notRob = 0;
        for (let i = 0; i < houses.length; i++) {
            let currentRob = notRob + houses[i];
            notRob = Math.max(notRob, beRob);
            beRob = currentRob;
        }
        return Math.max(beRob, notRob);
    }
    return Math.max(rob1(nums.slice(1)), rob1(nums.slice(0, N-1)));
};
```