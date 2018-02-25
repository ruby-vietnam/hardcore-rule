# Problem 1: Longest Harmonious Subsequence

URL: https://leetcode.com/problems/longest-harmonious-subsequence/description/

Status:
```
  ✔ Accepted
  ✔ 201/201 cases passed (231 ms)
  ✔ Your runtime beats 64.52 % of javascript submissions
```

The approach for this problem is, first, build a hashmap to count the occurence of every number in the input, after that, for each number, looking for the adjacent, if we found it, so the length of the harmonious subsequence containing this number should be the total numbers of it and the adjacent.

We find the maximum length of subsequences during the time we do adjacent search, thanks to hashmap, we don't need an inner for loop here.

Complexity: O(n)

Implementation:

```javascript
var findLHS = function(nums) {
  let count = Object.create(null);
  let max = up = down = select = 0;
  let i = -1;
  for (i of nums) {
    if (!count[i]) {
      count[i] = 1;
    } else {
      count[i] += 1;
    }
  }
  for (let i in count) {
    i = ~~i;
    up = down = 0;
    if (count[i+1]) {
      up = count[i+1] + count[i];
    }
    if (count[i-1]) {
      down = count[i-1] + count[i];
    }
    select = up > down ? up : down;
    if (max < select) max = select;
  }
  return max;
};
```

# Problem 2: Merge Two Binary Trees

URL: https://leetcode.com/problems/merge-two-binary-trees/description/

Status:
```
  ✔ Accepted
  ✔ 183/183 cases passed (159 ms)
  ✔ Your runtime beats 59.1 % of javascript submissions
```

The simple approach is recursively traversal the tree, for each node, calcualte the value of the node as described in the rule.

Implementation:
```javascript
var mergeTrees = function(t1, t2) {
    if (!t1 && !t2) return null;
    let v1 = v2 = 0;
    v1 = t1 ? t1.val : 0;
    v2 = t2 ? t2.val : 0;
    let root = new TreeNode(v1 + v2);
    root.left = mergeTrees(t1 ? t1.left : null, t2 ? t2.left : null);
    root.right = mergeTrees(t1 ? t1.right : null, t2 ? t2.right : null);
    return root;
};
```
