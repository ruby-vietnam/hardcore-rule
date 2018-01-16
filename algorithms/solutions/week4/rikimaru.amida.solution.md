## Problem 1: Jump Game II
- **Leetcode URL**: https://leetcode.com/problems/jump-game-ii/description/
- **Language**: Java
- **Source**:
```
class Solution {
    public int jump(int[] nums) {
        if (nums.length < 2) {
            return 0;
        } else {
            if (nums[0] >= nums.length) {
                return 1;
            } else {
                int count = 1;
                int index = 0;
                int current = nums[index];
                while(index + current < nums.length - 1) {
                    count++;
                    int max = 0;
                    int newIndex = index;
                    for (int i = index + current; i > index; i--) {
                        if (max < nums[i] + i) {
                            max = nums[i] + i;
                            newIndex = i;
                        }
                    }
                    
                    if (max <= index) {
                        return 0;
                    } else {
                        index = newIndex;
                        current = nums[index];
                    }
                }
                
                return count;
            }
        }
    }
}
```
