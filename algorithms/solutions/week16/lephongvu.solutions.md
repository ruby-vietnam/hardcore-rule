#Bai 1:
```

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int n = nums.size();
        std::unordered_map<int, int> m;
        for(int i = 0; i < n; i++)
        {
            if(m.find(nums[i]) != m.end() &&  i - m[nums[i]] <= k)
            {
                return true;
            }
            m[nums[i]] = i;
        }
        return false;
    }
};

```
