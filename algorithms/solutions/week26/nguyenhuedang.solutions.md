# Week 26

## Problem 1 - [Find the Difference] (https://leetcode.com/problems/find-the-difference)

```javascript
/**
 * @param {string} s
 * @param {string} t
 * @return {character}
 */

const getXor = (s) => {
  let res = 0;
  for (const i in s) {
    res ^= s.charCodeAt(i);
  }
  return res;
}

var findTheDifference = function(s, t) {
  return String.fromCharCode(
    getXor(s) ^ getXor(t)
  )
};
```

## Problem 2 - [Binary Tree Level Order Traversal] (https://leetcode.com/problems/binary-tree-level-order-traversal)

```javascript
/**
 * Definition for a binary tree node.
 * function TreeNode(val) {
 *     this.val = val;
 *     this.left = this.right = null;
 * }
 */
/**
 * @param {TreeNode} root
 * @return {number[][]}
 */

var levelOrder = function(root) {
  let rows = [];

  function visit(node, index) {
    if (node) {
      rows[index] = rows[index] || [];
      rows[index].push(node.val);
      visit(node.left, index + 1);
      visit(node.right, index + 1);
    }
  }

  visit(root, 0);
  return rows;
};
```
