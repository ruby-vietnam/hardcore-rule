#Problem 1
``` Java 
class Solution {
    public int climbStairs(int n) {
       return climbStairs(n, new int[n +1]);
    }
    
    private int climbStairs(int n, int[] result){
        if (n < 0) return 0;
        if (n == 0) return 1;
        
        if (result[n] > 0) return result[n];
        result[n] = climbStairs(n - 1, result) + climbStairs(n-2, result);
        return result[n];
    }
}
```
