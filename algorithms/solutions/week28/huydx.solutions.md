# Problem 1

```java
class Solution {
    public boolean checkPossibility(int[] nums) {
        int l = nums.length;
        int c = 0;
        for (int i = 0; i < l - 1 && c <= 1; ++i) {
            if (nums[i] > nums[i + 1]) {
                if (i > 0) {
                    if (nums[i - 1] <= nums[i + 1]) {
                        nums[i] = nums[i - 1];
                    } else {
                        nums[i + 1] = nums[i];
                    }
                }
                ++c;
            }
        }
        return c <= 1;
    }
    
    private void debug(Object ...objects) {
        if (true) {
            System.out.println(Arrays.deepToString(objects));        
        }
    }
}
```
