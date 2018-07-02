Problem1: https://leetcode.com/problems/non-decreasing-array/description/

When we know the nums[i-1] > nums[i] then we need to make change for nums[i-1] or nums[i]. As we can change at most 1 element, 
so we need to check the nums[i-2] too, if nums[i-2] > nums[i] then we need to change nums[i] = nums[i-1] if not, we just change nums[i-1] = nums[i].

For example: we have 3 5 2 6  => nums[i-2] is 3 and 3 > 2, then we change to 3 5 5 6, then we can know it is true
             we have 3 5 2 3  => nums[i-2] is 3 and 3 > 2, then we change to 3 5 5 3, then we can know it is false when we loop to 2nd 3
             we have 3 5 4 6 ==> nums[i-2] is 3 and 3 < 4, then we change to 3 4 4 6 and it is true
             
Time complexity: O(n)
Space Complexity is O(1)

```java
public boolean checkPossibility(int[] nums) {
        int needChangeCnt = 0;                                                                    
        for(int i = 1; i < nums.length && cnt<=1 ; i++){
          //System.out.println("i : " + i + ",val: " + nums[i]);
            if(nums[i-1] > nums[i]){
                needChangeCnt++;
                if(i-2<0 || nums[i-2] <= nums[i]) nums[i-1] = nums[i];                    
                else nums[i] = nums[i-1];                                                
            }
          /*
          for (int j = 0; j < nums.length; j++) {
            System.out.print(nums[j] + " ");
          }
          System.out.println("");
          */
        }
        return needChangeCnt<=1; 
    }
```

Problem2: https://leetcode.com/problems/permutations/description/

Time complexity is factoria: n!

```java
 private List<List<Integer>> permute(int[] nums, int remainingIndex) {
    List<List<Integer>> results = new ArrayList<>();
    if (remainingIndex == 0) {
      List<Integer> oneElementList = new ArrayList<>();
      oneElementList.add(nums[0]);
      results.add(oneElementList);
      return results;
    } else {
      int curVal = nums[remainingIndex];
      List<List<Integer>> subLists = permute(nums, remainingIndex - 1);
      List<Integer> newList = new ArrayList<>();
      for (List<Integer> subList: subLists) {
        for (int i = 0; i < subList.size();i++) {
          newList = new ArrayList<>(subList);
          newList.add(i, curVal);
          results.add(newList);
        }
        subList.add(curVal);
        results.add(subList);
      }
    }
    return results;
  } 
  
    public List<List<Integer>> permute(int[] nums) {
        return permute(nums, nums.length - 1);
    }
```
