
# 1. Excel Sheet Column Title

https://leetcode.com/problems/excel-sheet-column-title/

## 1.1 Summary

```
0   -  A
26  -  Z 
27  -  AA -> (27 - 1)/26 + 1
28  -  AB -> (28 - 2)/26 + 2
701 -  ZY -> (701 - 25)/26 + 25
```

## 1.2. Code

```js
/**
 * @param {number} columnNumber
 * @return {string}
 */
var convertToTitle = function (columnNumber) {
    if (columnNumber <= 26) return getChar(columnNumber)
    let result = ""
    while (columnNumber > 0) {
        const modOfCharacterLength = columnNumber % 26
        const charCode = modOfCharacterLength === 0 ? 26 : modOfCharacterLength
        result = getChar(charCode) + result
        columnNumber = (columnNumber - charCode) / 26

    }
    return result;
};

const getChar = (number) => {
    return String.fromCharCode(number + 65 - 1)
}
```

# 2. Climbing Stairs

https://leetcode.com/problems/climbing-stairs/

## 2.1 Summary

Dynamic programming

```
 1 -> 1
 2 -> 2
 3 -> n-2 n-1 -> 2 + 1
 4 -> n-3 n-2 -> 3 + 2
 5 -> n-4 n-3 -> 5 + 3
```

## 2.2. Code

```js
/**
 * @param {number} n
 * @return {number}
 */

var climbStairs = function (n) {
    if (n <= 2) return n
    let steps = [0, 1, 2]
    for (let i = 3; i <= n; i++) {
        steps[i] = steps[i - 1] + steps[i - 2]
    }
    return steps[n];
};

```


# 3. House Robber

https://leetcode.com/problems/house-robber/

## 3.1 Summary

Dynamic programming 

Maximum amount of N house is maximum of house N-1 and house N-2 + house N

## 3.2. Code

```js
/**
 * @param {number[]} nums
 * @return {number}
 */
var rob = function (nums) {
    const length = nums.length;
    if (length === 0) return 0;
    if (length === 1) return nums[0]

    let total = [nums[0], max(nums[0], nums[1])]

    for (let i = 2; i < length; i++) {
        total[i] = max(total[i - 1], total[i - 2] + nums[i])
    }

    return total[length - 1]
};

const max = (a, b) => a > b ? a : b
```


# 4. House Robber II

https://leetcode.com/problems/house-robber-ii/

## 4.1 Summary

Dynamic programming
Same as House Robber, Iterates from `0 -> length - 2` and `1 -> length - 1` then get maximum of them


## 4.2. Code

```js
/**
 * @param {number[]} nums
 * @return {number}
 */
 var rob = function (nums) {
    let length = nums.length;
    if (length === 0) return 0;
    if (length === 1) return nums[0]
    if (length === 2) return max(nums[0], nums[1])
    if (length === 3) return max(max(nums[0], nums[2]), nums[1])

    let dp1 = new Array(length);
    let dp2 = new Array(length);

    robber(0, length - 2, dp1, nums);
    robber(1, length - 1, dp2, nums);

    return max(dp1[length - 2], dp2[length - 1])
};

const max = (a, b = 0) => a >= b ? a : b

const robber = (start, end, dp, nums) => {
    dp[start] = nums[start]
    dp[start + 1] = max(dp[start], nums[start + 1])

    for (let j = start + 2; j <= end; j++) {
        dp[j] = max(dp[j - 1], dp[j - 2] + nums[j])
    }
}
```