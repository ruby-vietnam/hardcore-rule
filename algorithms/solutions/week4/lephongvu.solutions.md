# Loi giai cho bai sort color
O(2n)

đang suy nghĩ tiếp :v 

```
void sortColors(vector<int>& nums) {
      int a[3] = {0};
        for(auto c: nums)
        {
            a[c]++;
        }
        
        for(int i = 0; i < nums.size(); i++)
        {
            if( a[0] > 0 && i < a[0])
                nums[i] = 0;
            else if (a[1] > 0 && i < a[0] + a[1])
                nums[i] = 1;
            else if( a[2] > 0) nums[i] = 2;
        }  
}
```
