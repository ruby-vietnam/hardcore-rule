# Problem 1
``` java
class Solution {
    public boolean isIsomorphic(String s, String t) {
        if (s.length() != t.length()){
            return false;
        }
        
        char[] sChars = s.toCharArray();
        char[] tChars = t.toCharArray();
        
        HashMap<Character, Character> map = new HashMap<Character, Character>();
        for (int i = 0 ; i < s.length(); i++){
            if (map.get(sChars[i]) == null){
                if (map.containsValue(tChars[i])){
                    return false;
                }
                map.put(sChars[i], tChars[i]);
            } else {
                if (map.get(sChars[i]) != tChars[i]){
                    return false;
                }
            }
        }
        return true;
    }
}
```
