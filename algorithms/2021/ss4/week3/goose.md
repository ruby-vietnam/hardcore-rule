# 1. N-ary Tree Postorder Traversal
https://leetcode.com/problems/n-ary-tree-postorder-traversal/

## 1.1. Approach
Using stack

## 1.2. Code
```js
/**
 * // Definition for a Node.
 * function Node(val,children) {
 *    this.val = val;
 *    this.children = children;
 * };
 */

/**
 * @param {Node|null} root
 * @return {number[]}
 */
var postorder = function (root) {
  if (!root) return [];

  let result = [];
  let stack = [root];
  let visited = new Set();
  while (stack.length) {
    const top = stack[stack.length - 1];
    if (top.children.length === 0 || visited.has(top)) {
      stack.pop();
      result.push(top.val);
    } else {
      stack.push(...top.children.reverse());
      visited.add(top);
    }
  }

  return result;
};
```

# 2 [589] N-ary Tree Preorder Traversal
https://leetcode.com/problems/n-ary-tree-preorder-traversal/

## 2.1. Approach
Using stack

## 2.2. Code
```js
/**
 * // Definition for a Node.
 * function Node(val, children) {
 *    this.val = val;
 *    this.children = children;
 * };
 */
/**
 * @param {Node} root
 * @return {number[]}
 */
var preorder = function (root) {
  if (!root) return [];

  let result = [];
  let stack = [root];
  while (stack.length) {
    const top = stack.pop();
    result.push(top.val);
    if (top.children.length !== 0) {
      stack.push(...top.children.reverse());
    }
  }

  return result;
};
```

# 3. Binary Tree Level Order Traversal
https://leetcode.com/problems/binary-tree-level-order-traversal/

## 3.1. Approach
Self-explanatory

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
 * @return {number[][]}
 */
var levelOrder = function (root) {
  if (!root) return [];
  let result = [[root.val]];
  let currentLevel = [root];
  while (currentLevel.length) {
    currentLevel = currentLevel.reduce((acc, node) => {
      if (node.left) acc.push(node.left);
      if (node.right) acc.push(node.right);
      return acc;
    }, []);

    if (currentLevel.length) result.push(currentLevel.map(node => node.val));
  }

  return result;
};
```

# 4. Find Duplicate Subtrees
https://leetcode.com/problems/find-duplicate-subtrees/

## 4.1. Approach
My approach based on two key insights:
1. We can represent a subtree as a string with this formula <val>(l<left_val>r<right_val>). For example [1, 2, 3, 4] can represent as 1(l(2l4)r3). This makes subtree comparison becomes trivial.
2. If a node's subtree doesn't have any duplicates then its parent's subtree also doesn't have any duplicates. This helps us to prune a lot of nodes when doing tree traversal.

So the remain question is, how can we leverage the second insight to speed up our solution? We can do another traversal to pre-process the tree. We calculate the subtree depth for each node (the number in the parentheses):
          1(2)
        /   \
       2(1)  3(1)
      /     
     4(0)
If a node doesn't have any other node with both same subtree depth and same value, then such node doesn't have any duplicates. And apply the second insights stated above, any ancestor nodes of this node also doesn't have any duplicates.

## 4.2. Code
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
 * @return {TreeNode[]}
 */
var findDuplicateSubtrees = function (root) {
  let result = [];
  let subtreeOccurrences = {};
  let valueByLevel = {};

  function postOrder1(root) {
    if (root === null) return -1;
    let level;
    if (root.left === null && root.right === null) {
      level = 0;
    } else {
      const left = postOrder1(root.left);
      const right = postOrder1(root.right);
      level = Math.max(left, right) + 1;
    }

    if (level in valueByLevel) {
      if (root.val in valueByLevel[level]) valueByLevel[level][root.val]++;
      else valueByLevel[level][root.val] = 1;
    } else valueByLevel[level] = { [root.val]: 1 };

    root.level = level;
    return level;
  }


  // We post-order traversal the tree. After complete any subtree,
  // we calculate its hash as such <parent>(l<left>r<right>) and also
  // append to the result array (if already presented)
  function postOrder2(root) {
    if (root === null) return null;

    const left = postOrder2(root.left);
    const right = postOrder2(root.right);

    if (valueByLevel[root.level][root.val] < 2) return 'backtrack';
    if (left === 'backtrack' || right === 'backtrack') {
      return 'backtrack';
    }

    let hash = String(root.val);
    if (left || right) {
      hash += '(';
      if (left) hash += `l${left}`;
      if (right) hash += `r${right}`;
      hash += ')';
    }

    subtreeOccurrences[hash] = ~~subtreeOccurrences[hash] + 1;
    if (subtreeOccurrences[hash] === 2) result.push(root);
    return hash;
  }

  postOrder1(root);
  postOrder2(root);
  return Object.values(result);
};
```

# 5. Binary Tree Cameras
https://leetcode.com/problems/binary-tree-cameras/

## 5.1. Approach
My approach based on this insight: For a leaf node, we always put camera on its parent node. The reason is with a leaf node, we only have two options to put the camera which are itself and its parent node. The parent node is strictly better since it covers more nodes. Once a subtree is all watched, we can "discard" it and repeat the process.

So we defined our leaf node as such:
```js
function isLeafNode(node) {
  return (
    (node.left === null || node.left.watched) &&
    (node.right === null || node.right.watched)
  );
}
```

We do a postorder traversal. With each node we do the following:
1. If any children have camera, set `watched` to `true`
2. If it's a leaf node, do nothing
3. If it's a parent node of a leaf node, put camera on it

## 5.2. Code
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
 * @return {number}
 */
var minCameraCover = function (root) {
  let count = 0;

  function hasLeafChild(node) {
    if (node.left && isLeafNode(node.left)) return true;
    if (node.right && isLeafNode(node.right)) return true;
    return false;
  }

  function isLeafNode(node) {
    return (
      (node.left === null || node.left.watched) &&
      (node.right === null || node.right.watched)
    );
  }

  function postOrder(root) {
    if (root === null) return;
    postOrder(root.left);
    postOrder(root.right);

    if ((root.left && root.left.camera) || (root.right && root.right.camera)) {
      root.watched = true;
    }

    if (isLeafNode(root)) return;

    if (hasLeafChild(root)) {
      count++;
      root.watched = true;
      root.camera = true;
      return;
    }
  }

  let sentinelRoot = { val: 0, left: root, right: null };
  postOrder(sentinelRoot);
  return count;
};
```