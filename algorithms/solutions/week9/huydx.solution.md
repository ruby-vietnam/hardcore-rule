# Problem 1

```java
import java.util.*;

class Solution {
    public int findLHS(int[] nums) {
        Map<Integer, Integer> max = new HashMap<>();
        Map<Integer, Boolean> mark = new HashMap<>();
        
        for (int i : nums) {
            mark.put(i, true);
            if (max.get(i) == null) { max.put(i, 1); }
            else { max.put(i, max.get(i)+1); }

            if (max.get(i-1) == null) { max.put(i-1, 1); }
            else { max.put(i-1, max.get(i-1)+1); }
        }

        System.out.println(max);
        int m = Integer.MIN_VALUE;
        for (Map.Entry<Integer, Boolean> entry : mark.entrySet()) {
            int k = entry.getKey();
            if (mark.get(k-1) != null || mark.get(k+1) != null) {
                int v = max.get(k);
                if (m < v) { m = v; }
            }
        };
        
        return m >= 0 ? m : 0;
    }
}
```
