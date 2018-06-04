Problem1: https://leetcode.com/problems/sum-of-square-numbers/description/

We loop a from 0 and check whether a * a < c or not, if yes, then calculate b, if there is b, then return true.

Please take note that we need a is long type as if it is int then a * a can be negative value.

Time complexity is O(sqrt(c) * logc)
Space complexity is O(1)


```java
public boolean judgeSquareSum(int c) {
        for (long a = 0; a * a <= c;a++) {
          double b = Math.sqrt(c - a * a);
          if (b == (int) b) return true;
        }
      return false;
    }
```
Problem2: https://leetcode.com/problems/largest-number/description/

We can use Comparator to compare between 2 element in nums arrays. The rule is make (e1 + e2) string compare with (e2+e1) string.

Time Complexity is O(nlogn) as the sort in Java use that.
Space complexity is O(n) as I create a list of Integer from initial int[] array

```java
import java.util.Arrays;
import java.util.Collections;
import java.util.Comparator;
import java.util.List;
import java.util.stream.Collectors;

class Solution {
    public String largestNumber(int[] nums) {
        List<Integer> list = Arrays.stream(nums).boxed().collect(Collectors.toList());
    
    Comparator<Integer> comparator = (i1, i2) -> {
      String str1 = String.valueOf(i1) + String.valueOf(i2);
      String str2 = String.valueOf(i2) + String.valueOf(i1);
      return str2.compareTo(str1);
    };
    
    Collections.sort(list, comparator);
    if (list.get(0) == 0) {
        return "0";
    }  
      
    StringBuilder sb = new StringBuilder();
    for (Integer num: list) {
      sb.append(num);
    }
    
    return sb.toString();
    }
}
```
