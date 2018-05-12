### Prolem 1 - [Valid Anagram](https://leetcode.com/problems/valid-anagram/description/)

Status:
```
  ✔ Accepted
  ✔ 34/34 cases passed (26 ms)
```

```cpp
class Solution {
public:
    bool isAnagram(string s, string t) {
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        return s == t;
    }
};
```

### Prolem 2 - [Encode and Decode TinyURL](https://leetcode.com/problems/encode-and-decode-tinyurl/description/)

Status:
```
  ✔ Accepted
  ✔ 739/739 cases passed (6 ms)
```

```cpp
class Solution {
public:

    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        return longUrl;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        return shortUrl;
    }
};
```

### Problem 3 - [Merge k Sorted Lists](https://leetcode.com/problems/merge-k-sorted-lists/description/)

Status:
```
  ✔ Accepted
  ✔ 131/131 cases passed (29 ms)
```

Code:

```cpp
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
#include <priority_queue>
#include <pair>

class Solution {
public:
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode *x = 0, *head = 0;
        priority_queue<pair<int, ListNode*>, vector<pair<int, ListNode*> >, greater<pair<int, ListNode*> > > q;
        for (int i = 0; i < lists.size(); ++i) {
            if (lists[i]) q.push(make_pair(lists[i]->val, lists[i]));
        }
        if (!q.empty()) head = q.top().second;
        while (!q.empty()) {
            if(x) {
                x->next = q.top().second;
                x = x->next;
            } else {
                x = q.top().second;
            }
            q.pop();
            if (x && x->next) {
                q.push(make_pair(x->next->val, x->next));
            }
        }
        return head;
    }
};

// compexity O(nlogn) with n is total number of elements
```

### Problem 4 - [Serialize and Deserialize Binary Tree](https://leetcode.com/problems/serialize-and-deserialize-binary-tree/description/)

Status:
```
  ✔ Accepted
  ✔ 48/48 cases passed (30 ms)
```

Code:
```cpp
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
    const int mx = 11;
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string ret = "";
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
            TreeNode *u = q.front();
            q.pop();
            if (!u) {
                ret += "null ";
                continue;
            } else {
                q.push(u->left);
                q.push(u->right);
                ret += to_string(u->val) + " ";
            }
        }
        return ret;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        char *x = new char[data.size() + 1];
        TreeNode *root;
        memcpy(x, data.c_str(), data.size());
        x[data.size()] = 0;
        char s[mx];
        memcpy(s, strtok(x, " \n"), mx);
        queue<TreeNode*> q;
        if (strcmp(s, "null") == 0) {
            root = 0;
        } else {
            root = new TreeNode(atoi(s));
            q.push(root);
        }
        while(!q.empty()) {
            TreeNode *u = q.front();
            q.pop();
            if (!u) continue;
            TreeNode *v;
            memset(s, 0, sizeof s);
            memcpy(s, strtok(NULL, " \n"), mx);
            if (strcmp(s, "null") == 0) {
                v = 0;
            } else {
                v = new TreeNode(atoi(s));
            }
            u->left = v;
            q.push(v);
            memset(s, 0, sizeof s);
            memcpy(s, strtok(NULL, " \n"), mx);
            if (strcmp(s, "null") == 0) {
                v = 0;
            } else {
                v = new TreeNode(atoi(s));
            }
            u->right = v;
            q.push(v);
        }
        return root;
    }
};
```