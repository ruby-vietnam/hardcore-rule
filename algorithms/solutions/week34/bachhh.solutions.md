# Problem 1
```cpp
class Solution {
public:
    vector<int> memoi;
    int rob(vector<int>& nums) {
        int len = nums.size();
        if (len == 0 ) return 0;
        vector<int> memoi = vector<int>(len+3, 0);
        memoi[0] = nums[0];
        memoi[1] = max(nums[0], nums[1]);
        for(int i = 2; i < len; i++){
            memoi[i] = max(nums[i] + memoi[i-2], memoi[i-1]);
        }
        return memoi[len-1];
    }

};
```
