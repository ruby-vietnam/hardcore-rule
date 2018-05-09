# Problem 1

```java
class Solution {
    public void moveZeroes(int[] nums) {
        int[] nums2 = new int[nums.length];
        int j = 0;
        for (int i = 0; i < nums.length; i++) {
            if (nums[i] != 0) {
                nums2[j++] = nums[i];
            }
        }
        System.arraycopy(nums2, 0, nums, 0, nums.length);
    }
}
```
