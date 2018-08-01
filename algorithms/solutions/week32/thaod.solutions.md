## Problem 1

```javascript
/**
 * @param {TreeNode} root1
 * @param {TreeNode} root2
 * @return {boolean}
 */
const leafSimilar = (root1, root2) => {
  let leafSeq1 = getLeafSeq(root1);
  let leafSeq2 = getLeafSeq(root2);
  return leafSeq1 === leafSeq2;
};

/**
 * @param {TreeNode} node
 * @return {string}
 */
const getLeafSeq = (node, leafSeq = '') => {
  if (!node) return;
  if (!node.left && !node.right) leafSeq += `:${node.val}`;
  if (node.left) leafSeq = getLeafSeq(node.left, leafSeq);
  if (node.right) leafSeq = getLeafSeq(node.right, leafSeq);
  return leafSeq;
}
```
