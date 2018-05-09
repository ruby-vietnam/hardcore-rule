## Problem 1

```cpp
class Solution {
public:
    bool validPalindrome(string s) {
        int i, j, u, v; 
        
        i = 0; j = s.size()-1;
        while (i < j && s[i] == s[j]){ ++i; --j; }
        if (i >= j) return 1;
        
        u = i+1; v = j;
        while (u < v && s[u] == s[v]){ ++u; --v; }
        if (u >= v) return 1;
        
        u = i; v = j-1;
        while (u < v && s[u] == s[v]){ ++u; --v; }
        if (u >= v) return 1;
        
        return 0;
    }
};
```