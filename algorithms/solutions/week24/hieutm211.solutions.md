#Problem 2

```cpp
class Solution {
public:
    long long pow10[11] = {1, 10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000, 1000000000, 10000000000};
    
    long long combine(int a, int b){
        if (b == 0) return (long long) a*10;
        return (long long) a * pow10[(int) log10(b) + 1] + b;
    }
    
    bool checkArray0(vector<int>& nums){
        for (int i = 0; i < nums.size(); ++i) 
            if (nums[i]) return 0;
        return 1;
    }
    
    string largestNumber(vector<int>& nums) {
        if (checkArray0(nums)) return "0";
        
        sort(nums.begin(), nums.end(), [=](int a, int b){
            return combine(a, b) > combine(b, a);
        });

        string ans = "";        
        for(int i = nums.size()-1; i >= 0; --i){
            if (nums[i] == 0) ans = '0' + ans;
            while(nums[i]){
                ans = (char) (nums[i] % 10 + '0') + ans;
                nums[i] /= 10;
            }
        }
        
        return ans;
    }
};
```