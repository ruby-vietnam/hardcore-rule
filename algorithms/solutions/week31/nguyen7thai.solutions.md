## Problem 2
https://leetcode.com/problems/binary-tree-maximum-path-sum/description/

```
/**
 * Definition for a binary tree node.
 * function TreeNode(val) {
 *     this.val = val;
 *     this.left = this.right = null;
 * }
 */
/**
 * @param {TreeNode} root
 * @return {number}
 */

var transverse = function(root, result) {
    var left = Number.MIN_SAFE_INTEGER
    var right = Number.MIN_SAFE_INTEGER
    var total = root.val
    if (root.left) {
        left = transverse(root.left, result)
        total += left
    }
    if (root.right) {
        right = transverse(root.right, result)
        total += right
    }
    var maxRoot = Math.max(root.val, root.val + left, root.val + right)
    result.max = Math.max(result.max, maxRoot, total)
    return maxRoot
}

var maxPathSum = function(root) {
    var result = { max: Number.MIN_SAFE_INTEGER }
    transverse(root, result)
    return result.max
};
```
