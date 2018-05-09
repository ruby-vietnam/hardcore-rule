# Bai 1: https://leetcode.com/problems/move-zeroes/
```
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int length = nums.size();
        if (length == 1) return;
        int j = 0;
        for(int i = 0; i < length; i++)
        {
            if(nums[i] != 0)
                nums[j++] = nums[i];
        }
        for(; j < length; j++)
        {
            nums[j] = 0;
        }
    }
};
```
