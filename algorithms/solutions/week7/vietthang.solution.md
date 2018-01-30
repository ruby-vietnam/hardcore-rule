# Problem set 1:

```js
/**
 * @param {string} s
 * @return {number}
 */
const firstUniqChar = (s) =>  {
    let count = {}
    for (let i = 0; i < s.length; i++) {
        count[s[i]] = count[s[i]] + 1 || 1
    }

    for (let i = 0; i < s.length; i++) {
        if (count[s[i]] === 1) return i
    }
    return -1
}
```

# Problem set 2:

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
