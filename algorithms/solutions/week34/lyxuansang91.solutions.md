## Problem 1 - [House Robber](https://leetcode.com/problems/house-robber/description/)

Solution: Using DP (Dynamic programming).
Let S(i) is maximum amount of money you can rob tonight without alert the police end at i (0 <= i < n). We will calculate s(i) by:
- s(0) = nums(0)
- s(1) = max(s(0), nums(1))
- s(i) = max(s(j)) + nums(i) (0 <= j <= i-2)

We can caculate s(i) in solution O(N^2) but we can calculate s(i) in solution O(N) because we can calculate max(s(j)) in O(N).


```cpp
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size(); 
        if(n == 0) return 0;
        int* s = new int[n];
        s[0] = nums[0];
        int result = s[0];
        int temp = 0;
        for(int i = 1; i < n; i++) {
            s[i] = nums[i];
            if(i >= 2 && temp < s[i-2]) temp = s[i-2];
            s[i] = (s[i] > temp + nums[i] ? s[i] : temp + nums[i]);
            result = (result > s[i] ? result : s[i]);
        }
        return result;
    }
};
```