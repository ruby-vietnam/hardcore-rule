
# Problem 1
``` java
class Solution {
    public boolean containsNearbyDuplicate(int[] nums, int k) {
        if (k < 0){
            k = k* -1;
        } 
        
        HashMap<Integer, Integer> map = new HashMap<>();
        
        for (int i = 0; i < nums.length; i++){
            Integer idx = map.get(nums[i]);
             if (idx != null){
                if (i - idx <= k){
                    return true;
                }
            }
            map.put(nums[i], i); 
        }
        
        return false;
    }
}
```

# Problem 2
``` java
class Solution {
    public int findPeakElement(int[] nums) {
        return findPeakElement(nums, 0, nums.length -1);
    }
    
    private int findPeakElement(int[] nums, int l, int r){
        if (l == r){
            return l;
        }
        
        int mid = (l + r) /2;
        if (nums[mid] > nums[mid +1]){
            return findPeakElement(nums, l , mid);
        }
        else {
            return findPeakElement(nums, mid + 1 , r);
        }
    }
}
```
