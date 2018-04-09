### Problem 2

```C
int findPeakElement(int* nums, int n) {
    int i = 0;
    while (n > 1) {
        if (nums[i] > nums[(i+1) % n]) {
            return i;
        }
        ++i;
    }
    return i;
}
```
