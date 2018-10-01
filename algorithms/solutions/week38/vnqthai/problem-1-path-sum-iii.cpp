#define VI vector<int>

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
    int pathSum(TreeNode* root, int sum) {
      int count = 0;
      check(root, sum, count, VI());
      return count;
    }

  private:
    void check(TreeNode* node, int sum, int& count, VI sums) {
      if (node == nullptr) { return; }
      if (node->val == sum) { count++; }
      for (int s : sums) {
        if (node->val + s == sum) {
          count++;
        }
      }

      VI new_sums;
      for (int s : sums) {
        new_sums.push_back(s + node->val);
      }
      new_sums.push_back(node->val);

      check(node->left, sum, count, new_sums);
      check(node->right, sum, count, new_sums);
    }
};
