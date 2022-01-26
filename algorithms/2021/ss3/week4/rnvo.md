# 1. Two Sum

https://leetcode.com/problems/two-sum/

## 1.1. Summary

 - Using Map to memorize and store values
   - If input length = 2 then return [0,1]
   - Else loops through all numbers
     - Check if the the minus result of target and current value is exists in the map
       - If so return [remainValueIndex, index]
       - Else add pair of [currentValue, index] into map

## 1.2. Code

```js
/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number[]}
 */
var twoSum = function (nums, target) {
    const length = nums.length;
    if (length == 2) return [0, 1]
    const memorizedNums = new Map([[nums[0], 0]])
    for (let i = 1; i < length; i++) {
        const remainValueIndex = memorizedNums.get(target - nums[i])
        if (remainValueIndex !== undefined) return [remainValueIndex, i]
        else memorizedNums.set(nums[i], i)
    }
};
```

# 2. Valid Parentheses

https://leetcode.com/problems/valid-parentheses/


## 2.1. Summary

- If length < 2 or length is odd then return false
- Define balance = 0, store = []
- Loop through string
  - If current character is open backet then increase balace and push current character into store array
  - Compare current character and the last character in the store
    - if its a pair and balance = 0 then return false
  - Return balance === 0

## 2.2. Code
```js
/**
 * @param {string} s
 * @return {boolean}
 */
var isValid = function (s) {
    const length = s.length;
    if (length < 2 || length % 2 !== 0) return false
    let balance = 0
    const brackets = {
        "(": ")",
        "{": "}",
        "[": "]"
    }
    const openBrackets = Object.keys(brackets)
    const store = []
    for (let i = 0; i < length; i++) {
        const char = s[i]
        if (openBrackets.includes(char)) {
            balance++
            store.push(char)
        } else {
            if (brackets[store[store.length - 1]] !== char || balance === 0) return false
            balance--
            store.pop()
        }
    }
    return balance === 0
};
```

# 3. Generate Parentheses

https://leetcode.com/problems/generate-parentheses/

## 3.1. Summary

- Using backtracking algorithm
- In each time the generateAll method is called
  - Check open brackets and close brackets
    - If open backets is less than pair
      - Call with string which appened "("
    - If close backets is less than open brackets
      - Call with string which appened ")"

## 3.2. Code

```js
/**
* @param {number} n
* @return {string[]}
*/
var generateParenthesis = function (n) {
    const result = []
    generateAll("", result, 0, 0, n)
    return result
};

function generateAll(current, result, open, close, pair) {
    if (current.length === 2 * pair) {
        result.push(current)
        return;
    }
    if (open < pair) {
        generateAll(current + "(", result, open + 1, close, pair)
    }
    if (close < open) {
        generateAll(current + ")", result, open, close + 1, pair)
    }
}
```