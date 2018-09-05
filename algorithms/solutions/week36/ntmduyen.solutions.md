# Problem 2 - [Longest Substring Without Repeating Characters](https://leetcode.com/problems/longest-substring-without-repeating-characters/description/)

```cpp
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> chars(256, -1);
        int n = s.length();
        int max_len = 0, curr_len = 0, head = 0;
        for (int i = 0; i < n; i++) {
            int c = int(s[i]);
            if (chars[c] == -1 || chars[c] < head) {
                curr_len++;
            } else {
                head = chars[c] + 1;
                curr_len = i - chars[c];
            }
            if (curr_len > max_len) {
                max_len = curr_len;
            }
            chars[c] = i;
        }
        return max_len;
    }
};
```

# Problem 3 - [Course Schedule](https://leetcode.com/problems/course-schedule/description/)

```cpp
class Solution {
public:
    const int UNVISITED = 0;
    const int VISITING = 1;
    const int VISITED = 2;

    bool hasCycle(vector<vector<int>> adj, int i, int *states) {
        states[i] = VISITING;
        vector<int>::iterator it;
        for (it = adj[i].begin(); it != adj[i].end(); it++) {
            if (states[*it] == VISITED) {
                continue;
            }
            if (states[*it] == VISITING) {
                return true;
            }
            if (hasCycle(adj, *it, states)) {
                return true;
            }
        }
        states[i] = VISITED;
        return false;
    }

    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<vector<int>> adj(numCourses, vector<int>(0));
        int n = prerequisites.size();
        for (int i = 0; i < n; i++) {
            int c1 = prerequisites[i].first;
            int c2 = prerequisites[i].second;
            adj[c2].push_back(c1);
        }
        int *states = new int[numCourses];
        for (int i = 0; i < numCourses; i++) {
            states[i] = UNVISITED;
        }
        for (int i = 0; i < numCourses; i++) {
            if (hasCycle(adj, i, states)) {
                return false;
            }
        }
        delete [] states;
        return true;
    }
};
```
