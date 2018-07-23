## Problem 2

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
  int maxPathSum(TreeNode* root) {
    int maxSum = -2000000000;
    calculateMaxPathSum(root, maxSum);
    return maxSum;
  }
  
  int calculateMaxPathSum(TreeNode* root, int &maxSum) {
    if (root == NULL)
      return 0;
    int maxLeft = calculateMaxPathSum(root->left, maxSum);
    int maxRight = calculateMaxPathSum(root->right, maxSum);

    if (maxSum < root->val + maxLeft + maxRight)
      maxSum = root->val + maxLeft + maxRight;
    if (maxSum < root->val + maxLeft)
      maxSum = root->val + maxLeft;
    if (maxSum < root->val + maxRight)
      maxSum = root->val + maxRight;
    if (maxSum < root->val)
      maxSum = root->val;

    int maxV = (maxLeft > maxRight) ? maxLeft : maxRight;
    if (root->val > root->val + maxV)
      return root->val;
    else
      return root->val + maxV;
  }
};
```
