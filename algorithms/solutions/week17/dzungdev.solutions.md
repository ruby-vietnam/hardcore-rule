Problem1: https://leetcode.com/problems/isomorphic-strings/

We use the map to contain the source character map to destination character. If the map contains the source character, we need to check the value must be same.
If the map doesn't contain the source character, we need to get the list of current destination and check whether it contains the destination character.

For example: aba and baa are wrong because a map to b and a
             ab and aa are wrong because a and b map to same a
             
Space complexity is O(n) and Time complexity is O(n)

```java
  public boolean isIsomorphic(String s, String t) {
    if (s == null || t == null || s.length() != t.length())
      return false;
    char[] sc = s.toCharArray();
    char[] tc = t.toCharArray();
    Map<Character, Character> map = new HashMap<>();
    for (int i = 0; i < sc.length; i++) {
      if (map.containsKey(sc[i])) {
        if (map.get(sc[i]) != tc[i])
          return false;
      } else {
        if (map.values().contains(tc[i]))
          return false;
        map.put(sc[i], tc[i]);
      }
    }
    return true;
  }
```
