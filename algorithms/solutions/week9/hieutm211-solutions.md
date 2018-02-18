
##Problem bonus
 
```cpp
class Solution {
public:
    template<class T> inline bool maximize(T& a, T b){ return a < b ? a = b, 1 : 0; }
    
    int findNumberOfLIS(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        
        int ans, LIS, tmp, f[nums.size()], g[nums.size()];        
        
        LIS = 0;
        for (int i = 0; i < nums.size(); ++i){
            tmp = 0;
            for (int j = 0; j < i; ++j)
                if (nums[j] < nums[i]) maximize(tmp, f[j]);
            
            if (tmp == 0) g[i] = 1;
            else {
                g[i] = 0;
                for (int j = 0; j < i; ++j)
                    if (nums[j] < nums[i] && f[j] == tmp) g[i] += g[j];
            } 
                
            f[i] = tmp + 1;
            maximize(LIS, f[i]);
        }
        
        ans = 0;
        for (int i = 0; i < nums.size(); ++i) 
            if (f[i] == LIS) ans += g[i];
        return ans;
    }
};
```