# Problem 1
``` java
class Solution {
    public boolean canWinNim(int n) {
        return n % 4 != 0 ;
    }
}
```

# Problem 2
```java
class Solution {
    public int findPoisonedDuration(int[] timeSeries, int duration) {
        if (timeSeries.length == 0)
            return 0;
        int attatckTime = 0;
        int lastAttatckTime = -1;
        
        for (int timeSerie : timeSeries){
            if (lastAttatckTime == -1){
                lastAttatckTime = timeSerie;
                continue;
            }
            if (timeSerie - lastAttatckTime >= duration){
                attatckTime += duration;
            }
            else{
                attatckTime += timeSerie - lastAttatckTime;
            }
            lastAttatckTime = timeSerie;
        }
        attatckTime += duration;
        return attatckTime;
    }
}
```


