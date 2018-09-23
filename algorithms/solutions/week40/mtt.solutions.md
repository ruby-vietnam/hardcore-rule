## Problem 1
```c++
class Solution {
public:
  void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    vector<int> temp;
    int i = 0, j = 0;
    while (i < m || j < n)
      if (i < m && j < n)
        nums1[i] < nums2[j] ? temp.push_back(nums1[i++]) : temp.push_back(nums2[j++]);
      else
        i == m ? temp.push_back(nums2[j++]) : temp.push_back(nums1[i++]);
    for (int k = 0; k < temp.size(); ++k) nums1[k] = temp[k];
  }
};
```

## Problem 2
```c++
class Solution {
private:
  int minNumSquares(unordered_map<int, int>& f, int n) {
    if (f.find(n) != f.end())
      return f.find(n)->second;
    int t = sqrt(n);
    if (t*t == n) {
      f[n] = 1;
      return 1;
    }
    int minF = minNumSquares(f, t*t) + minNumSquares(f, n - t*t);
    for (int i = sqrt(t); i < t; ++i)
      if (minF > minNumSquares(f, i*i) + minNumSquares(f, n - i*i))
        minF = minNumSquares(f, i*i) + minNumSquares(f, n - i*i);
    f[n] = minF;
    return minF;
  }
public:
  int numSquares(int n) {
    unordered_map<int, int> f;
    return minNumSquares(f, n);
  }
};
```

## Problem 3
```c++
class Solution {
public:
  string longestPalindrome(string s) {
    int len = s.length();
    string r = "";
    for (int i = 0; i < len; ++i) {
      int l = 1;
      while (i - l >= 0 && i + l < len && s[i - l] == s[i + l]) l++;
      if (r.length() < 2*l - 1) r = s.substr(i - l + 1, 2*l - 1);
      
      if (i + 1 < len && s[i] == s[i + 1]) {
        l = 1;
        while (i - l >= 0 && i + 1 + l < len && s[i - l] == s[i + 1 + l]) l++;
        if (r.length() < 2*l) r = s.substr(i - l + 1, 2*l);
      }
    }
    return r;
  }
};
```
