##Problem 1

```cpp
class Solution {
public:
    int climbStairs(int n) {
        if (n == 0) return 0;
        if (n == 1) return 1;
        
        int f[n];
        f[0] = 1;
        f[1] = 2;
        for (int i = 2; i < n; ++i) f[i] = f[i-1] + f[i-2];
        return f[n-1];
    }
};
```
##Problem 2

```cpp 
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        bool mark[256];
        int ans, j;
        
        ans = 0;
        for (int i = 0; i < s.size(); ++i){
            for (j = 0; j < 256; ++j) mark[j] = 0;
            for (j = i; j < s.size() && !mark[s[j]]; ++j) mark[s[j]] = 1;
            ans = max(ans, j-i);
        }
        return ans;
    }
};
```

##Problem 3

```
class Solution {
public:  
    void visit(int& root, int u, bool * visited, vector<int> * adj, bool& circle){
        if (circle) return;
        visited[u] = 1;
        for (auto& v : adj[u])
        if (v == root) circle = 1;
        else if (!visited[v]) visit(root, v, visited, adj, circle);
    }
    
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        if (numCourses == 1) return 1;
        
        vector<int> adj[numCourses+1];
        bool circle, visited[numCourses+1];

        for (auto& p : prerequisites) adj[p.second].push_back(p.first);
  
        for (int i = 0; i < numCourses; ++i){
            for (int j = 0; j < numCourses; ++j) visited[j] = 0;
            circle = 0;
            visit(i, i, visited, adj, circle);
            if (circle) return 0;
        }
        return 1;
    }
};
```

##Problem 4

```cpp
class Solution {
public:
    const int base = 1000000007;
    int sumSubseqWidths(vector<int>& A) {
        if (A.size() == 1) return 0;
        
        int ans, pow2[A.size()];
        
        pow2[0] = 1;
        for (int i = 1; i < A.size(); ++i) pow2[i] = (2LL * pow2[i-1]) % base;
        
        sort(A.begin(), A.end());
        
        ans = 0;
        for (int i = 0; i < A.size(); ++i){
            ans = ((long long) ans + ((long long) A[i] * (pow2[i]-1)) % base) % base;
            ans = ((long long) ans - ((long long) A[i] * (pow2[A.size()-i-1]-1)) % base + base) % base;
        }
        return ans;
    }
};
```
