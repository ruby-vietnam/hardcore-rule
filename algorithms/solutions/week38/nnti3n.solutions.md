### Problem 1

```javascript
function TreeNode(val) {
  this.val = val;
  this.left = this.right = null;
}
/**
 * @param {TreeNode} root
 * @param {number} sum
 * @return {number}
 */
var pathSum = function(root, sum) {
  // let head = setTree(0, root);
  return path(root, sum);
};

function path(root, sum) {
  if (!root) {
    return 0;
  }
  return traverse(root, sum) + path(root.left, sum) + path(root.right, sum);
}

function traverse(node, sum) {
  if (!node) {
    return 0;
  }
  return (node.val == sum ? 1 : 0) + traverse(node.left, sum - node.val) + traverse(node.right, sum - node.val);
}

function setTree(i, root) {
  if (root[i] === undefined) {
    return null
  }
  let node = new TreeNode(root[i]);
  if (root[i+1]) {node.left = setTree(i+1, root);}
  if (root[i+2]) {node.right = setTree(i+2, root);}
  return node;
}
```
