# Problem 1:
#### [Valid Anagram](https://leetcode.com/problems/valid-anagram/)
```java
class Solution {
    public boolean isAnagram(String s, String t) {
        int[] cntS = countLetter(s);
        int[] cntT = countLetter(t);
        for(int i = 0; i < cntS.length; i++) {
            if(cntS[i] != cntT[i]) return false;
        }
        return true;
    }
    
    private int[] countLetter(String s) {
        final int MAX_LETTER  = 26;
        int[] cntLetter = new int[MAX_LETTER];
        for(int i = 0, len = s.length(); i < len; i++) {
            cntLetter[s.charAt(i) - 'a']++;
        }
        return cntLetter;
    }
}
```

