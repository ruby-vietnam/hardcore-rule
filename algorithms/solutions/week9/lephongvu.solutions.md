#1
```
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
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        TreeNode *t = new TreeNode(0);
        if(t1 && t2){ 
            t->val = t1->val + t2->val;
            t->left = mergeTrees(t1->left, t2->left);
            t->right = mergeTrees(t1->right, t2->right);
        }
        else if(t1)        t = t1;
        else if(t2)        t = t2;

        else return nullptr;
        return t;       
    }
};
```
