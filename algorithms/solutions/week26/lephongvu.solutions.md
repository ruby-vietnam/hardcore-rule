# Bai 1:

```
class Solution {
public:
    char findTheDifference(string s, string t) {
        int key = 0,i = 0;
        for(; s[i] ; i ++)
            key+=t[i]-s[i];
        return key+t[i];
    }
};
```
