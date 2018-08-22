# Problem 1
#### [House Robber](https://leetcode.com/problems/house-robber/description/)
```cs
public class Solution {
    public int Rob(int[] nums) {
        
        var dp = new int[nums.Length];
        
        for(var i = 0; i < nums.Length; i++){
            dp[i] = nums[i];
            if(i - 2 >= 0){
                dp[i] += dp[i - 2];
            }
            
            if(i - 1 >= 0){
                dp[i] = Math.Max(dp[i], dp[i - 1]);
            }
        }
        
        return nums.Length > 0 ? dp[nums.Length - 1] : 0;
    }
}
```


