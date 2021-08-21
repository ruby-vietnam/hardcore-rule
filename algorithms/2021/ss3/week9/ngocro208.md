# 1. umber of Strings That Appear as Substrings in Word
https://leetcode.com/problems/number-of-strings-that-appear-as-substrings-in-word/

## 1.1 Summary



## 1.2. Code

```js
/**
 * @param {string[]} patterns
 * @param {string} word
 * @return {number}
 */
var numOfStrings = function(patterns, word) {
    return patterns.reduce((nums,p) => {
        return word.includes(p) ? nums + 1 : nums;
    },0)
};
```

# 2. Check If String Is a Prefix of Array

https://leetcode.com/problems/check-if-string-is-a-prefix-of-array/

## 2.1 Summary

## 2.2. Code

```js
/**
 * @param {string} s
 * @param {string[]} words
 * @return {boolean}
 */
var isPrefixString = function(s, words) {
    const len = s.length;

    let temp = '';
    for(let i=0; i<len; i++) {
        if(temp.length <len) {
            temp += words[i];
        } else {
            break;
        }
    }
    
    return temp === s;
};
```


# 3. Array With Elements Not Equal to Average of Neighbors

https://leetcode.com/problems/array-with-elements-not-equal-to-average-of-neighbors/

## 3.1 Summary

## 3.2. Code

```js
/**
 * @param {number[]} nums
 * @return {number[]}
 */

var rearrangeArray = function(nums) {
    nums.sort((a,b)=>a-b);

    const arr=[], length = arr.length;
    let index=0; // Start with even index
    
    for(let i=0;i<nums.length;i++){
        arr[index]=nums[i]
        index+=2 
        if(index>=nums.length) index=1 // Reset to 1 -> put remain odd indexes
    }
    return arr;
};
```
