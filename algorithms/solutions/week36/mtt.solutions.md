## Problem 1
```c++
class Solution {
public:
  int climbStairs(int n) {
    if (n < 3) return n;
    int f[2] = {1, 2};
    for (int i = 3; i <= n; ++i) {
      int sum = f[0] + f[1];
      if (i == n) return sum;
      f[0] = f[1];
      f[1] = sum;
    }
  }
};
```

## Problem 2
```c++
class Solution {
public:
  int lengthOfLongestSubstring(string s) {
    unordered_set<char> chars;
    deque<char> sub;
    int max = 0;

    for (string::iterator it = s.begin(); it != s.end(); ++it) {
      if (chars.find(*it) == chars.end()) {
        chars.insert(*it);
        sub.push_back(*it);
        if (max < sub.size()) max = sub.size();
      }
      else {
        while (chars.find(*it) != chars.end()) {
          char first = sub.front();
          sub.pop_front();
          chars.erase(first);
        }
        chars.insert(*it);
        sub.push_back(*it);
      }
    }
    return max;
  }
};
```

## Problem 3
```c++
class Solution {
private:
  void add(map<int, unordered_set<int>>& v, int* count, int& a, int& b) {
    unordered_set<int>& s = v.find(a)->second;
    if (s.find(a) == s.end())
      count[a]++;
    s.insert(b);
  }
public:
  bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
    int* in = new int[numCourses];
    int* out = new int[numCourses];
    bool* check = new bool[numCourses];
    map<int, unordered_set<int>> vi, vo;
    for (int i = 0; i < numCourses; ++i) {
      in[i] = out[i] = 0;
      check[i] = false;
      vi[i] = unordered_set<int>{};
      vo[i] = unordered_set<int>{};
    }
    
    for (auto it : prerequisites) {
      int a = it.first, b = it.second;
      if (a == b) return false;
      add(vi, in, b, a);
      add(vo, out, a, b);
    }
    int n = numCourses;
    while (true) {
      bool stop = true;
      for (int i = 0; i < numCourses; ++i)
        if (!check[i] && in[i] == 0) {
          stop = false;
          check[i] = true;
          for (auto it : vo.find(i)->second)
            in[it]--;
          n--;
        }
      if (!n)
        break;
      if (stop)
        return false;
    }
    
    delete []in;
    delete []out;
    delete []check;
    return true;
  }
};
```

## Problem 4
```c++
#define li long int
#define vi vector<int>

class Solution {
public:
  int sumSubseqWidths(vector<int>& A) {
    li DEVISOR = 1000000007;
    
    vector<li> p2(A.size());
    p2[0] = 1;
    for (int i = 1; i < A.size(); ++i) p2[i] = (p2[i-1] * 2) % DEVISOR;
    
    sort(A.begin(), A.end());
    li modMaxSum = 0, modMinSum = 0;
    li n = A.size();
    for (vi::reverse_iterator it = A.rbegin(); it != A.rend(); it++)
      modMaxSum = (modMaxSum + p2[--n] * *it) % DEVISOR;
    n = A.size();
    for (vi::iterator it = A.begin(); it != A.end(); it++)
      modMinSum = (modMinSum + p2[--n] * *it) % DEVISOR;
    
    if (modMaxSum > modMinSum)
      return modMaxSum - modMinSum;
    else
      return (DEVISOR + modMaxSum - modMinSum) % DEVISOR;
  }
};
```
