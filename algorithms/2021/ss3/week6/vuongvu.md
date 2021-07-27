# 1. Excel Sheet Column Title

https://leetcode.com/problems/linked-list-cycle/

## 1.1. Summary

- use 2 cursors:
  - slow - move 1 node at a time
  - fast - move 2 nodes at a time
- when fast cursor is null => no cycle
- when fast cursor is the same node as slow cursor => has cycle

## 1.2. Code

```js
const hasCycle = function (head) {
  let slow = head;
  let fast = head;

  while (fast?.next?.next) {
    slow = slow.next;
    fast = fast.next.next;

    if (slow === fast) {
      return true;
    }
  }

  return false;
};
```

# 2. Excel Sheet Column Title

https://leetcode.com/problems/intersection-of-two-linked-lists/

## 2.1. Summary

- loop through 2 lists and store all nodes in an object
- check if the node is already stored, return the node

## 2.2. Code

```js
const getIntersectionNode = function (headA, headB) {
  const memo = {};
  let nodeA = headA;
  let nodeB = headB;

  while (nodeA || nodeB) {
    if (nodeA) {
      const key = nodeA.val;

      if (nodeA === nodeB || (memo[key] && memo[key].includes(nodeA))) {
        return nodeA;
      }

      memo[key] = (memo[key] || []).concat(nodeA);
      nodeA = nodeA.next;
    }

    if (nodeB) {
      const key = nodeB.val;

      if (memo[key] && memo[key].includes(nodeB)) {
        return nodeB;
      }

      memo[key] = (memo[key] || []).concat(nodeB);
      nodeB = nodeB.next;
    }
  }

  return null;
};
```

# 3. Binary Search Tree Iterator

https://leetcode.com/problems/binary-search-tree-iterator/

## 3.1. Summary

- Use a stack to store nodes
- next method push nodes to stack in order
- hasNext method check if the stack is empty

## 3.2. Code

```js
const BSTIterator = function (root) {
  this.head = root;
  this.list = [];
};

BSTIterator.prototype.next = function () {
  while (this.head !== null) {
    this.list.push(this.head);
    this.head = this.head.left;
  }

  this.head = this.list.pop();
  const current = this.head.val;
  this.head = this.head.right;
  return current;
};

BSTIterator.prototype.hasNext = function () {
  return this.head !== null || this.list.length > 0;
};
```
