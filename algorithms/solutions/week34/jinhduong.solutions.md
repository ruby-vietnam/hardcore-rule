# #1. House Robber
```csharp
public class Solution {
    public int Rob(int[] nums) {
        var len = nums.Length;
        if (len == 0) return 0;
        if (len == 1) return nums[0];

        nums[1] = nums[0] > nums[1] ? nums[0] : nums[1];
        for (var i = 2; i < nums.Length; i++) {
            nums[i] = Math.Max (nums[i] + nums[i - 2], nums[i - 1]);
        }

        return nums[len - 1];
    }
}
```