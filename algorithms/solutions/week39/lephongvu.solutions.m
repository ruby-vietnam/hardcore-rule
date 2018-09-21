#Bai 1:

```
class Solution {
public:
    int reverse(int x) {
        long long res = 0;
        int y = std::abs(x);
        while (y)
        {
            int temp  = y % 10;
            res = res * 10 + temp;
            y = y/10;
        }
        res = (x < 0) ?  -res : res;
        if( res > INT_MAX || res < INT_MIN) return 0;
        return res;
        
    }
};
```
