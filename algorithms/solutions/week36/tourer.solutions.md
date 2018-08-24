# Problem 1

## [Climbing Stairs](https://leetcode.com/problems/climbing-stairs/description/)
```java
class Solution {
    public int climbStairs(int n) {
        int[] ways = new int[n+1];
        ways[0] = 1;
        for(int i = 1; i <= n; i++) {
            ways[i] = ways[i-1];
            if(i - 2 >= 0) {
                ways[i] += ways[i-2];
            }
        }
        
        return ways[n];
    }
}
```
