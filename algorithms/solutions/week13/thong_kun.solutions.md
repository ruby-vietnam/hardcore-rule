# Problem 1
``` java
class Solution {
    public int maximumProduct(int[] nums) {
        int maxOne = Integer.MIN_VALUE;
        int maxTwo = Integer.MIN_VALUE;
        int maxThree = Integer.MIN_VALUE;
        
        int minOne = Integer.MAX_VALUE;
        int minTwo = Integer.MAX_VALUE;
        
        for (int num : nums){
            // find maxOne
            if (num > maxOne){
                maxThree = maxTwo;
                maxTwo = maxOne;
                maxOne = num;
            } else if (num > maxTwo){// find maxTwo
                maxThree = maxTwo;
                maxTwo = num;
            } else if (num > maxThree){// find maxThree
                maxThree = num;
            }
            
            if (num < minOne){
                minTwo = minOne;
                minOne = num;
            } else if (num < minTwo){
                minTwo = num;
            }
        }
        
        return Math.max(minOne * minTwo * maxOne, maxOne * maxTwo * maxThree);
    }
}
```
