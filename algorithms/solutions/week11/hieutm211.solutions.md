
# Problem 4: Range Sum Query

```Cpp
class NumArray {
public:
    vector<int> a, fw;
    int n;
    
    void fw_update(int i, int val){
        for (; i < n; i += i & -i) fw[i] += val;    
    }

    int fw_get(int i){
        int ans = 0;
        for (; i > 0; i -= i & -i) ans += fw[i];
        return ans;
    }
    
    NumArray(vector<int> nums) {
        a.push_back(0); 
        fw.push_back(0);
        
        for (int i = 0; i < nums.size(); ++i){
            a.push_back(nums[i]);
            fw.push_back(0);
        }
        
        n = a.size();
        for (int i = 1; i < n; ++i) fw_update(i, a[i]);
    }
    
    void update(int i, int val) {
        ++i;
        fw_update(i, -a[i]);
        a[i] = val;
        fw_update(i, +a[i]);
    }
    
    int sumRange(int i, int j) {
        ++i; ++j;
        return fw_get(j) - fw_get(i-1);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * obj.update(i,val);
 * int param_2 = obj.sumRange(i,j);
 */
```
