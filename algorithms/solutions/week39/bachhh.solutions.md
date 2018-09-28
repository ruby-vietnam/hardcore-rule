# Problem 3
```cpp
class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        vector<int> v = vector<int>(nums.size()+1, 0);
        for(int i = 0 ; i < nums.size(); i++){
            v[i+1] = v[i] + nums[i];
            if (k ==0 && i > 0 && nums.size() > 1 && v[i+1] == 0 && v[i] == 0 ) return true;
        }
        if (k==0) return false;
        for(int i = 1 ;i < v.size()-1; ++i){
            for(int j = i+1; j < v.size(); ++j){
                if ((v[j] -v[i-1])%k == 0) return true;
            }
        }
        return false;
    }
};```
