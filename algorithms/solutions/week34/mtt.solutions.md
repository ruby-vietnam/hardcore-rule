## Problem 1

```c++
class Solution {
public:
  int max(int a, int b) {
    return (a > b) ? a : b;
  }
  
  int rob(vector<int>& nums) {
    if (nums.size() == 0)
      return 0;
    
    vector<vector<int>> f;
    vector<int> a, b;
    f.push_back(a);
    f.push_back(b);
    
    f[0].push_back(0);
    f[1].push_back(nums[0]);
    
    for (int i = 1; i < nums.size(); ++i) {
      f[0].push_back(max(f[0][i-1], f[1][i-1]));
      f[1].push_back(max(f[0][i-1] + nums[i], f[1][i-1]));
    }
    
    return max(f[1][nums.size()-1], f[0][nums.size()-1]);
  }
};
```

## Problem 2
```c++
class Solution {
public:
  bool wordBreak(string s, vector<string>& wordDict) {
    map<string, bool> check;
    map<int, bool> result;
    
    for (auto e : wordDict)
      check.insert(pair<string, bool>(e, true));
    for (int i = 0; i < s.size(); ++i) {
      for (int j = 0; j <= i; ++j) {
        string sub1 = s.substr(0, j + 1);
        if (check.find(sub1) != check.end() || result.find(j) != result.end()) {
          if (j == i) {
            result.insert(pair<int, bool>(i, true));
          }
          else {
            string sub2 = s.substr(j + 1, i - j);
            if (check.find(sub2) != check.end()) {
              result.insert(pair<int, bool>(i, true));
              break;
            }
          }
        }
      }
    }
    return result.find(s.size() - 1) != result.end();
  }
};
```

## Problem 3
```c++
class Solution {
public:
  int leastInterval(vector<char>& tasks, int n) {
    map<char, int> quantity, lastIndex;
    map<char, int>::iterator it, li, lq;
    
    for (vector<char>::iterator t = tasks.begin(); t != tasks.end(); ++t) {
      if ((it = quantity.find(*t)) != quantity.end())
        it->second++;
      else
        quantity.insert(pair<char, int>(*t, 1));
      lastIndex.insert(pair<char, int>(*t, -1));
    }
    
    int index = 0;
    while (true) {
      bool anyLeft = false;
      int max = 0;
      
      for (map<char, int>::iterator q = quantity.begin(); q != quantity.end(); ++q) {
        if (q->second > 0)
          anyLeft = true;
        if ((li = lastIndex.find(q->first))->second == -1 || index - li->second - 1 >= n)
          if (max < q->second) {
            max = q->second;
            lq = q;
          }
      }
      if (max > 0) {
        lq->second--;
        lastIndex.find(lq->first)->second = index;
      }
      if (!anyLeft)
        break;
      index++;
    }
    return index;
  }
};
```

## Problem 4
```c++
class Solution {
public:
  int longestValidParentheses(string s) {
    vector<int> f;
    set<pair<int, int>> segment;
    int max = 0;
    
    for (int i = 0; i < s.size(); ++i)
      if (s[i] == '(')
        f.push_back(0);
      else {
        for (int j = 0; j < i; ++j)
          if (s[j] == '(' && ((i - j + 1) % 2 == 0)) {
            if (i - j + 1 == 2 || segment.find(pair<int, int>(j + 1, i - 1)) != segment.end()) {
              f.push_back(f[j - 1] + i - j + 1);
              if (max < f[j - 1] + i - j + 1) max = f[j - 1] + i - j + 1;
              segment.insert(pair<int, int>(j - f[j - 1], i));
              break;
            }
          }
        if (f.size() <= i) f.push_back(0);
      }
    return max;
  }
};
```
