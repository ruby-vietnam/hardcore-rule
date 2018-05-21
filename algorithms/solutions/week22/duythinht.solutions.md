### Problem 1

https://leetcode.com/problems/majority-element/description/

```C
int majorityElement(int* nums, int n) {
    int count = 0, major;
    for (int i=0; i<n; i++) {
        if (!count) {
            major = nums[i];
        }
        if (major == nums[i]) {
            ++count;
        } else {
            --count;
        }
        printf("%d,", major);
    }
    return major;
}
```
