## 1. Two Sum IV - Input is a BST
### 1.1. Summary
| Runtime  | Faster than | Memory   | Less than |
| :----:   | :----:      | :----:   | :----:    |
| 32ms     | 88.35%      | 35.9 MB  | 99.34%    |

### 1.2. Solution summary
Iterate all elements and check if exists any element that have
a combine equals to _k_.

Note that if the double of the element is equal to _k_ it should
be invalid due to no duplicated element in the BST.

### 1.3. Source code
```cpp
class Solution {
public:
    bool find(TreeNode* root, const int &x) {
        if (root == NULL) return false;
        if (root->val == x) return true;
        if (x < root->val) return find(root->left, x);
        if (x > root->val) return find(root->right, x);
        return false;
    }

    bool check(TreeNode* rootTree, TreeNode* root, const int &k) {
        if (root == NULL) return false;
        if (root->val * 2 != k && find(rootTree, k - root->val)) return true;
        return check(rootTree, root->left, k) || check(rootTree, root->right, k);
    }

    bool findTarget(TreeNode* root, int k) {
        return check(root, root, k);
    }
};
```

## 2. Two Sum IV - Input is a BST
### 2.1. Summary
| Runtime  | Faster than | Memory   | Less than |
| :----:   | :----:      | :----:   | :----:    |
| 56ms     | 9.25%       | 16 MB    | 50.93%    |

### 2.2. Solution summary

Traverse all nodes, at each node, we calculate the result for the sub-tree with root node is the current node. We have two cases:

1. If we choose that node is a starting node of the path, we try to find the remaining by recursion.
2. If we not choose that node, just accumulate the result of the two child nodes (left & right).

### 2.3. Source code
```cpp
class Solution {
public:
    int calc(TreeNode* root, const int &target, const bool &isContinue) {
        if (root == NULL) return 0;

        int cnt = 0;
        cnt += root->val == target;

        if (!isContinue) {
            cnt += calc(root->left, target, 0);
            cnt += calc(root->right, target, 0);
        }

        cnt += calc(root->left, target - root->val, 1);
        cnt += calc(root->right, target - root->val, 1);

        return cnt;
    }

    int pathSum(TreeNode* root, int targetSum) {
        return calc(root, targetSum, 0);
    }
};
```

## 3. Two Sum IV - Input is a BST
### 3.1. Summary
| Runtime  | Faster than | Memory   | Less than |
| :----:   | :----:      | :----:   | :----:    |
| 24ms     | 63.79%      | 27.6 MB  | 91.53%    |

### 3.2. Solution summary

Defined that the path is **Single path** if its end node is the child of the sub-tree with the root node is starting node. _See the image below._

![](https://i.imgur.com/FZfTPY6.png)

I am going to introduce **Combined path**. If you're at the root of the sub-tree and you have maximum single path at the left node and the right node. Combine it, you will have a combined path.

![](https://i.imgur.com/8u7jLFe.png)

So, in the problem, we will have two cases at every sub-tree.

1. Maximum single path
2. Maximum combined path

See the image below.

![](https://i.imgur.com/mvFUMl2.png)

In order to calculate maximum single path at every sub-tree, it is easy to do that uses dynamic programming idea.

The maximum single path at root _root_ with two child nodes is:

_best = max(root->value, best_left, best_right);_

At the same time, we can calculate the combined path also. The result is the maximum of best of single path and combined path at every sub-tree.

### 3.3. Source code
```cpp
class Solution {
public:
    int res = -1001001001;
    int f(TreeNode* root) {
        if (root == NULL) return 0;
        int best  = root->val;
        int bestL = f(root->left);
        int bestR = f(root->right);
        best = max(best, max(best + bestL, best + bestR));
        res = max(res, max(best, bestL + bestR + root->val));
        return best;
    }

    int maxPathSum(TreeNode* root) {
        f(root);
        return res;
    }
};
```
