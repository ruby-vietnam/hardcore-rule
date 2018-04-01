#Problem 1

```cpp
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int j = 0;
        for (int i = 0; i < nums.size(); ++i)
        if (nums[i] == 0){
            for (j = max(j, i+1); j < nums.size() && nums[j] == 0; ++j);
            if (j == nums.size()) break;
            swap(nums[i], nums[j]);
        }
    }
};
```
