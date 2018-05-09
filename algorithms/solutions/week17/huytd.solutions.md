# Problem 1: Isomorphic Strings

URL: https://leetcode.com/problems/isomorphic-strings/description/

Status:
```
  ✔ Accepted
  ✔ 30/30 cases passed (64 ms)
  ✔ Your runtime beats 74.62 % of javascript submissions
```

Approach: We build two hashmap to track characters of each string. For each character, its value is its index in the string, so if there are two character at the same position, but has different value in the hashmap, we can say the two strings are not isomorphic.  

In the end, if both strings matched, so they're isomorphic strings.

```javascript
var isIsomorphic = function(s, t) {
    let hs = {}; let ht = {};
    let sc = 0; let tc = 0;
    let len = s.length;
    let cs = ct = 0;
    for (let i = 0; i < len; i++) {
        cs = s[i]; ct = t[i];
        if (hs[cs] == null) {
            hs[cs] = sc;
            sc++;
        }
        if (ht[ct] == null) {
            ht[ct] = tc;
            tc++;
        }
        if (hs[cs] !== ht[ct]) return false;
    }
    return true;
};
```

# Bonus: Trapping Water

Status: WIP

```
 ✘ Time Limit Exceeded
 ✘ 314/315 cases passed (N/A)
```

```javascript
var trap = function(height) {
    let water = 0;
    let highest = height.reduce((h, i) => {
        if (i > h) h = i;
        return h;
    }, 0);
    for (let level = 0; level < highest; level++) {
        let layer = height.map(i => i);
        for (let i = 0; i < height.length; i++) {
            if (height[i] !== 0) height[i] -= 1;
            if (layer[i] !== 0) layer[i] = 1;
        }
        // Detect number of 0
        let total = 0;
        let num = parseInt(layer.reverse().join("")) + "";
        num = num.split("").reverse().join("");
        num = parseInt(num) + "";
        console.log(num);
        for (let i = 0; i < num.length; i++) {
            if (num[i] === '0') total += 1;
        }
        water += total;
    }
    return water;
};
```
