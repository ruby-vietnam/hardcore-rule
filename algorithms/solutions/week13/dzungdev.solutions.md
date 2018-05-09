Problem1: https://leetcode.com/problems/maximum-product-of-three-numbers/description/

Because the integer can be negative and we can have the case like: {-4,-3,-2,-1,60}
So in this case the Max Product will be: 60 * -4 * -3 instead of 60 * -1 * -2.
So the idea here is: we get 3 biggest number and also 2 smallest negative number, then we calculate the multiple for 2 Max Product
  - firstMaxProd = multiple of 3 biggest number. E.g: 60 * -1 * -2 in above example
  - secondMaxProd = multiple of biggest number with 2 smallest negative number: 60 * -4 * -3 in above example,
Then we return the Max Prod based on max(firstMaxProd, secondMaxProd)

In the case there is only one negative number, then we just do multiple of 3 biggest number.

Time complexity is O(n) and Space complexity is O(n).

```java
public int[] sortedArray(int a, int b, int c) {
 // Find maximum element
    int get_max = Math.max(a, Math.max(b, c));
 
    // Find minimum element
    int get_min = - Math.max(-a, Math.max(-b, -c));
 
    int get_mid = (a+b+c) - (get_max+get_min);
 
    return new int[] {get_min, get_mid, get_max};
  }
  
  public int maximumProduct(int[] nums) {
    
    int[] biggestNumArr = sortedArray(nums[0],nums[1],nums[2]); 
    
    Integer negSmallestNum = null;
    Integer negSecondSmallestNum = null;
    
    for (int i = 0; i < nums.length; i++) {
      int num = nums[i];
      if (num >= 0 && i > 2) {
        if (num >= biggestNumArr[2]) {//biggestNumArr[2] is biggest number
          biggestNumArr[0] = biggestNumArr[1];
          biggestNumArr[1] = biggestNumArr[2];
          biggestNumArr[2] = num;
        } else if (num >= biggestNumArr[1]) {//biggestNumArr[1] is 2nd biggest number
          biggestNumArr[0] = biggestNumArr[1];
          biggestNumArr[1] = num;
        } else if (num >= biggestNumArr[0]) {//biggestNumArr[1] is 3rd biggest number
          biggestNumArr[0] = num;
        }
      } else {//negative
        if (negSmallestNum == null || num <= negSmallestNum) {
          negSecondSmallestNum = negSmallestNum;
          negSmallestNum = num;
        } else if (negSecondSmallestNum == null || num <= negSecondSmallestNum) {
          negSecondSmallestNum = num;
        }
      }
    }
    
    if (negSmallestNum == null || negSecondSmallestNum == null) {
      return biggestNumArr[0] * biggestNumArr[1] * biggestNumArr[2];
    } else {
      int firstMaxProd = biggestNumArr[0] * biggestNumArr[1] * biggestNumArr[2];
      int secondMaxProd = negSmallestNum *  negSecondSmallestNum * biggestNumArr[2];
      return Math.max(firstMaxProd, secondMaxProd);
    }
    
  }
```
