# 1. Binary Tree Paths

https://leetcode.com/problems/binary-tree-paths/

## 1.1. Summary

- use recursive function to get all paths from root to node

## 1.2. Code

```js
const binaryTreePaths = function (root) {
  const list = findPathStr(root, "");
  return list.split(",");
};

const findPathStr = function (node, pathStr) {
  const nextStr = `${pathStr ? `${pathStr}->` : ""}${node.val}`;

  if (!node.left && !node.right) return nextStr;

  if (node.left && node.right) {
    return `${findPathStr(node.left, nextStr)},${findPathStr(
      node.right,
      nextStr
    )}`;
  }

  if (node.left) {
    return findPathStr(node.left, nextStr);
  }

  return findPathStr(node.right, nextStr);
};
```

# 2. Find K Closest Elements

https://leetcode.com/problems/find-k-closest-elements/

## 2.1. Summary

- intial a closest array start index with default value 0 (closest array will start from 0 to k from input arr)
- let a value i run from k to `arr.length`
  - whenever input |arr[i - k] - x| > |arr[i] - x| (start element farther than new last element)
    - then assign a new start index
  - whenever the condition above is not matched and value at arr[i - k] !== arr[i]
    - then we stop the loop (arr input is sorted)
- return array with assigned start index from input array

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

# 3. Sum Root to Leaf Numbers

https://leetcode.com/problems/sum-root-to-leaf-numbers/submissions/

## 3.1. Summary

- use recursive function to get all paths from root to node
- calculate the sum of each path

## 3.2. Code

```js
const sumNumbers = function (root) {
  const paths = findPathStr(root, "").split(",");
  return paths.reduce((sum, cur) => sum + parseInt(cur), 0);
};

const findPathStr = function (node, pathStr) {
  const nextStr = `${pathStr}${node.val}`;

  if (!node.left && !node.right) return nextStr;

  if (node.left && node.right) {
    return `${findPathStr(node.left, nextStr)},${findPathStr(
      node.right,
      nextStr
    )}`;
  }

  if (node.left) {
    return findPathStr(node.left, nextStr);
  }

  return findPathStr(node.right, nextStr);
};
```
