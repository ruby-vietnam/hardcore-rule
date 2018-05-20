#Problem 1

```cpp
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int p, cnt;
        while (1){
            p = rand()%nums.size();
            cnt = 0;
            for (int i = 0; i < nums.size(); ++i) 
                if (nums[i] == nums[p]) ++cnt;
            if (cnt > nums.size()/2) return nums[p];
        }
    }
};
```
