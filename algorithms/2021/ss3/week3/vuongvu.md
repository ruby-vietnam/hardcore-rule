# 1. Binary Tree Paths

https://leetcode.com/problems/binary-tree-paths/

## 1.1. Summary

- use recursive function to get all paths from root to node

## 1.2. Code

```js
const binaryTreePaths = function (root) {
  const list = findPathStr("", root);
  return list.split(",");
};

const findPathStr = function (pathStr, node) {
  const nextStr = `${pathStr ? `${pathStr}->` : ""}${node.val}`;

  if (!node.left && !node.right) return nextStr;

  if (node.left && node.right) {
    return `${findPathStr(nextStr, node.left)},${findPathStr(
      nextStr,
      node.right
    )}`;
  }

  if (node.left) {
    return findPathStr(nextStr, node.left);
  }

  return findPathStr(nextStr, node.right);
};
```

# 2. Find K Closest Elements

https://leetcode.com/problems/find-k-closest-elements/

## 2.1. Summary

## 2.2. Code

```js
const findClosestElements = function (arr, k, x) {
  let closestStartIndex = 0;
  let found = false;
  let i = k;

  while (!found && i < arr.length) {
    const lastElementDistance = Math.abs(arr[i - k] - x);
    const newElementDistance = Math.abs(arr[i] - x);

    if (lastElementDistance > newElementDistance) {
      closestStartIndex = i - k + 1;
    } else if (arr[i - k] !== arr[i]) {
      found = true;
    }

    i++;
  }

  return arr.slice(closestStartIndex, closestStartIndex + k);
};
```
