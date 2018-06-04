# Week 23

## Problem 1 - [Intersection of Two Linked Lists](https://leetcode.com/problems/intersection-of-two-linked-lists)

### Solution 1

```javascript
const getLengthFrom = (node) => {
  if (!node) { return 0; }
  return 1 + getLengthFrom(node.next);
}

const getNext = (node, distance) => {
  if (!node) { return null; }
  if (distance === 0) { return node; }
  return getNext(node.next, distance - 1);
}

const getMerged = (nodeA, nodeB) => {
  if (!nodeA || !nodeB) { return null; }
  if (nodeA === nodeB) { return nodeA; }
  return getMerged(nodeA.next, nodeB.next);
}

var getIntersectionNode = function(headA, headB) {
  const lengthA = getLengthFrom(headA);
  const lengthB = getLengthFrom(headB);
  // ===
  const min = Math.min(lengthA, lengthB);
  const nodeA = getNext(headA, lengthA - min);
  const nodeB = getNext(headB, lengthB - min);
  // ===
  return getMerged(nodeA, nodeB);
};
```

### Solution 2

```javascript
var getIntersectionNode = function(headA, headB) {
  let runnerA = headA, runnerB = headB;
  let finishA = false, finishB = false;

  while (runnerA && runnerB) {
    // If both completed their first line
    if (finishA && finishB) {
      if (runnerA.val === runnerB.val) { return runnerA; }
      else if ((!runnerA) || (!runnerB)) { return null; }
    }

    // Move both forward
    runnerA = runnerA.next;
    runnerB = runnerB.next;

    // If A finished
    if (!runnerA && !finishA) {
      runnerA = headB;
      finishA = true;
    }

    // If B finished
    if (!runnerB && !finishB) {
      runnerB = headA;
      finishB = true;
    }
  }
};
```

```javascript
var getIntersectionNode = function(headA, headB) {
  let runnerA = headA;
  let runnerB = headB;

  while (runnerA !== runnerB) {
    runnerA = (runnerA === null) ? headB : runnerA.next;
    runnerB = (runnerB === null) ? headA : runnerB.next;
  }

  return runnerA;
};
```

## Problem 2 - [Simplify Path](https://leetcode.com/problems/simplify-path)

```javascript
var simplifyPath = function(path) {
  return '/' + path
    .split('/')
    .filter(nav => (nav.length && nav !== '.'))
    .reduce((current, nav) => {
      if (nav === '..') { current.pop() }
      else current.push(nav);
      return current;
    }, [])
    .join('/');
};
```
