First Unique Character in a String
```
class Solution {
public:
    int firstUniqChar(string s) {
        int a[256] = {0};
        for(int i = 0; i < s.length(); i++)
        {
            a[s[i]]++;
        }
        
        for(int i = 0; i < s.length(); i++)
        {
            if(a[s[i]] == 1)
                return i;
        }
        return -1;
        
    }
};

```
Symmetric Tree

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
    
    bool isMir(TreeNode* r1, TreeNode* r2)
    {
        if(r1 == nullptr)
            return r2 == nullptr;
        if(r2 == nullptr)
            return false;
    
        if(r1->val != r2->val) return false;
 
        return isMir(r1->left, r2->right) && isMir(r1->right, r2->left);
    }
    
    bool isSymmetric(TreeNode* root) {
        if(root == nullptr) return true;
        return isMir(root->left, root->right);
    }
};
```

Candy:
```
class Solution {
public:
    int candy(vector<int>& ratings) {
        
        vector<int> candy (ratings.size(), 1);  
        int n = ratings.size();

            if(ratings[0] > ratings[1] && candy[0] < candy[1])
                candy[0] = candy[1] +1;
            for(int i = 1; i < n-1; i++)
            {
                if(ratings[i] > ratings[i-1] && candy[i] <= candy[i-1])
                    candy[i] = candy[i-1]+1;
            }
            
            if(ratings[n-1] > ratings[n-2] && candy[n-1] <= candy[n-2])
            candy[n-1] = candy[n-2] +1;
            
            for(int i = n-2; i > 0; i--)
                if(ratings[i] > ratings[i+1] && candy[i] <= candy[i+1])
                    candy[i] = candy[i+1]+1;

            if(ratings[0] > ratings[1] && candy[0] <= candy[1])
                candy[0] = candy[1] +1;
            

        int sum = 0;
        for(int i = 0; i < n; i++)
        {
            sum += candy[i];
        }
        return sum;
    }
};
```
