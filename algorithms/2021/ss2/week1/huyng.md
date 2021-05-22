## 1. Two Sum IV - Input is a BST
### 1.1. Summary
| Runtime  | Faster than | Memory   | Less than |
| :----:   | :----:      | :----:   | :----:    |
| 204ms    | 13.52%      | 68.8 MB  | 26.81%    |

### 1.3. Source code
```cpp

```

## 2. Two Sum IV - Input is a BST
### 2.1. Summary
| Runtime  | Faster than | Memory   | Less than |
| :----:   | :----:      | :----:   | :----:    |
| 0ms      | 100%        | 12.8 MB  | 60.11%    |

### 2.3. Source code
```cpp
class Solution {
public:
  int n = 0;
  vector<int> nodes;
  vector< vector<int> > adj;

  void dfs(TreeNode* root) {
    if (root == NULL) return;
    n = max(n, root->val + 1);
    dfs(root->left);
    dfs(root->right);
  }
  
  void add(const int &u, const int &v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  
  void build(TreeNode* root) {
    if (root == NULL) return;
    if (root->left != NULL) add(root->val, root->left->val);
    if (root->right != NULL) add(root->val, root->right->val);
    build(root->left);
    build(root->right);
  }
  
  void find(const int &u, const int &k, const int &par) {
    if (k == 0) {
      nodes.push_back(u);
      return;
    }
    for (int v : adj[u]) if (v != par) find(v, k - 1, u);
  }
  
  vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
    dfs(root);
    adj.resize(n);
    build(root);
    find(target->val, k, -1);
    return nodes;
  }
};
```
