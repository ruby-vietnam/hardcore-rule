# 1. Reverse Bits

https://leetcode.com/problems/reverse-bits/

## 1.1 Summary

## 1.2. Code

```js
/**
 * @param {number} n - a positive integer
 * @return {number} - a positive integer
 */
var reverseBits = function(n) {
    // Parse to binary then assign into 32 bits, reverse. Convert to interger
    return parseInt([...`${Number(n).toString(2)}`.padStart(32,0)].reverse().join(''),2)
};
```

# 2. Number of 1 Bits

https://leetcode.com/problems/number-of-1-bits/

## 2.1 Summary

## 2.2. Code

```js
/**
 * @param {number} n - a positive integer
 * @return {number}
 */
var hammingWeight = function(n) {
    // Parse to binary then filter the appearance of 1
    return [...n.toString(2).padStart(32,0)].filter(c=>c==1).length
};
```


# 3. Longest Repeating Character Replacement

https://leetcode.com/problems/longest-repeating-character-replacement/

## 3.1 Summary

Using Sliding window
Store the frequency of char into map then get Max

## 3.2. Code

```js
/**
 * @param {string} s
 * @param {number} k
 * @return {number}
 */
var characterReplacement = function(s, k) {
    let start = 0, map = new Map(), maxCount = 0, maxLength = 0;
    
    for(let end = 0; end < s.length; end++){
        map.set(s[end], map.get(s[end]) + 1 || 1);
        maxCount = Math.max(maxCount, map.get(s[end]));
        
        while(end - start - maxCount + 1 > k){
            map.set(s[start], map.get(s[start]) - 1);
            start++
        }
        
        maxLength = Math.max(maxLength, end - start + 1);
    }
    
    return maxLength;
};
```
