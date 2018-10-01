##Problem 1

```cpp
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0;
        for (int& x : nums) ans ^= x;
        return ans;
    }
};
```

##Problem 2

```cpp
class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size()+1;
        
        bool f[n][n];
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                if (i == n-1 || j == n-1 || i > j) f[i][j] = 1;
        
        for (int i = n-2; i >= 0; --i){
            f[i][i] = 1;
            for (int j = i+1; j < n-1; ++j) f[i][j] = f[i+1][j-1] && (s[i] == s[j]);
        }
        
        int ans = 0;
        for (int i = 0; i < n-1; ++i)
            for (int j = i; j < n-1; ++j)
                ans += f[i][j];
        return ans;
    }
};
```
