# Problem 1

```javascript
const pathSum = (root, sum) => {
    if (!root) return 0; 
    return sumNode(root, sum) + pathSum(root.left, sum) + pathSum(root.right, sum);
};

const sumNode = (node, sum) => {
    if (!node) return 0;
    return (node.val === sum ? 1 : 0) + sumNode(node.left, sum - node.val) + sumNode(node.right, sum - node.val);
};
```
