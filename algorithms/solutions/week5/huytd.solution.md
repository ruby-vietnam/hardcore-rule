# Problem 1: Pascal Triangle

URL: https://leetcode.com/problems/pascals-triangle-ii/description/

Status: Accepted

This approach uses O(k) space. The idea is simple: Pre-allocate the result array and fill it with 1. Then do the same calculation over and over again on the result array for each row, the last row will produce the desired result.

```javascript
var getRow = function(rowIndex) {
  let pascal = [];
  for (let i = 0; i < rowIndex+1; i++) { pascal[i] = 1; }
  for (let i = 1; i < rowIndex; i++) {
    for (let j = i; j >= 1; j--) {
      pascal[j] += pascal[j - 1];
    }
  }
  return pascal;
};
```

# Problem 2: Valid Parenthesis String

URL: https://leetcode.com/problems/valid-parenthesis-string/description/

Status: 49/58 cases passed (a.k.a Not Accepted)

My approach is using a stack to push all of `(` and `*`, pop when a `)` is found, later on, filter it again to remove all `*)` pairs.

```javascript
var checkValidString = function(s) {
  let stack = [];
  let arr = s.split('');
  while (arr.length) {
    let c = arr.shift();
    if (c == '(' || c == '*') stack.push(c);
    if (c == ')') {
      if (!stack.length) return false;
      if (stack[stack.length - 1] == '(') { stack.pop(); }
      else if (stack[0] == '(') { stack.shift(); }
    }
  }
  while (stack[stack.length - 1] == '*') {
    stack.pop();
    if (stack[stack.length - 1] == '(') stack.pop();
  }
  return !stack.length;
};
```

# Problem 3: Russian Doll Envelopes

URL: https://leetcode.com/problems/russian-doll-envelopes/description/

Status: 35/85 cases passed (a.k.a Not Accepted)

I dunno, I just bruteforce it :(

```javascript
var maxEnvelopes = function(input) {
  let maxLen = 0;
  let arr = [];
  input.sort((a, b) => a[0] >= b[0] && a[1] >= b[1]);
  for (let i = 0; i < input.length; i++) {
    arr = [input[i]];
    let pos = 0;
    for (j = 0; j < input.length; j++) {
      if (input[j][0] > arr[pos][0] && input[j][1] > arr[pos][1]) {
        arr.push(input[j]);
        pos++;
      }
    }
    if (maxLen < arr.length) maxLen = arr.length;
  }   
  return maxLen;
};
```
