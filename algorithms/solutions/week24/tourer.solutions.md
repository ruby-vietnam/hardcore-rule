# Problem 3

## [Coin Change](https://leetcode.com/problems/coin-change/description/)
```java
class Solution {
    public int coinChange(int[] coins, int amount) {
        int[] f = new int[amount+1];
        Arrays.fill(f, Integer.MAX_VALUE);
        f[amount] = 0;
        for(int i = amount; i > 0; i--) {
            if(f[i] == Integer.MAX_VALUE) {
                continue;
            }
            for(int j = 0; j < coins.length; j++) {
                if(i >= coins[j] && f[i - coins[j]] > f[i] + 1) {
                    f[i-coins[j]] = f[i] + 1;
                }
            }
        }
        
        return f[0] == Integer.MAX_VALUE ? -1 : f[0];
    }
}
```
