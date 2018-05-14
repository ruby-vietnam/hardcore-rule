# Problem 1: 169 - Majority Element

Status:
```
Status: Accepted
44 / 44 test cases passed. Runtime: 4 ms
Your runtime beats 100.00 % of c submissions
```

Solution:

```c
int majorityElement(int* nums, int numsSize) {
    int major=nums[0];
    int count = 1;
    for(int i = 1; i < numsSize; i++){
        if(!count){
            count++;
            major = nums[i];
        }else if(major == nums[i]){
            count++;
        }else count--;
    }
    return major;
}
```
