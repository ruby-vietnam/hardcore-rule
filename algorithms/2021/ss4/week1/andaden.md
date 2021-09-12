# 1. Maximum Depth of Binary Tree
https://leetcode.com/problems/maximum-depth-of-binary-tree/

## 1.1. Summary

- Using recursive to solve this problem.

## 1.2. Code

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
var maxDepth = function(root) {
    if (root == null) return 0;
    if (root.left == null && root.right == null) {
        return 1;
    }
    return Math.max(maxDepth(root.left), maxDepth(root.right)) + 1;
};
```

# 2. Convert Sorted Array to Binary Search Tree

https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/

## 2.1. Summary

- Using recursive to solve this problem.
- Because the BST is a height-balanced one so the middle of array is the root node.
- The left tree is built from the left sub array. The similar to the right tree.

## 2.2. Code

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
 * @param {number[]} nums
 * @return {TreeNode}
 */
var sortedArrayToBST = function(nums) {
    if (nums.length === 1) {
        return new TreeNode(nums[0], null, null);
    }
    if (nums.length === 2) {
        const [num1, num2] = nums;
        const left = new TreeNode(num1, null, null);
        const root = new TreeNode(num2, left, null);
        return root;
    }
    let mid;
    if (nums.length % 2 === 0) {
        mid = nums.length / 2
    } else {
        mid = Math.ceil(nums.length / 2)- 1;
    }
    const left = sortedArrayToBST(nums.slice(0, mid));
    const right = sortedArrayToBST(nums.slice(mid + 1, nums.length));
    const root = new TreeNode(nums[mid], left, right);
    return root;
};
```

# 3. Kth Smallest Element in a BST

https://leetcode.com/problems/kth-smallest-element-in-a-bst/submissions/


## 3.1. Summary
- Convert BST to an array by using Inorder Traversal tree.

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
 * @param {number} k
 * @return {number}
 */
var kthSmallest = function(root, k) {
    const values = [];
    const stack = [];
    let currentNode = root;
    while(currentNode || stack.length !== 0) {
        while (currentNode !== null) {
            stack.push(currentNode);
            currentNode = currentNode.left;
        }
        currentNode = stack.pop();
        values.push(currentNode.val);
        currentNode = currentNode.right;
    }
    return values[k- 1];
};
```

# 4. Construct Binary Tree from Preorder and Inorder Traversal

https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/


## 4.1. Summary
- In-order:  left-> root-> right, pre-order root-> left-> right.
- So the pre-order array gives us the root of a tree is the first element.
- The in-order array gives us values in the left and right subtree.
- Note that we want to build the left subtree first because of the order of pre-order, root-> left-> right
- Using recursive to solve.
- Using a hashmap to quickly find the the array index.

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
 * @param {number[]} preorder
 * @param {number[]} inorder
 * @return {TreeNode}
 */
var buildTree = function(preorder, inorder) {
    let preorderIndex = 0;
    const map = new Map();
    for (let i = 0; i < inorder.length; i++) {
        map.set(inorder[i], i);
    }
    
    const arrayToTree = (preorder, left, right) => {
        if (left > right) return null;
        const rootValue = preorder[preorderIndex++];
        const root = new TreeNode(rootValue);
        root.left = arrayToTree(preorder, left, map.get(rootValue) - 1);
        root.right = arrayToTree(preorder, map.get(rootValue) + 1, right);
        return root;
    }
    
    return arrayToTree(preorder, 0, preorder.length - 1);
};
```