# Problem 1:

```
class Solution {
public:
    
    bool palin(string s)
    {
        return s == string(s.rbegin(), s.rend());
    }
    
    bool validPalindrome(string s) {
        int l = s.length();
        for (int i = 0 ; i <= s.length() /2 ; i++)
        {
            if(s[i] != s[l-i-1]) {
                if(s[i] == s[l-i-2])
                {
                    if(palin(s.substr(i,l-i-1-i)))
                        return true;
                }
                if(s[i+1] == s[l-i-1])
                {
                     if(palin(s.substr(i+1, l-i-1-i)))
                        return true;
                }
                return false;
            }
        }
        return true;
    }
};
```
# Problem 2: Flatten binary tree
https://leetcode.com/problems/flatten-binary-tree-to-linked-list/description/
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
    void flatten(TreeNode* root) {
        if(!root) return;
        flatten(root->left);
        flatten(root->right);
        TreeNode* temp =  root->right;
        root->right = root->left;
        root->left = nullptr;
        while (root->right)
            root = root->right;
        root->right = temp;
    }
};
```

# Problem 3: IsSubsequence:
```
class Solution {
public:
    bool isSubsequence(string s, string t) {
    	auto i = s.begin();
        for(char c : t) i += (*i == c);
        return i == s.end();
    }
};
```
