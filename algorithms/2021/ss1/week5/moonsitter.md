# [653. Two Sum IV - Input is a BST](https://leetcode.com/problems/two-sum-iv-input-is-a-bst/)

## Approach

**Algorithm:**
Use map to store node vals in the BST.
- If `current_node_val is NULL`, return `false`.
- If `k - current_node_val = already_traversed_node_val`, return `true`. Otherwise, check for left node and right node recursively.
**Analysis:**
- Time complexity: `O(n)`
- Space complexity: `O(n)`

**Submission Detail:**
```cpp
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        map<int,int> set;
        return findTargetRecursive(root, k, set);
    }
    bool findTargetRecursive(TreeNode* root, int k, map<int, int>& set) {
        if (root == NULL) {
            return false;
        }
        if (set[k - root->val]) {
            return true;
        }
        set[root->val] = 1;
        return findTargetRecursive(root->left, k, set) || findTargetRecursive(root->right, k, set);
    }
};
```
```
Runtime: 52 ms, faster than 17.56% of C++ online submissions for Two Sum IV - Input is a BST.
Memory Usage: 41.4 MB, less than 11.10% of C++ online submissions for Two Sum IV - Input is a BST.
```

# [437. Path Sum III](https://leetcode.com/problems/path-sum-iii/)

## Approach
```cpp
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int pathSum(TreeNode* root, int targetSum) {
        if (root == NULL) {
            return 0;
        }
        return pathSum(root->left, targetSum) + pathSum(root->right, targetSum) + pathSumIncludingRoot(root, targetSum);
    }
    int pathSumIncludingRoot(TreeNode* root, int targetSum) {
        if (root == NULL) {
            return 0;
        }
        int count = 0;
        if (root->val == targetSum) {
            ++count;
        }
        int remainingSum = targetSum - root->val;
        count += pathSumIncludingRoot(root->left, remainingSum) + pathSumIncludingRoot(root->right, remainingSum);
        return count;
    }
};
```
```
Runtime: 20 ms, faster than 54.63% of C++ online submissions for Path Sum III.
Memory Usage: 15.6 MB, less than 86.51% of C++ online submissions for Path Sum III.
```
