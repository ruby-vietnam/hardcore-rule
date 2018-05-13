# Bai 1:

```
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int> result ;
        int a = 1;
        for(int i = digits.size()-1; i >= 0; i--)
        {
            digits[i] += a;
            if(digits[i] == 10){
              digits[i] = 0;
              a = 1;
            } 
            else {
                a = 0;
                break;
            }  
        }
        if( a == 1) digits.insert(digits.begin(),1);
        
        return digits;
    }
};
```

