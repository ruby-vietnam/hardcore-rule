# Problem 2:
https://leetcode.com/problems/perfect-squares/description/

```java
class Solution {
    public int numSquares(int n) {
        if(n == 0 || n == 1){
            return 1;
        }
        
        int[] dp = new int[n+1];
        
        dp[0] = 1;
        dp[1] = 1;
        
        for(int i = 2; i <= n; i++){
            int min = Integer.MAX_VALUE;
            for(int k = 1; k < i; k++){
                if(i == k * k){
                    dp[i] = 1;
                    break;
                }else if(i > k*k){
                    if(min > dp[i - k*k]){
                        min = dp[i - k*k];
                    }
                    dp[i] = min + 1;
                }else{
                    break;
                }
            }
        }
        
        return opt[n];
    }
}
```