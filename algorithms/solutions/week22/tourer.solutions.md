# Problem 1
#### [Majority Element](https://leetcode.com/problems/majority-element/)
```java
class Solution {
    public int majorityElement(int[] nums) {
        Map<Integer,Integer> map = new HashMap<>();
        int max = nums[0];
        for(int i =0 ; i < nums.length; i++) {
            int count = 0;
            if(map.containsKey(nums[i])) {
                count = map.get(nums[i]);
            }
            if(count + 1 > nums.length /2) {
                max = nums[i];
                break;
            }
            map.put(nums[i], count + 1);
        }
        return max;
    }
}
```

