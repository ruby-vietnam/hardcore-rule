## Problem 2

```javascript
/**
 * @param {TreeNode} root
 * @return {number[][]}
 */
const levelOrder = function(root) {
  if (!root) { return []; }

  root.visited = true;
  root.level = 0;
  const queue = [root];
  const order = [[root.val]];

  while (Array.isArray(queue) && queue.length > 0) {
    v = queue.shift();
    const level = v.level + 1;

    const children = order[level] || [];
    if (v.left && !v.left.visited) {
      v.left.visited = true;
      v.left.level = v.level + 1;
      queue.push(v.left);
      children.push(v.left.val);
    }

    if (v.right && !v.right.visited) {
      v.right.visited = true;
      v.right.level = v.level + 1;
      queue.push(v.right);
      children.push(v.right.val);
    }

    if (children.length > 0) {
      order[level] = children;
    }
  }

  return order;
};
```
