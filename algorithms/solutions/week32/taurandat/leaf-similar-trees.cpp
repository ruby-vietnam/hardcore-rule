
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
    vector<int> sequence1, sequence2;
    traverse(root1, sequence1);
    traverse(root2, sequence2);

    return sequence1 == sequence2;
  }

  void traverse(TreeNode* node, vector<int>& sequence) {
    if(node == nullptr) {
      return;
    } else if(node->left == nullptr && node->right == nullptr) {
      sequence.push_back(node->val);
      return;
    } else {
      traverse(node->left, sequence);
      traverse(node->right, sequence);
      return;
    }
  }
};
