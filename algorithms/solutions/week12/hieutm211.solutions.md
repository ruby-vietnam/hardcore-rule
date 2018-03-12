
# Problem 2: Teemo attacking


```cpp
class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        int ans = 0;
        
        timeSeries.push_back(10000000+duration);
        for(int i = 0; i < timeSeries.size()-1; ++i)
            ans += max(0, min(duration, timeSeries[i+1]-timeSeries[i]));
        
        return ans;
    }
};
```
