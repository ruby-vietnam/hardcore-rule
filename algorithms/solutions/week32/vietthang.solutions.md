# Problem 1

```js
/**
 * Definition for a binary tree node.
 * function TreeNode(val) {
 *     this.val = val;
 *     this.left = this.right = null;
 * }
 */
/**
 * @param {TreeNode} root1
 * @param {TreeNode} root2
 * @return {boolean}
 */
var leafSimilar = function(root1, root2) {
    let leafs = []
    let idx = 0
    let isFirst = true
    let res = true
    
    function findSequence(node) {
        if (node !== null) {
            if (node.left === null && node.right === null) {
                if (isFirst) {
                    leafs.push(node.val)
                } else if (leafs[idx++] !== node.val) {
                    return res = false
                }
            }            
            findSequence(node.left)
            findSequence(node.right)
        }        
    }
    
    findSequence(root1)
    isFirst = false
    findSequence(root2)
    
    return res && leafs.length === idx
};
```
