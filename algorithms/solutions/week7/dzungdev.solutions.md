Problem1

We loop the character list and use the Map to store the count number of the character. Then we will know which character is first unique character
Time Complexity is O(n)

```java
public int firstUniqChar(String s) {
        Map<Character, Integer> countMap = new HashMap<>();
        char[] chars = s.toCharArray();
        for (char c: chars) {
            countMap.put(c, countMap.containsKey(c) ? countMap.get(c) + 1: 1);
        }
        for (int i = 0; i < chars.length;i++) {
            if (countMap.get(chars[i]) == 1) {
                return i;
            }
        }
        return -1;
    }
```
