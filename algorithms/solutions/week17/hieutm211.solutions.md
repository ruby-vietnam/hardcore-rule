##Problem 1:

```cpp
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        char c[256], rc[256];    
        int n = s.size();
        
        for (int i = 0; i < n; ++i){
            c[s[i]] = t[i];
            rc[t[i]] = s[i];
        }
        
        for (int i = 0; i < n; ++i)
            if (c[s[i]] != t[i] || rc[t[i]] != s[i]) return 0;
            
        return 1;
    }
};
```
