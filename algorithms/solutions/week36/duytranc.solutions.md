# Problem 1
#### [Climbing Stairs](https://leetcode.com/problems/climbing-stairs/description/)
```cs
public class Solution {
    public int ClimbStairs(int n) {
        int[] counts = new int[n];
        
        if(n >= 1) counts[0] = 1;
        if(n >= 2) counts[1] = 2;
        
        for(var i = 2 ; i < n ; i ++)
            counts[i] = counts[i - 1] + counts[i - 2];
        
        return counts[n - 1];
    }
}
```