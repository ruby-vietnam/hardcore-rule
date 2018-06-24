### Prolem 1 - [Find the Difference](https://leetcode.com/problems/find-the-difference/description/)
```python
class Solution(object):
    def findTheDifference(self, s, t):
        s = sorted(s)
        t = sorted(t)
        for i in range(len(s)):
            if s[i] != t[i]:
                return t[i]
        return t[-1]
```

### Prolem 2 - [Binary Tree Level Order Traversal](https://leetcode.com/problems/binary-tree-level-order-traversal/description/)
```python
# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def levelOrder(self, root):
        if root is None:
            return []
        from collections import deque
        ret = []
        q = deque([])
        d = deque([])
        q.append(root)
        d.append(0)
        while len(q) > 0:
            u = q.popleft()
            l = d.popleft()
            if len(ret) == l:
                ret.append([])
            ret[l].append(u.val)
            if u.left is not None:
                q.append(u.left)
                d.append(l + 1)
            if u.right is not None:
                q.append(u.right)
                d.append(l + 1)
        return ret
```

### Problem 3 - [Similar String Groups](https://leetcode.com/problems/similar-string-groups/description/)
```cpp
class Solution {
public:
    int numSimilarGroups(vector<string>& A) {
        ret = A.size();
        for (int i = 0; i < A.size(); ++i) p[i] = i;
        for (int i = 0; i < A.size(); ++i) {
            for (int j = i + 1; j < A.size(); ++j) {
                if (similar(A[i], A[j])) {
                    join(i, j);
                }
            }
        }
        return ret;
    }
private:
    int ret;
    int p[2002];
    int Find(int u) {
        return u == p[u] ? u : p[u] = Find(p[u]);
    }
    void join(int u, int v) {
        u = Find(u);
        v = Find(v);
        if (u != v) {
            --ret;
            p[u] = v;
        }
    }
    bool similar(string s, string t) {
        vector<int> pos;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] != t[i]) {
                pos.push_back(i);
                if (pos.size() > 2) return 0;
            }
        }
        if (pos.size() == 0) return 1;
        return s[pos[0]] == t[pos[1]];
    }
};
```
