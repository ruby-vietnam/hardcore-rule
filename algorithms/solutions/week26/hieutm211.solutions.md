## Problem 1

```cpp
class Solution {
public:
    char findTheDifference(string s, string t) {
        int cnt[26];
        for (int i = 0; i < 26; ++i) cnt[i] = 0;
        
        for (auto& c : s) ++cnt[c-'a'];
        for (auto& c : t) --cnt[c-'a'];
        for (int i = 0; i < 26; ++i)
            if (cnt[i]) return (char)('a' + i);
    }
};
```
