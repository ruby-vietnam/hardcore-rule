Problem1: https://leetcode.com/problems/majority-element/description/

We can use Divide and Conquer to solve this problem. Idea is we will get the Majority Element of left array and Majority Element of right array. If it is same, then we return it. 
If it is different, we need to count the frequently appear of leftMajority and rightMajority,then return the majority which appears more times.

when we keep split the array to left and right, it will have time the array has only one element, so it can be like (nums, start = 0, end = 0), so one of base case here is if start == end, then return nums[start]

Time Complexity is: O(nlogn) because we still need to count the frequent appear of left and right Majority in array.
Space complexity is: O(logn)

```java
public class MajorityElement {
  
  public int countFrequent(int[] nums, int num, int start, int end) {
    int frequent = 0;
    for (int i = start; i <= end; i++) {
      if (nums[i] == num) frequent++;
    }
    return frequent;
  }

  public int majorityElement(int[] nums) {
    return majorityElement(nums, 0, nums.length - 1);
  }
  
  public int majorityElement(int[] nums, int start, int end) {
    if (start == end) return nums[start];//when we have only one element
    
    int mid = (end - start) / 2 + start;
    int leftMajorityElement =  majorityElement(nums, start, mid);
    int rightMajorityElement = majorityElement(nums, mid + 1, end);
    
    if (leftMajorityElement == rightMajorityElement) return leftMajorityElement;
    
    int leftMajorityElementFreq = countFrequent(nums, leftMajorityElement, start, end);
    int rightMajorityElementFreq = countFrequent(nums, rightMajorityElement, start, end);
    
    return rightMajorityElementFreq > leftMajorityElementFreq ? rightMajorityElement : leftMajorityElement;
  }
  
  public static void main(String[] args) {
    MajorityElement app = new MajorityElement();
    System.out.println(app.majorityElement(new int[] {2,2,1,1,1,2,2,1}));
  }

}
```

