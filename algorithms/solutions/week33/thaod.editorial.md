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
