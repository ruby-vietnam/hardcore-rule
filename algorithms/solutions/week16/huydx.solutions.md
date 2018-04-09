# Problem 1

```java
class Solution {
    public boolean containsNearbyDuplicate(int[] nums, int k) {
        Map<Integer, Integer> cache = new HashMap<>();
        for (int i = 0; i < nums.length; i++) {
            int n = nums[i];
            if (cache.get(n) != null) {
                int oi = cache.get(n);
                if (i - oi <= k) {
                    return true;
                } 
            }
            cache.put(n, i);
        }
        return false;
    }
}
```

# Problem 2

```java
// too lazy to do binary search tree
class Solution {
    public int findPeakElement(int[] nums) {
        if (nums.length == 1) {
            return 0;
        }
        for (int i = 0; i < nums.length; i++) {
            int nm1 = i == 0 ? Integer.MIN_VALUE : nums[i-1];
            int np1 = i == nums.length-1 ? Integer.MIN_VALUE : nums[i+1];
            if (nums[i] > nm1 && nums[i] > np1) {
                return i;
            }
        }
        return -1;
    }
}
```

