problem1: https://leetcode.com/problems/valid-anagram/description/

We can use 2 map to store the character of both strings and then compare the frequent of each character. Time complexity is O(n) and Space complexity is O(1)

```java
public boolean isAnagram(String s, String t) {
   if (s == null && t == null) return true;
   if (s.length() != t.length()) return false;
   
   Map<Character, Integer> sm = new HashMap<>();
   Map<Character, Integer> tm = new HashMap<>();
   
   for (int i = 0; i < s.length(); i++) {
     sm.put(s.charAt(i), sm.getOrDefault(s.charAt(i), 0) + 1);
     tm.put(t.charAt(i), tm.getOrDefault(t.charAt(i), 0) + 1);
   }
   
   if (sm.keySet().size() != tm.keySet().size()) return false;
   for (Character c: sm.keySet()) {
     if (!tm.containsKey(c) || tm.get(c).intValue() != sm.get(c).intValue()) return false;
   }
   return true;
  }
```
