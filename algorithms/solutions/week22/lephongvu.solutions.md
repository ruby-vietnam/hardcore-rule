# Bai 1 :

```
class Solution {
public:
    int majorityElement(vector<int>& num) {
        int major=num[0], count = 1;
        for(int i=1; i<num.size();i++){
            if(count==0){
                count++;
                major=num[i];
            }else if(major==num[i]){
                count++;
            }else count--;
            
        }
        return major;
    }
};
```
