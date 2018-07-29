##Problem 1

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
    void findSequence(TreeNode * root, vector<int>& ans){
        stack<TreeNode> st;    
        TreeNode p(0);
    
        ans.clear();
        
        st.push(*root);
        while(!st.empty()){
            p = st.top(); st.pop();

            if (p.left == NULL && p.right == NULL) ans.push_back(p.val);
            else {
                if (p.right != NULL) st.push(*p.right);
                if (p.left != NULL) st.push(*p.left);   
            }
        }    
    }

    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> sequence[2];

        findSequence(root1, sequence[0]);
        findSequence(root2, sequence[1]);
        
        if (sequence[0].size() != sequence[1].size()) return 0;
        for (int i = 0; i < sequence[0].size(); ++i) 
            if (sequence[0][i] != sequence[1][i]) return 0;
        return 1;
    }
};
```
