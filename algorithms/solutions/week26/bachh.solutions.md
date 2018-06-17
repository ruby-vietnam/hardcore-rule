# Problem 1

```cpp
class Solution {
public:
  char findTheDifference(string s, string t){
    sort(s.begin(), s.end());
    sort(t.begin(), t.end());
    for(int i = 0; i <= min(s.size(), t.size()); ++i){
      if(s[i] != t[i]) return t[i];
    }
    return t.back();
  }
};
```
# Problem 2
```cpp
class Solution {
public:
  vector<vector<int>> levelOrder(TreeNode * root){
    vector<vector<int>> v;
    queue<pair<int, TreeNode* >> que;
    if (root != NULL) que.push(make_pair(0, root));
    while(!que.empty()){
      auto t = que.front(); que.pop();
      std::cout << t.second->val << std::endl;
      int level = t.first;
      if (v.size() < level + 1) v.push_back(vector<int>());
      v[level].push_back(t.second->val);

      if(t.second->left != NULL){
        que.push(make_pair(level + 1, t.second->left));
      }

      if(t.second->right != NULL){
        que.push(make_pair(level + 1, t.second->right));
      }
    }
    std::cout << v.size() << std::endl;
    for (int i = 0; i < v.size(); ++i) {
      std::cout << v[i].size() << std::endl;
    }
    return v;
  }
};
```
# Problem 3
```cpp
class Solution {
public:
  bool isSimilar(string a, string b){
    int c = 0;
    for(int i = 0; i< a.size(); ++i){
      if(a[i] != b[i] ) c++;
    }
    return c == 0 || c == 2;
  }

  int FindGroup(vector<int> &parent, int n){
    if (parent[n]== n) return n;
    return FindGroup(parent, parent[n]);
  }

  void JoinGroup(vector<int> &parent, int a, int b){
    int pa = FindGroup(parent, a);
    int pb = FindGroup(parent, b);
    if(pa!=pb) parent[a] = pb;
  }

  int numSimilarGroups(vector<string>& A) {
    vector<int> parent(A.size());
    for(int i =0; i < parent.size(); ++i) parent[i] = i;

    for(int i = 0; i < A.size(); ++i){
      for(int j = 0; j < A.size(); ++j){
        if(i==j) continue;
        if(isSimilar(A[i], A[j])){
          std::cout << A[i] << " " << A[j] << std::endl;
          JoinGroup(parent, i, j);
        }
      }
    }
    int c = 0;
    for(int i = 0; i < parent.size(); i++){
      std::cout << FindGroup(parent, i) << std::endl;
      if(FindGroup(parent, i) == i) c++;
    }
    return c;
  }
};
```
