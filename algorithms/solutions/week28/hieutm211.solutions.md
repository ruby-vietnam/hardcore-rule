## Problem 2

```cpp
class Solution {
public:
    vector<vector<int>> ans;    
    vector<int> x, tmp;
    vector<bool> mark;
    
    void backtrack(vector<int>& nums, int i){
        if (i == nums.size()){
            tmp.clear();
            for(int j = 0; j < nums.size(); ++j) tmp.push_back(nums[x[j]]);
            ans.push_back(tmp);
            return;
        }
        for (int j = 0; j < nums.size(); ++j)
        if (!mark[j]){
            x[i] = j;
            mark[j] = 1;
            backtrack(nums, i+1);
            mark[j] = 0;
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        for(int i = 0; i < nums.size(); ++i){
            x.push_back(0);
            mark.push_back(0);
        }
        backtrack(nums, 0);
        return ans;   
    }
};
```
