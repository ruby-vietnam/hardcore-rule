# 283

```c
void moveZeroes(int* nums, int numsSize) {
  int lastZeroIndex = -1;
  for (int i = 0; i< numsSize; i++) {
    if(nums[i] == 0) {
      if(lastZeroIndex < 0)
        lastZeroIndex = i;
    } else {
      if (lastZeroIndex > -1) {
        int temp = nums[i];
        nums[i]=nums[lastZeroIndex];
        nums[lastZeroIndex]=temp;
        lastZeroIndex++;
      }
    }
  }
}
```
