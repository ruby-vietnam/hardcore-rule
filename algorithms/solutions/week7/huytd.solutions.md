# Problem 1: First Unique Character in a String

URL: https://leetcode.com/problems/first-unique-character-in-a-string/description/

Status: 
```
  ✔ Accepted
  ✔ 104/104 cases passed (105 ms)
  ✔ Your runtime beats 98.66 % of javascript submissions
```

There's nothing much to talk about this problem. This simple approach is **O(2n)** a.k.a **O(n)**.

```javascript
var firstUniqChar = function(s) {
  let count = Array(26).fill(0);
  let len = s.length; let c = i = 0;
  for (i = 0; i < len; i++) {
    c = s.charCodeAt(i) - 97;
    count[c]++;
  }
  for (i = 0; i < len; i++) {
    c = s.charCodeAt(i) - 97;
    if (count[c] === 1) return i;
  }
  return -1;
};
```

# Problem 2: Symmetric Tree

URL: https://leetcode.com/problems/symmetric-tree/description/

Status:
```
  ✔ Accepted
  ✔ 193/193 cases passed (100 ms)
  ✔ Your runtime beats 65.16 % of javascript submissions
```

<details>
  <summary><b>Recursive approach:</b> O(n)</summary>
  
```javascript
const isMirror = (left, right) => {
  if (!left && !right) return true;
  if (!left || !right) return false;
  return (left.val === right.val) &&
         isMirror(left.left, right.right) &&
         isMirror(left.right, right.left);
};
```

</details>

<details>
  <summary><b>Iterative approach:</b> O(n)</summary>
  
```javascript
const isMirror = (left, right) => {
  let queue = [left, right];
  while (queue.length) {
    let L = queue.shift();
    let R = queue.shift();

    if (!L && !R) continue;
    if (!L || !R) return false;
    if (L.val !== R.val) return false;

    queue.push(L.left);
    queue.push(R.right);
    queue.push(L.right);
    queue.push(R.left);
  }
  return true;
};
```

</details>

# Problem 3: Candy

URL: https://leetcode.com/problems/candy/description/

Status:
```
  ✔ Accepted
  ✔ 28/28 cases passed (113 ms)
  ✔ Your runtime beats 62.96 % of javascript submissions
```


With the N elements rating array of N childs, let's say K is the array of candies will be given to them.
Because any child will get at least 1 candy, we can init the K array and fill it with 1. So by default, each one has 1 candy.

For any i-th child, if his/her rating is greater than the previous one, N[i] > N[i-1], we can increase the number of candy he/she could be given by increase K[i]:

```
K[i] = K[i - 1] + 1
```

In case his/her rating is less than the previous one, we can give the previous one more candy, if he/she already given the same or smaller amount of candies:

```
K[i] = Max(K[i - 1], K[i] + 1)
```

Here's the code:

```javascript
var candy = function(ratings) {
  let len = ratings.length;
  let result = Array(len).fill(1);
  let i = sum = 0;
  for (i = 0; i < len; i++) {
    if (ratings[i] > ratings[i-1]) {
      result[i] = result[i-1] + 1;
    }
  }
  for (i = len - 1; i >= 0; i--) {
    if (ratings[i-1] > ratings[i]) {
      result[i-1] = Math.max(result[i-1], result[i] + 1);
    }
  }
  for (i = 0; i < len; i++) {
    sum += result[i];
  }
  return sum;
};
```
