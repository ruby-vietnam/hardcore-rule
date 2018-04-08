
##Problem 1:

```cpp
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        vector<pair<int, int> > p;
        
        for (int i = 0; i < nums.size(); ++i) p.push_back({nums[i], i});
        
        sort(p.begin(), p.end(), [](pair<int, int>& a, pair<int, int>& b){ 
            if (a.first == b.first) return a.second < b.second;
            return a.first < b.first;
        });
        
        for (int i = 1; i < p.size(); ++i) 
            if (p[i].first == p[i-1].first && p[i].second - p[i-1].second <= k) return 1;
        return 0;
    }
};
```