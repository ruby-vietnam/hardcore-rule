#Problem 1
``` Java
class Solution {
    public boolean isAnagram(String s, String t) {
        if (s.length() != t.length()){
            return false;
        }
        char[] charsS = s.toCharArray();
        char[] charsT = t.toCharArray();
        Arrays.sort(charsS);
        Arrays.sort(charsT);
                   
        return String.valueOf(charsS).equals(String.valueOf(charsT));
    } 
}
```
