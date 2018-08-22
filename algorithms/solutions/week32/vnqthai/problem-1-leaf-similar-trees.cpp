#define forl(i, from, to) for (int i = (from); i <  (to); i++)

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
      return leaves(root1) == leaves(root2);
    }

  private:
    vector<int> leaves(TreeNode* n) {
      if (n == nullptr) { return vector<int>(); }
      if (n->left == nullptr && n->right == nullptr) {
        return vector<int>(1, n->val);
      } else {
        vector<int> l = leaves(n->left);
        vector<int> r = leaves(n->right);
        vector<int> result;
        forl(i, 0, l.size()) { result.push_back(l[i]); }
        forl(i, 0, r.size()) { result.push_back(r[i]); }
        return result;
      }
    }
};
