## Problem 1 - [Leaf-Similar Trees](https://leetcode.com/problems/leaf-similar-trees/)


We can use DFS to find all leaves in 2 tree and push into 2 lists. Then compare 2 lists we will know it is similar leaf or not.

```cpp
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> leavesLeft, leavesRight; 
        dfs(root1, leavesLeft);
        dfs(root2, leavesRight);
        return (leavesLeft == leavesRight);
    }
    
    void dfs(TreeNode* node, vector<int>& leaves) {
        if (node == NULL) return;
        if (node->left == NULL && node->right == NULL)
            leaves.push_back(node->val);
        dfs(node->left, leaves);
        dfs(node->right, leaves);
    }
};
```