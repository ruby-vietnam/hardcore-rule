# Problem 1

```java
import java.util.Arrays;

class Solution {
    public char findTheDifference(String s, String t) {
        int[] arr = new int[100];
        for (char sc : s.toCharArray()) {
            arr[sc-'0']++;
        }
        for (char tc : t.toCharArray()) {
            arr[tc-'0']--;
        }
        
        for (int i = 0; i < 100; i++) {
            if (arr[i] != 0) {
                return (char)(i+'0');
            }
        }
        debug(arr);
        throw new IllegalStateException();
     }
    
    public void debug(Object ...obj) {
        if (true) {
            System.out.printf(Arrays.deepToString(obj));
        }
    }
}
```
