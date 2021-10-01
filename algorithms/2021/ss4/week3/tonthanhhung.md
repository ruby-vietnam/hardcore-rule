## 1. [590] N-ary Tree Postorder Traversal

https://leetcode.com/problems/n-ary-tree-postorder-traversal/

### 1.1 Approach

- Use Stack
- Using recursive

### 1.2 Code

```js
function Node(val, children) {
  this.val = val;
  this.children = children;
};

/**
 * Approach 1: Using Stack
 * @param {Node|null} root
 * @return {number[]}
 */
var postorder = function (root) {
  if (root == null) return [];
  let ret = [];
  let stack = [root];
  while (stack.length != 0) {
    let top = stack.pop()
    if (top.children == null) {
      ret.push(top);
    } else {
      stack.push(top.val);
      for (let i = top.children.length - 1; i >= 0; i--) {
        stack.push(top.children[i])
      }
    }
  }
  return ret
};


/**
 * Approach 2: Using Recusive
 * @param {Node|null} root
 * @return {number[]}
 */
var postorder = function (root) {
  if (root == null) return [];
  if (root.children == null) {
    return [root.val]
  }
  let ret = []
  for (const childNode of root.children) {
    ret.push(...postorder(childNode))
  }
  ret.push(root.val);
  return ret

};
```

## 2. [589] N-ary Tree Preorder Traversal

https://leetcode.com/problems/n-ary-tree-preorder-traversal/

### 2.1 Approach

- Using recursive
- Use Stack

### 2.2 Code

```js
/**
 * Approach Using Recusive
 * @param {Node|null} root
 * @return {number[]}
 */
var preorder = function (root) {
    if (root == null) return [];
    if (root.children == null) {
      return [root.val]
    }
    let ret = []
    ret.push(root.val);
    for (const childNode of root.children) {
      ret.push(...preorder(childNode))
    }
    return ret
  };
```

## 3. [102] Binary Tree Level Order Traversal

https://leetcode.com/problems/binary-tree-level-order-traversal/

### 3.1 Approach

- Using DSF

### 3.2 Code

```js

/**
 * @param {TreeNode} root
 * @return {number[][]}
 */

var levelOrder = function (root) {
  const ret = []
  void function dfs(root, level) {
    if (root == null) return;
    if (ret[level] == null) {
      ret[level] = []
    }
    ret[level].push(root.val)
    root.left != null && dfs(root.left, level + 1, ret)
    root.right != null && dfs(root.right, level + 1, ret)
  }(root, 0)
  return ret
};


```


## 4. [652] Find Duplicate Subtrees

https://leetcode.com/problems/find-duplicate-subtrees/

### 4.1 Approach

- Using DSF combination with hashtable to keep track the tree structure

### 4.2 Code
```js

/**
 * @param {TreeNode} root
 * @return {TreeNode[]}
 */
var findDuplicateSubtrees = function (root) {
  const ret = {}
  const treeM = []
  void function dfs(root) {
    if (root == null) return "";
    const path = `${root.val}L${dfs(root.left)}R${dfs(root.right)}`
    if (treeM.includes(path)){
      ret[path] = root
    }else{
      treeM.push(path)
    }
    return path;
  }(root, treeM);
  return Object.values(ret)
};

```
