# Problem 1: 
https://leetcode.com/problems/single-number/description/

```java
class Solution {
    public int singleNumber(int[] nums) {
        
        int ret = nums[0];
        for (int i=1; i<nums.length; i++) {
            ret ^= nums[i];
        }
        
        return ret;
    }
}
```

