# Bai 1: https://leetcode.com/problems/nim-game/description/
```
class Solution {
    public boolean canWinNim(int n) {
        return n%4;
    }
}
```


# Bai 2: https://leetcode.com/problems/teemo-attacking/description/\

```
class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        int t = 0;
        int sum = 0;
        for(auto c: timeSeries)
        {
            if(c < t)
                sum += duration -  (t - c );
            else 
                sum += duration;
            t = c + duration;
        }
        return sum;
    }
    
};
```
