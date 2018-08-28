# #1 Climbing Stairs
``` csharp
public class Solution {
    public int ClimbStairs(int n) {
        int result = 1, temp;
        int a = 1;
        for (int i = 1; i < n; i++) {
            temp = result;
            result += a;
            a = temp;

        }

        return result;
    }
}
```