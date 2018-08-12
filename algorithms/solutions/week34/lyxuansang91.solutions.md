## Problem 1 - [House Robber](https://leetcode.com/problems/house-robber/description/)

Solution: Using DP (Dynamic programming).
Let S(i) is maximum amount of money you can rob tonight without alert the police end at i (0 <= i < n). We will calculate s(i) by:
- s(0) = nums(0)
- s(1) = max(s(0), nums(1))
- s(i) = max(s(j)) + nums(i) (0 <= j <= i-2)

We can caculate s(i) in solution O(N^2) but we can calculate s(i) in solution O(N) because we can calculate max(s(j)) in O(N).


```cpp
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size(); 
        if(n == 0) return 0;
        int* s = new int[n];
        s[0] = nums[0];
        int result = s[0];
        int temp = 0;
        for(int i = 1; i < n; i++) {
            s[i] = nums[i];
            if(i >= 2 && temp < s[i-2]) temp = s[i-2];
            s[i] = (s[i] > temp + nums[i] ? s[i] : temp + nums[i]);
            result = (result > s[i] ? result : s[i]);
        }
        return result;
    }
};
```
## Problem 2 - [Word Break](https://leetcode.com/problems/word-break/description/)

Solution: using DP (Dynamic Programming)
```cpp
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        sort(wordDict.begin(), wordDict.end());
        int n = s.size();
        bool *f = new bool[n+1];
        f[0] = true;
        for(int i = 1; i <= n; i++) {
            f[i] = false;
            for(int j = i; j > 0; j--) {
                string sub = s.substr(j-1, i-j+1);
                if(f[j-1] && std::binary_search(wordDict.begin(), wordDict.end(), sub)) {
                    f[i] = true;
                    break;
                }
            }
        }
        return f[n];
    }
};
```
## Problem 3 - [Task Scheduler](https://leetcode.com/problems/task-scheduler/description/)
Solution:
```cpp
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int* count = new int[26];
        for(int i = 0; i < 26; i++) count[i] = 0;
        int max = 0;
        for(int i = 0; i < tasks.size(); i++) {
            count[tasks[i] - 'A']++;
            max = (max > count[tasks[i]- 'A'] ? max : count[tasks[i] - 'A']);
        }
        int ans = (max - 1) * (n+1);
        for(int i = 0; i < 26; i++)
            if(max == count[i]) ans++;
        return (ans > tasks.size() ? ans : tasks.size());
    }
};
```
## Problem 4 - [Longest Valid Parentheses](https://leetcode.com/problems/longest-valid-parentheses/description/)
Solution: using Dynamic Programming. With f[i] is the longest valid paretheses at ith element
- f[0] = 0
- if(s[i] == '(') f[i] = 0
- if(s[i] == ')') 
  f[i] = f[i-2] + 2 if s[i-1] == '(' else f[i] = f[i-1] + f[i-f[i-1]-2] + 2 if i-f[i-1]-1 == '('

```cpp
class Solution {
public:
    int longestValidParentheses(string s) {
        vector<int> f(s.size());
        int maxans = 0;
        for(int i = 1; i < s.size(); i++) {
            if(s[i] == ')') {
                if(s[i-1] == '(') { 
                    f[i] = (i >= 2 ? f[i-2] : 0) + 2;
                } else if(i-f[i-1] > 0 && s[i-f[i-1]-1] == '(') {
                    f[i] = f[i-1] + (i-f[i-1] >= 2 ? f[i-f[i-1]-2] : 0) + 2; 
                }
                maxans = (maxans > f[i]  ? maxans : f[i]);
            }
        }
        return maxans;
    }
};
```