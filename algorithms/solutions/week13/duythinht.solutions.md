### Problem 1

https://leetcode.com/problems/maximum-product-of-three-numbers/description/

```
int compareInt(const int *a ,const int *b) 
{ 
	return *a - *b;
} 
int maximumProduct(int* nums, int numsSize) {
    qsort(nums, numsSize, sizeof(int), &compareInt);
    int result1 = nums[numsSize-1] * nums[numsSize-2] * nums[numsSize-3];
    int result2 = nums[numsSize-1] * nums[1] * nums[0];
    return result1 > result2 ? result1 : result2;
}
```
