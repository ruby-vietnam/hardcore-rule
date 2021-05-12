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
