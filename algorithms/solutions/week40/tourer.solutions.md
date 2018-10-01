# Problem 3

## [Longest Palindromic Substring](https://leetcode.com/problems/longest-palindromic-substring/description/)
```java
class Solution {
    public String longestPalindrome(String s) {
        int longest = 0;
        String res = "";
        for(int i = 0; i < s.length(); i++) {
            for(int j = i + longest; j < s.length(); j++) {
                String sub = s.substring(i,j+1);
                if(sub.length() > longest && isPalindrom(sub)) {
                    longest = sub.length();
                    res = sub;
                }
            }
        }
        
        return res;
    }
    
    private boolean isPalindrom(String s) {
        for(int i = 0; i + i < s.length(); i++) {
            if(s.charAt(i) != s.charAt(s.length()-1-i)) return false;
        }
        
        return true;
    }
}
```
