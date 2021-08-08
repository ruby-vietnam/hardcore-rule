# 1. Linked List Cycle

https://leetcode.com/problems/linked-list-cycle

## 1.1. Summary

- Use slow and fast strategy.
- The slow node goes step by step while the fast one goes 2 steps.
- If they meet the other, the list has cycle.

## 1.2. Code

```js
/**
 * Definition for singly-linked list.
 * function ListNode(val) {
 *     this.val = val;
 *     this.next = null;
 * }
 */

/**
 * @param {ListNode} head
 * @return {boolean}
 */
var hasCycle = function(head) {
    if (!head || head.next == null) return false;
    let slow = head;
    let fast = head;
    while (fast.next && fast.next.next) {
        fast = fast.next.next;
        slow = slow.next;
        if (fast == slow) return true;
    }
    return false;
};
```

# 2. Intersection of Two Linked Lists

https://leetcode.com/problems/intersection-of-two-linked-lists

## 2.1. Summary

- Imagine 2 lists meet each other at node X
```
ListA[m] = X
ListB[n] = X

Distance from X to the end of list is p.
Becaus of `m + p + n + p = n + p + m + p`
So we go through a List, if we meet the end of list, we switch to the other. After `m + p + n` steps, the two lists point to the same node if they have intersection.

```

## 2.2. Code

```js
/**
 * Definition for singly-linked list.
 * function ListNode(val) {
 *     this.val = val;
 *     this.next = null;
 * }
 */

/**
 * @param {ListNode} headA
 * @param {ListNode} headB
 * @return {ListNode}
 */
var getIntersectionNode = function(headA, headB) {
    if (!headA || !headB) return null;
    let A = headA;
    let B = headB;
    while (A !== B) {
        A = A ? A.next : headB;
        B = B ? B.next : headA;
    }
    return A;
};
```

# 3. Binary Search Tree Iterator

https://leetcode.com/problems/binary-search-tree-iterator

## 3.1. Summary

- Use stack to store all nodes.
- Because left tree is always smaller than right tree so we push only the left tree to the stack.
- HasNext() check if stack is not empty
- Next() pop the stack, if the poped node has right node, push the left tree (if has) of the right node into the stack.

## 3.2. Code

```js
/**
 * Definition for a binary tree node.
 * function TreeNode(val, left, right) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.left = (left===undefined ? null : left)
 *     this.right = (right===undefined ? null : right)
 * }
 */
/**
 * @param {TreeNode} root
 */
var BSTIterator = function(root) {
    this._stack = [];
    this.pushStack(root);
};

BSTIterator.prototype.pushStack = function(node) {
    while (node) {
        this._stack.push(node);
        node = node.left;
    }
}

/**
 * @return {number}
 */
BSTIterator.prototype.next = function() {
    if (this._stack.length == 0) return null;
    const currentNode = this._stack.pop();
    if (currentNode.right) {
        this.pushStack(currentNode.right);
    }
    return currentNode.val;
};

/**
 * @return {boolean}
 */
BSTIterator.prototype.hasNext = function() {
  return this._stack.length > 0;  
};

/** 
 * Your BSTIterator object will be instantiated and called as such:
 * var obj = new BSTIterator(root)
 * var param_1 = obj.next()
 * var param_2 = obj.hasNext()
 */
```