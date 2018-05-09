# Bai 1: https://leetcode.com/problems/valid-anagram/description/

```
class Solution {
public:
    bool isAnagram(string s, string t) {
        // simple way
        /*int check[26] = {0};
        if(s.length() != t.length()) return false;
        
        for(int i = 0; i < s.length(); i++)
        {
            check[s[i]-'a']++;
            check[t[i]-'a']--;
        }
        
        for(int i = 0;i< 26; i++)
        {
            if(check[i] != 0)
                return false;
        }
        return true;*/
        
        // trick method
        int s1 = 0, s2 = 0, s3 = 0;
        if(s.length() != t.length()) return false;
        
        for(int i =0;i < s.length(); i++)
        {
            s1 += s[i] - t[i];
            s2 += s[i] * s[i] - t[i] * t[i];
            s3 += s[i] * s[i]* s[i] - t[i] * t[i]* t[i];
        }
        if(!s1 && !s2 && !s3) return true;
        return false;
    }
};
```
