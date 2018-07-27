# Problem 1

URL: https://leetcode.com/problems/leaf-similar-trees/description/

```javascript
/*
 * [872] Leaf-Similar Trees
 * Status:
 *  ✔ Accepted
 *  ✔ 36/36 cases passed (60 ms)
 *  ✔ Your runtime beats 28.85 % of javascript submissions
 */

const travel = root => {
    let output = [];
    let stack = [root];
    let node;
    while (stack.length) {
        node = stack.pop();
        if (node.right) stack.push(node.right);
        if (node.left) stack.push(node.left);
        if (!node.left && !node.right) {
            output.push(node.val);
        }
    }
    return output;
};

const leafSimilar = (root1, root2) => {
    let l1 = travel(root1);
    let l2 = travel(root2);
    if (l1.length != l2.length) return false;
    for (let i = 0; i < l1.length; i++) {
        if (l1[i] !== l2[i]) return false;
    }
    return true;
};
```
