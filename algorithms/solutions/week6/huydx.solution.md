# Problem 1

```
import java.util.*;

class Solution {
    public int findShortestSubArray(int[] nums) {
        Map<Integer, Integer> minPos = new HashMap<>();
        Map<Integer, Integer> maxPos = new HashMap<>();        
        Map<Integer, Integer> accessCount = new HashMap<>();
        int max = -1;
        int maxNum = -1;
        int minSubArr = Integer.MAX_VALUE;
        for (int i = 0; i < nums.length; i++) {
            int n = nums[i];
            Integer c = accessCount.get(n);
            if (c == null) {
                accessCount.put(n, 1);
                c = 1;
            } else {
                c += 1;
            }
            if (minPos.get(n) == null) { minPos.put(n, i); }
            maxPos.put(n, i); 
            if (c > max) {
                max = c;
                maxNum = n;
                minSubArr = maxPos.get(maxNum) - minPos.get(maxNum) + 1;
            } else if (c == max) {
                int m1 = maxPos.get(maxNum) - minPos.get(maxNum) + 1;;
                int m2 = maxPos.get(n) - minPos.get(n) + 1;;
                minSubArr = m1 < m2 ? m1 : m2;
            }
            accessCount.put(n, c);
        }

        return minSubArr;
    }
}
```
