# Problem 1

## [Non-decreasing Array](https://leetcode.com/problems/non-decreasing-array/description/)
```java
class Solution {
    public boolean checkPossibility(int[] nums) {
        for(int i = 0; i < nums.length; i++) {
            int origin = nums[i];
            if(i + 1 < nums.length) {
                nums[i] = nums[i+1];
            } else {
                nums[i] = Integer.MAX_VALUE;
            }
            if(isNonDeacreasing(nums)) {
                return true;
            }
            nums[i] =  origin;
        }
        return false;
    }
    
    private boolean isNonDeacreasing(int[] nums) {
        for(int i = 1; i < nums.length; i++) {
            if(nums[i-1] > nums[i]) {
                return false;
            }
        }
        return true;
    }
}
```
