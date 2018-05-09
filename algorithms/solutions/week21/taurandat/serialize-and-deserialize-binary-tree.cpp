/*
 *
 * Link: https://leetcode.com/problems/serialize-and-deserialize-binary-tree/
 *
 * 48 / 48 test cases passed.
 * Status: Accepted
 * Runtime: 26 ms
 * Your runtime beats 98.50 % of cpp submissions.
 *
 */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string str;

        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            if (q.front() == nullptr) {
                str += "null";
            } else {
                TreeNode* currentNode = q.front();
                q.push(currentNode->left);
                q.push(currentNode->right);
                str += to_string(currentNode->val);
            }
            str += ",";
            q.pop();
        }

        return str;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        TreeNode* root = nullptr;

        queue<TreeNode**> q;
        q.push(&root);

        string::iterator first = data.begin();
        while (first != data.end()) {
            TreeNode** currentNode = q.front();

            // work arround to avoid overflow
            // the check should be: `string(*first, *first+4) == "null"`
            if (*first == 'n') {
                advance(first, 5);
            } else {
                string::iterator last = find(first, data.end(), ',');
                int val = stoi(string(first, last));
                *currentNode = new TreeNode(val);
                q.push(&((*currentNode)->left));
                q.push(&((*currentNode)->right));
                first = next(last);
            }

            q.pop();
        }

        return root;
    }
};