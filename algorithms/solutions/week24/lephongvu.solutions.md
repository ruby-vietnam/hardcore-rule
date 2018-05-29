#Bai 1:
https://leetcode.com/submissions/detail/156372298/
```
class Solution {
public:
    bool judgeSquareSum(int c) {
        int b = 0, e = (int)sqrt(c);
        while(b <= e) {
            int sum = b * b + e * e;
            if (sum == c) {
                return true;
            } else if (sum >= c) {
                e--;
            } else {
                b++;
            }
        }
        return false;
    }
};

```

# Bai 2:
https://leetcode.com/problems/largest-number/description/
```
class Solution {
public:
    
    static bool greater(const int &a, const int &b)
    {
        string x = to_string(a);
        string y = to_string(b);
        return x + y > y + x;
    }
    
    string largestNumber(vector<int>& nums) {
        std::sort(nums.begin(), nums.end(), greater);
        string res;
        if(nums[0] == 0) return "0";
        for(int num : nums)
            res+= to_string(num);
        
        return res;
    }
};
```
