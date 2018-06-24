# Problem 1

## [Find the Difference](https://leetcode.com/problems/find-the-difference/description/)
```java
class Solution {
    public char findTheDifference(String s, String t) {
        int[] firstStringCount = countLetter(s);
        int[] secondStringCount = countLetter(t);
        
        for(int i = 0; i < 26; i++) {
            if(firstStringCount[i] < secondStringCount[i]) {
                return (char)('a' + i);
            }
        }        
        throw new IllegalArgumentException();
    }
    
    private int[] countLetter(String s) {
        int[] count = new int[26];
        for(int i = 0, len = s.length(); i < len; i++) {
            count[s.charAt(i) - 'a']++;
        }
        
        return count;
    }
        
}
```
