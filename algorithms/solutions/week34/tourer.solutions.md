# Problem 1

## [House Robber](https://leetcode.com/problems/house-robber/description/)
```java
class Solution {
    public int rob(int[] nums) {
        if(nums.length == 0) {
            return 0;
        }
        if(nums.length == 1) {
            return nums[0];
        }      
        int[] bests = new int[nums.length];
        bests[0] = nums[0];
        bests[1] = Math.max(nums[0], nums[1]);
        for(int i = 2; i < nums.length; i++) {
            bests[i] = Math.max(bests[i-1], bests[i-2] + nums[i]);
        }
        
        return bests[nums.length-1];
    }
}
```
