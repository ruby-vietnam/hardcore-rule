# Problem 1: Valid Palindrome II

URL: https://leetcode.com/problems/valid-palindrome-ii/description/

Status:
```
  ✔ Accepted
  ✔ 460/460 cases passed (112 ms)
  ✔ Your runtime beats 100 % of javascript submissions
```

So, we simply check from the two ends of the string, for each character, if they're the same, so they probably part of a palindrome.

But if they're not, so one of them should be the one we need to remove in order to make a palindrome, so we simply create two new string that remove both of them, then check if the two new strings are palindrome or not.

By repeating this process, eventually we will find out if the string can be palindrome by removing just a single character or not.

```javascript
var validPalindrome = function(s) {
    let i = 0; let lf = lr = "";
    let len = s.length; let left_bound = -1;
    let mid = ~~(len / 2);
    for (i = 0; i < mid; i++) {
        left_bound = len - 1 - i;
        if (s[i] !== s[left_bound]) {
            lf = excludeChar(s, i);
            lr = excludeChar(s, left_bound);
            return isPalindrome(lf) || isPalindrome(lr);
        }
    }
    return true;
};

var isPalindrome = (s) => {
    let len = s.length; let mid = ~~(len / 2);
    for (let i = 0; i < mid; i++) {
        if (s[i] !== s[len - 1 - i]) return false;
    }
    return true;
};

var excludeChar = function(s, i) {
    return s.substr(0, i) + s.substr(i+1);
};
```

# Problemm 2: Flatten Binary Tree

URL: https://leetcode.com/problems/flatten-binary-tree-to-linked-list/description/

Status;
```
  ✔ Accepted
  ✔ 225/225 cases passed (68 ms)
  ✔ Your runtime beats 100 % of javascript submissions
```

Leetcode is broken.

```javascript
var flatten = function(root) {
    if (!root) return;
    let stack = [root];
    while (stack.length) {
        let t = stack.pop();
        if (t.right) stack.push(t.right);
        if (t.left) stack.push(t.left);
        if (stack.length) t.right = stack[stack.length - 1];
        t.left = null;
    }
};
```
