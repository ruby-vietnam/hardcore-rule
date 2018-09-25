
##Problem 1

```cpp
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> ans(0);

        for (int i = 0, j = 0; i < m || j < n; ){
            if ((j == n && i < m) || (i < m && j < n && nums1[i] <= nums2[j])){
                ans.push_back(nums1[i]);
                ++i;
            }
            if ((i == m && j < n) || (i < m && j < n && nums1[i] > nums2[j])){
                ans.push_back(nums2[j]);
                ++j;
            }
        }
        for (int i = 0; i < m+n; ++i) nums1[i] = ans[i];
    }
};
```

##Problem 2

```cpp
class Solution {
public:
    int numSquares(int n) {
        vector<int> ps(0);
        for (int i = 1; i*i <= n; ++i) ps.push_back(i*i);
        
        vector<int> f(n+1, n+1);
        f[0] = 0;
        for (int i = 1; i <= n; ++i){
            for (int j = 0; j < ps.size(); ++j) 
                if (i - ps[j] >= 0 && f[i] > f[i-ps[j]] + 1) f[i] = f[i-ps[j]] + 1;
        }
        
        return f[n];
    }
};
```
