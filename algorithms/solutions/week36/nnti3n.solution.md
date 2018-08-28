# Problem 1
 ```javascript
/**
 * @param {number} n
 * @return {number}
 */
var cache = [];
var climbStairs = function(n) {
  var cached = cache[n];
    if (cached)
    {
        return cached;
    }
    if (n == 0 ) {
      return 1
    }
    if (n < 0) {
      return 0
    }
  return (cache[n] = climbStairs(n-1) + climbStairs(n-2))
};

```

# Problem 2
 ```javascript
/**
 * @param {string} s
 * @return {number}
 */
var lengthOfLongestSubstring = function(s) {
  var length = 0;
  var dict;
  for (let i = 0; i< s.length; i++) {
    dict = {};
    temp_length = 0;
    for (let j = i; j < s.length; j++) {
      if (!dict[s[j]]) {
        dict[s[j]] = true;
        temp_length++;
        if (temp_length > length) {
          length = temp_length;
        }
      } else {
        break;
      }
    }
  }
  return length;
};

```
