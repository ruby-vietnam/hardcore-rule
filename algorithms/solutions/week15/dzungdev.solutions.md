Problem1: https://leetcode.com/problems/move-zeroes/

We will use 2 pointer approach, we use second variable which is called lastNonZeroValPos to keep the index of the last value which is not 0. 
Then we loop through the array, each time we find the value which is not 0, then we swap it with the lastNonZeroValPos, with this we don't lose data.

for example we have array: [0,1,0,3,12]
so we have the step like this:

1. lastNonZeroValPos = 0, loop index i = 0 => nums[0] = 0 ==> we do nothing
2. lastNonZeroValPos = 0, loop index i = 1 => nums[1] = 1 != 0 => nums[0] = nums[1] =1 (we assign 1 to lastNonZeroValPos = 0 )
                                                                  so the array is: [1,1,0,3,12]
                                                                  increasing lastNonZeroValPos with 1: lastNonZeroValPos++
3. lastNonZeroValPos = 1, loop index i = 2 => nums[2] = 0 ==> do nothing
4. lastNonZeroValPos = 1, loop index i = 3 => nums[3] = 3 != 0 => nums[1] = nums[3] = 3 (we assign 3 to lastNonZeroValPos = 1 )
                                                                  so the array is: [1,3,0,3,12]
                                                                  increasing lastNonZeroValPos with 1: lastNonZeroValPos++
5. lastNonZeroValPos = 2, loop index i = 4 => nums[4] = 12 != 0 => nums[2] = nums[4] = 12 (we assign 12 to lastNonZeroValPos = 2 )
                                                                  so the array is: [1,3,12,3,12]
                                                                  increasing lastNonZeroValPos with 1: lastNonZeroValPos++
So after this step 5th, we loop entire the array and we have lastNonZeroValPos = 3 now, we can assign all element which have position 
from 3 to end of array is 0

```java
  public void moveZeroes(int[] nums) {
    int lastNonZeroValPos = 0;
    for (int i = 0; i < nums.length;i++) {
      if (nums[i] != 0) {
        //Moving the value which is not 0 to the position of lastNonZeroVal
        nums[lastNonZeroValPos] = nums[i];
        lastNonZeroValPos++;
      }
    }
    
    //After the above loop, we can set all the value from lastNonZeroValPos 
    //to end of array is 0
    for (;lastNonZeroValPos < nums.length;lastNonZeroValPos++) {
      nums[lastNonZeroValPos] = 0;
    }
  }
```
