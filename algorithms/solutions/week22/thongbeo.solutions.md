#Problem 1
``` Java
class Solution {
    public int majorityElement(int[] nums) { 
        Arrays.sort(nums);
        return nums[nums.length/2];
        
        // HashMap solutions
        // HashMap<Integer, Integer> map = new HashMap<Integer, Integer>();
        // for (int num : nums){
        //     int count = map.getOrDefault(num,0) + 1;
        //     if (count > nums.length /2){
        //         return num;
        //     }
        //     map.put(num, count);
        // }
        // return 0;
    }
}
```
