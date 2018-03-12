### Problem 2
I saw LOL here

https://leetcode.com/problems/teemo-attacking/description/

```C
int findPoisonedDuration(int* timeSeries, int timeSeriesSize, int duration) {
    int sum = 0;
    int affectedEndTime = 0;
    for (int i=0; i < timeSeriesSize; i++) {
        sum += timeSeries[i] > affectedEndTime ? duration : duration - (affectedEndTime - timeSeries[i]);
        affectedEndTime = timeSeries[i] + duration;
    }
    return sum;
}
```
