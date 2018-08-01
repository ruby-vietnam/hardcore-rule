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

## Problem 2: [Most Frequent Subtree Sum](https://leetcode.com/problems/most-frequent-subtree-sum/description/)

Using Deep First Search (DFS) to calculate sum of nodes and we need a map to calculate frequent of sum of node then find maximum frequent of sum of node.

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
    vector<int> findFrequentTreeSum(TreeNode* root) {
        vector<int> s, result;
        int sum = dfs(root, s); // calculate sum
        // calculate frequent of sum
        std::map<int, int> tMap;
        for(int i = 0; i < s.size(); i++) {
            if(tMap.find(s[i]) != tMap.end()) { 
                tMap[s[i]]++;
            } else {
                tMap[s[i]] = 1;
            }
        }
        int max = -1;
        for(auto& x : tMap) {
            if(x.second > max) {
                max = x.second;
            }
        }
        
        for(auto& x: tMap) 
            if(x.second == max) 
                result.push_back(x.first);
            
        
        return result;
    }
    
    int dfs(TreeNode* node, vector<int> &s) {
        if(node == NULL) return 0;
        int sum = node->val + dfs(node->left, s) + dfs(node->right, s);
        s.push_back(sum);
        return sum;
    }
};
```