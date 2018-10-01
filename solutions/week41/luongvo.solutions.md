# Week 41


## Problem 1 

```java
class Solution {
    public int singleNumber(int[] nums) {
          for(int i=0;i<nums.length-1;i++){
            nums[i+1] ^= nums[i];
          }
          return nums[nums.length-1];
    }
}
```

Submission Detail
16 / 16 test cases passed.
Status: Accepted
Runtime: 1 ms
Submitted: 1 minute ago

