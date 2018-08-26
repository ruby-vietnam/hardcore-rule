Problem1: https://leetcode.com/problems/house-robber/description/

The idea is if the robber meets one house, he will need to make decision to rob that house or not. So the decision will be based on (Max Of House before this house 2 house + this house) compare with Max of Prev House

```java
public int rob(int[] nums) {
        int prevMax = 0;
        int currMax = 0;
        int temp = 0;
        for (int num : nums) {
            //store currMax to make it become prevMax after this element
            temp = currMax;
            currMax = Math.max(prevMax + num, currMax);
            prevMax = temp;
        }
        return currMax;
    }
```
