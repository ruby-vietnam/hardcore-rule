# Problem 1

```js
/**
 * @param {string} s
 * @return {boolean}
 */
var validPalindrome = function(s) {
    let pop = false, i = 0; j= s.length - 1

    while (i < j) {
        if (s[i] !== s[j]) return checkPali(s, i+1, j) || checkPali(s, i, j-1)
        i++
        j--
    }

    return true
};

var checkPali = function(s, i, j) {
    while(i < j) {
        if (s[i] !== s[j]) return false
        i++
        j--
    }
    return true
}
```

# Problem 2

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
 * @return {void} Do not return anything, modify root in-place instead.
 */
var flatten = function(root) {
    let stack = []

    while(root !== null || stack.length !== 0){
        // if root.right -> push to stack
        if (root.right !== null) {
            stack.push(root.right)
        }

        // Replace right right with left node if the left !== null. Vice versa, replace right node with the node in stack.
        if (root.left !== null) {
            root.right = root.left
            root.left = null
        } else if (stack.length !== 0) {
            let node = stack.pop()
            root.right = node
        }

        root = root.right
    }
};
```
