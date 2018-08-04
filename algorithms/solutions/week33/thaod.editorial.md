## Problem 1

https://leetcode.com/problems/middle-of-the-linked-list

There are many solutions for this easy problem:

### Solution 1:

Travel all list nodes to count list size, then travel list nodes from head to `mid = roundDown(size/2)` to get middle node.

Time complexity: `O(n + roundDown(n/2))` => `O(n)`
Space complexity: `O(1)`

```javascript
/**
 * @param {ListNode} head
 * @return {ListNode}
 */
const middleNode = (head) => {
  let size = 0;
  let node = head;
  while (node) {
    size++;
    node = node.next;
  }

  if (size = 0) {
    return null;
  }

  let i = 0;
  let mid = Math.floor(size/2);
  node = head;
  while(i < mid) {
    node = node.next;
    i++;
  }
  return node;
};
```

### Solution 2:

Travel all list nodes to count list size and store nodes into an array. Middle node is the array item having `index = roundDown(size/2)`.

Time complexity: `O(n)`
Space complexity: `O(n)` - Because we need an array to store all nodes of the list

```javascript
/**
 * @param {ListNode} head
 * @return {ListNode}
 */
const middleNode = (head) => {
  let size = 0;
  let node = head;
  const arr = [];
  while (node) {
    arr.push(node);
    size++;
    node = node.next;
  }
  return arr[Math.floor(size/2)];
};
```

_Note: In practice, the time cost will not be O(n), because of the cost for allocating new item into array `arr.push(node)`_

### Solution 3:

Use one variable `i` as one node jumper, another variable `j` as two nodes jumper. With this, it's only take `roundDown(n/2)` jumps for `j` to be at the element `nth` (or `n+1th` for even `n` - outside of the nodes list). At that time, since the `i` jumper is half-time slower than the `j` jumper, `i` will point to the middle node that we need to find.

This solution is the best of 3 IMHO, since it takes less time and space.

Time complexity: `O(roundDown(n/2))` => `O(n)`
Space complexity: `O(1)`

```javascript
const middleNode3 = (head) => {
  let oneStep = head;
  let twoSteps = head;
  while (twoSteps !== null && twoSteps.next !== null) {
    oneStep = oneStep.next;
    twoSteps = twoSteps.next.next;
  }
  return oneStep;
};
```

## Problem 2

https://www.codewars.com/kata/scheduling-shortest-job-first-or-sjf

### Solution:

To calculate the clock-cycles (cc) to finish the `ith` job, we need to calculate the total cc of jobs that having cc less than the `ith` job (SJF). For jobs that having cc as same as the `ith` job, only use jobs that having index less than `i` (FIFO).

Time complexity: `O(n)`
Space complexity: `O(1)`

```javascript
function SJF(jobs, index) {
  const job = jobs[index];
  let cc = job;
  for (i = 0; i < jobs.length; i++) {
    if ((jobs[i] < job) || (jobs[i] === job && i < index)) {
      cc += jobs[i];
    }
  }

  return cc;
}
```

## Problem 3

https://www.hackerrank.com/challenges/value-of-friendship

### Solution

TODO

## Problem 4

https://www.codewars.com/kata/twice-linear

These two solutions share a same concept - to produce a sequence according to the rules, so that the sequence contains the item at `n` index we need to find.
The difference is how to build the needed sequence as quick as possible, to avoid exceeding allowed time limit.

### Solution 1 - Time limit exceeded

Add two numbers generated from each `u[i]`, then immediately sort the whole `u` to have an ascending sequence. Using a key-value data structure (object for JS) to store existed number to quickly check and ignore duplication.

Time complexity: `O(n^2)`
Space complexity: `O(n)`


```javascript
/**
 *
 * @param {number} n
 * @returns number
 */
const dblLinear1 = (n) => {
  let u = [1];
  const existed = {
    1: true
  };

  for (let i = 0; i <= n; i++) {
    const d = 2 * u[i] + 1;
    const t = 3 * u[i] + 1;

    if (!existed[d]) {
      u.push(d);
      existed[d] = true;
    }

    if (!existed[t]) {
      u.push(t);
      existed[t] = true;
    }

    u = u.sort((ua, ub) => ua < ub ? -1 : ua > ub ? 1 : 0);
  }

  return u[n];
}
```

### Solution 2

1. Since we only need the array at `n` index, building a sequence having length greater than `n+1` is wasting.
2. Try to analyse the sequence rule as following:

  2.1. With `i < j`, `ui < uj` (no `=` - no duplication)
  2.2. From (2.1), we have `ui * 2 + 1` appears before `ui *3 + 1`.
  2.2. Also from (2.1), we have `ui * 2 + 1` appears before `uj * 2 + 1`.
  2.3. Also from (2.1), we have `ui * 3 + 1` appears before `uj * 3 + 1`.
  2.4. *But for `ui * 3 + 1` and `uj * 2 + 1`*, the appearance depend on result of their comparation.

Now, we can try to manually build our sequence from what we have broken down.

```
[1]
1*3 + 1 > 1*2 + 1 => [1, 1*2 + 1 = 3]
1*3 + 1 < 3*2 + 1 => [1, 3, 1*3 + 1 = 4]
3*3 + 1 > 3*2 + 1 => [1, 3, 4, 3*2 + 1 = 7]
3*3 + 1 > 4*2 + 1 => [1, 3, 4, 7, 4*2 + 1 = 9]
3*3 + 1 < 7*2 + 1 => [1, 3, 4, 7, 9, 3*3 + 1 = 10]
4*3 + 1 < 7*2 + 1 => [1, 3, 4, 7, 9, 10, 4*3 + 1 = 13]
7*3 + 1 > 7*2 + 1 => [1, 3, 4, 7, 9, 10, 13, 7*2 + 1 = 15]
7*3 + 1 > 9*2 + 1 => [1, 3, 4, 7, 9, 10, 13, 15, 9*2 + 1 = 19]
7*3 + 1 > 10*2 + 1 => [1, 3, 4, 7, 9, 10, 13, 15, 19, 10*2 + 1 = 21]
7*3 + 1 < 13*2 + 1 => [1, 3, 4, 7, 9, 10, 13, 15, 19, 21, 7*3 + 1 = 22]
9*3 + 1 vs 13*2 + 1 => [1, 3, 4, 7, 9, 10, 13, 15, 19, 21, 22, ...]
```

So, for implementation, we can use two variables as pointer to represent for `ui` & `uj`. Then build the sequence base on the comparation of `ui * 3 + 1` vs `uj * 2 + 1`.

Time complexity: `O(n)`
Space complexity: `O(n)`

```javascript
/**
 *
 * @param {number} n
 * @returns number
 */
const dblLinear2 = (n) => {
  let u = [1];
  if (n <= u.length - 1) {
    return u[n];
  }

  let i = 0;
  let j = 0;

  while (u.length <= n) {
    if ((u[i] * 3 + 1) > (u[j] * 2 + 1)) {
      u.push(u[j] * 2 + 1);
      j++;
    } else if ((u[i] * 3 + 1) < (u[j] * 2 + 1)) {
      u.push(u[i] * 3 + 1);
      i++;
    } else {
      u.push(u[i] * 3 + 1);
      i++;
      j++;
    }
  }

  return u[n];
}
```
