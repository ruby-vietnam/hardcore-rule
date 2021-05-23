## 1. Find the Town Judge
### 1.1. Summary
| Runtime  | Faster than | Memory   | Less than |
| :----:   | :----:      | :----:   | :----:    |
| 204ms    | 13.52%      | 68.8 MB  | 26.81%    |

### 1.3. Source code
```cpp
class Solution {
public:
  int findJudge(int n, vector<vector<int>>& trust) {
    vector<int> in(n), out(n);
    for (auto edge : trust) {
      ++in[edge[1]-1], ++out[edge[0]-1];
    }

    for (int i = 0; i < n; i++) {
      if (in[i] == n - 1 && out[i] == 0) return i + 1;
    }

    return -1;
  }
};
```

## 2. All Nodes Distance K in Binary Tree
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
