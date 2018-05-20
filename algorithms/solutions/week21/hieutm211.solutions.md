##Problem 1

```cpp
class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) return 0;
        
        int c[26];
        
        for(int i = 0; i < 26; ++i) c[i] = 0;
        
        for(int i = 0; i < s.size(); ++i) ++c[s[i]-'a'];
        for(int i = 0; i < t.size(); ++i) --c[t[i]-'a'];
        
        for(int i = 0; i < 26; ++i) 
            if (c[i] != 0) return 0;
        
        return 1;
    }
};
```
