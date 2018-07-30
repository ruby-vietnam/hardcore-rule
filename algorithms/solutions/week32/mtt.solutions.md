## Problem 1

```c++
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
    vector<int> leaf1, leaf2;
    getLeaves(root1, leaf1);
    getLeaves(root2, leaf2);
    return leaf1 == leaf2;
  }
  
  void getLeaves(TreeNode* root, vector<int>& leaves) {
    if (root == NULL) return;
    if (root->left == NULL && root->right == NULL) leaves.push_back(root->val);
    getLeaves(root->left, leaves);
    getLeaves(root->right, leaves);
  }
};
```

## Problem 3
```c++
#include <bits/stdc++.h>
using namespace std;

long long int minTime(long long int l, long long int s, long long int t, long long int &r) {
    if (s <= t) {
        r += t - s;
        return t;
    }
    if (s <= l - t) {
        r += l - t - s;
        return l - t;
    }
    r += l + t - s;
    return l + t;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    long long int m;

    cin >> n >> m;
    long long int l = 2*(m - 1);

    for (int e = 0; e < n; ++e) { 
        long long int i, j, t;
        cin >> i >> j >> t;
        if (i == j)
            cout << t << "\n";
        else {
            i--;
            j--;
            long long int st = t % l;
            long long int next = minTime(l, st, i, t);
            minTime(l, next % l, j, t);
            cout << t << "\n";
        }
    }
}
```
