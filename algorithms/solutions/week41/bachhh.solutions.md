# problem 1

```cpp
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        set<int> s;
        for (int i : nums){
            if (s.count(i) > 0){
                s.erase(i);
            }
            else {
                s.insert(i);

            }
        }
        return *s.begin();
    }
};
```

