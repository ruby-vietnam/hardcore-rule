## Problem 1
```c++
class Solution {
public:
  int singleNumber(vector<int>& nums) {
    unordered_set<int> s;
    for (int e : nums)
      if (s.find(e) == s.end())
        s.insert(e);
      else
        s.erase(e);
    for (int e : s) return e;
  }
};
```

## Problem 2
```c++
class Solution {
public:
  int countSubstrings(string s) {
    int lens = s.length();
    long int result = 0;
    for (int i = 0; i < lens; ++i) {
      int l = 1;
      while (i - l >= 0 && i + l < lens && s[i - l] == s[i + l]) l++;
      result += l;
      
      if (i + 1 < lens && s[i] == s[i + 1]) {
        int l = 1;
        while (i - l >= 0 && i + 1 + l < lens && s[i - l] == s[i + 1 + l]) l++;
        result += l;
      }
    }
    return result;
  }
};
```

## Problem 3
```c++
struct Node {
  string from;
  string to;
  int step;
  Node(string a, string b, int c) : from(a), to(b), step(c) {}
};

class Solution {
private:
  void removeMatches(string& s1, string& s2) {
    int i = 0;
    while (i < s1.length())
      if (s1[i] == s2[i]) {
        s1.erase(i, 1);
        s2.erase(i, 1);
      }
      else
        ++i;
  }
public:
  int kSimilarity(string A, string B) {
    queue<Node> nodes;
    
    removeMatches(A, B);
    if (A.length() == 0) return 0;
    nodes.push(Node(A, B, 0));
    
    while (true) {
      Node node = nodes.front();
      nodes.pop();
      
      // swap 2 characters
      int li = -1, lj = -1;
      for (int i = 0; i < node.from.length() && li == -1; ++i)
        for (int j = i + 1; j < node.from.length() && li == -1; ++j)
          if (node.to[i] == node.from[j] && node.to[j] == node.from[i]) {
            li = i;
            lj = j;
          }
      if (li >= 0) {
        string from = node.from, to = node.to;
        swap(from[li], from[lj]);
        removeMatches(from, to);
        if (from.length() == 0) return node.step + 1;
        nodes.push(Node(from, to, node.step + 1));
        continue;
      }
      
      // swap not match characters and push them to queue
      for (int i = 0; i < node.from.length(); ++i)
        for (int j = i + 1; j < node.from.length(); ++j)
          if (node.to[i] == node.from[j]) {
            string from = node.from, to = node.to;
            swap(from[i], from[j]);
            removeMatches(from, to);
            if (from.length() == 0) return node.step + 1;
            nodes.push(Node(from, to, node.step + 1));
          }
    }
  }
};
```

## Problem 4
```c++
class Solution {
public:
  int largestRectangleArea(vector<int>& heights) {
    int maxArea = 0;
    
    int size_of_heights = heights.size();
    set<int> hs;
    for (int e : heights) hs.insert(e);
    vector<int> hm(hs.begin(), hs.end());
    vector<vector<int>> fx(2, vector<int>(hm.size(), 0));
    int size_of_hm = hm.size();
    
    for (int i = 0; i < size_of_hm; ++i)
      if (hm[i] > heights[0])
        fx[0][i] = 0;
      else {
        fx[0][i] = hm[i];
        if (maxArea < fx[0][i]) maxArea = fx[0][i];
      }
    int k = 0;
    
    for (int i = 1; i < size_of_heights; ++i) {
      for (int j = 0; j < size_of_hm; ++j) {
        if (hm[j] > heights[i]) 
          fx[1 - k][j] = 0;
        else {
          fx[1 - k][j] = fx[k][j] + hm[j];
          if (maxArea < fx[1 - k][j]) maxArea = fx[1 - k][j];
        }
      }
      k = 1 - k;
    }
    return maxArea;
  }
};
```
