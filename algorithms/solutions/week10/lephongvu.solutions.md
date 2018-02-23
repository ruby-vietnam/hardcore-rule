# Problem 1:

```
class Solution {
public:
    
    bool palin(string s)
    {
        return s == string(s.rbegin(), s.rend());
    }
    
    bool validPalindrome(string s) {
        int l = s.length();
        for (int i = 0 ; i <= s.length() /2 ; i++)
        {
            if(s[i] != s[l-i-1]) {
                if(s[i] == s[l-i-2])
                {
                    if(palin(s.substr(i,l-i-1-i)))
                        return true;
                }
                if(s[i+1] == s[l-i-1])
                {
                     if(palin(s.substr(i+1, l-i-1-i)))
                        return true;
                }
                return false;
            }
        }
        return true;
    }
};
```

# Problem 3: IsSubsequence:
```
class Solution {
public:
    bool isSubsequence(string s, string t) {
        int i = 0; 
        for(int j = 0; j < t.length(); j++)
        {
            if(t[j] == s[i]) i++;
        }
        if(i == s.length()) return true;
        return false;
    }
};
```
