### Prolem 1 - [Non-decreasing Array](https://leetcode.com/problems/non-decreasing-array/description/)
```cpp
class Solution {
private:
    vector<int> l;
    int Find(int x) {
        int left = 0, right = l.size() - 1, mid, pos;
        while(left<= right) {
            mid = (left + right)/2;
            if(x <= l[mid]) {
                pos = mid;
                right = mid - 1;
            }
            else left = mid + 1;
        }
        return pos;
    }

public:
    bool checkPossibility(vector<int>& nums) {
        l.push_back(nums[0]);
        for(int i = 1; i < nums.size(); ++i)
        if(nums[i] >= l.back())
            l.push_back(nums[i]);
        else l[Find(nums[i])] = nums[i];
        return nums.size() - l.size() <= 1;
    }
};
```

### Prolem 2 - [Permutations](https://leetcode.com/problems/permutations/description/)
```cpp
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ret;
        sort(nums.begin(), nums.end());
        do{
            ret.push_back(nums);
        }while(next_permutation(nums.begin(), nums.end()));
        return ret;
    }
};
```

### Problem 3 - [Serialize and Deserialize Binary Tree](https://leetcode.com/problems/serialize-and-deserialize-binary-tree/description/)
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

### Problem 4 - [Find Median from Data Stream](https://leetcode.com/problems/find-median-from-data-stream/description/)
```cpp
class MedianFinder {
private:
    priority_queue<int> l;
    priority_queue<int, vector<int>, greater<int> > r;
    int sz;
public:
    
    MedianFinder() {
        sz = 0;
    }
    
    void addNum(int num) {
        ++sz;
        if (sz & 1) {
            if (!r.empty()) {
                int u = r.top();
                r.pop();
                l.push(min(u, num));
                r.push(max(u, num));
            } else {
                l.push(num);
            }
        } else {
            int u = l.top();
            l.pop();
            l.push(min(u, num));
            r.push(max(u, num));
        }
    }
    
    double findMedian() {
        if (sz & 1) return l.top();
        return 0.5 * (l.top() + r.top());
    }
};
```

