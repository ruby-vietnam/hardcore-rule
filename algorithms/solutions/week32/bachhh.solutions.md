# Problem 1
```cpp
class Solution {
public:
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        return recurse(root1) == recurse(root2);
    }
    string recurse(TreeNode* root){
        if (root == NULL) return "";
        if (root->left == NULL && root->right == NULL) return to_string(root->val);
        return recurse(root->left) + recurse(root->right);
    }
};
```

# Probem 3
```cpp
#include <bits/stdc++.h>

using namespace std;

//  ***** MAIN *****
int main(){
    //ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m, s, f, t; cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        cin >> s >> f >> t;
        if (s < f ){
            cout << ceil( (t - s + 1)/ (2.0 * m -2)) * (2*m-2) + (s-1) + (f-s) << endl;
        }
        else if( s > f) {
             cout << ceil((t - m + s - m + 1)/(2.0*m-1)) * (2*m-2) + (m-s) + (m-1) + (s-f) << endl;
        }
        else {
            std::cout << t << std::endl;
        }

    }
    return 0;
}

```
