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

# Problem 2

URL: https://leetcode.com/problems/most-frequent-subtree-sum/description/

```javascript
/* 
 * [508] Most Frequent Subtree Sum
 * Status:
 *  ✔ Accepted
 *  ✔ 61/61 cases passed (96 ms)
 *  ✔ Your runtime beats 16.67 % of javascript submissions
 */
 
const sum = root => {
    return root.val + (root.left ? sum(root.left) : 0) + (root.right ? sum(root.right) : 0);
};

const build = root => {
    let output = [];
    let stack = [root];
    while (stack.length) {
        let node = stack.pop();
        if (node.right) stack.push(node.right);
        if (node.left) stack.push(node.left);
        output.push(sum(node));
    }
    return output;
};

const findFrequentTreeSum = root => {
    if (!root) return [];
    let output = [];
    let maxFreq = 0;
    let freq = build(root).reduce((arr, curr) => {
        if (!arr[curr]) arr[curr] = 0;
        arr[curr] += 1;
        if (arr[curr] > maxFreq) maxFreq = arr[curr];
        return arr;
    }, {});

    for (let key in freq) {
        if (freq[key] === maxFreq) output.push(~~key);
    }

    return output;
};
```
