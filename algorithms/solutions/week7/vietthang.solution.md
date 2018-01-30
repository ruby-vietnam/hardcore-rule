# Problem set 1:

```js
/**
 * Definition for a binary tree node.
 * function TreeNode(val) {
 *     this.val = val;
 *     this.left = this.right = null;
 * }
 */
/**
 * @param {TreeNode} root
 * @return {boolean}
 */
const isSymmetric = (root) => {    
    return !root || checkSymmetric(root.left, root.right)
}

const checkSymmetric = (Left, Right) => {
    if (!Left || !Right) return Right === Left
    return Left.val === Right.val &&  checkSymmetric(Left.left, Right.right) && checkSymmetric(Left.right, Right.left)
}
```
