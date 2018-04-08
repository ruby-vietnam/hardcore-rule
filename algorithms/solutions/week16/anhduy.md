# 219

```c
bool containsNearbyDuplicate(int* nums, int numsSize, int k) {
  for(int i = 0; i < numsSize; i++) {
    for(int j = 1; j <= k && i + j < numsSize; j++) {
      if (nums[i] == nums[i + j])
        return true;
    }
  }
  return false;
}
```

# 162

```c
int findPeakElement(int* nums, int numsSize) {
  int left = 0;
  int right = numsSize - 1;
  while (left < right) {
    int center = (left + right) / 2;
    if (center + 1 <= right && nums[center] < nums[center + 1])
      left = center + 1;
    else
      right = center;
  }
  return left;
}
```
