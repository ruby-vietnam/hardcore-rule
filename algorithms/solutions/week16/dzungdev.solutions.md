problem1: https://leetcode.com/problems/contains-duplicate-ii/

We can use HashSet to store the number we loop through, so when we loop until the element at position greater than k, then we just remove the i-k-1 element. 
After that use the Set to check whether can add number into the Set or not.

Time complexity: O(k)

```java
public boolean containsNearbyDuplicate(int[] nums, int k) {
   Set<Integer> set = new HashSet<>();
   for (int i = 0; i < nums.length;i++) {
     if (i > k) {
       set.remove(nums[i-k-1]);
     }
     if (!set.add(nums[i])) return true;
   }
   return false;
  }
```
