# Problem 1:
#### [Plus One](https://leetcode.com/problems/plus-one/)
```java
class Solution {
    public int[] plusOne(int[] digits) {
        digits[digits.length-1]++;
        for(int i = digits.length-1; i > 0; i--) {
            if(digits[i] == 10) {
                digits[i-1]++;
                digits[i] = 0;
            } else {
                break;
            }
        }
        if(digits[0] < 10) return digits;
        int[] newNumber = new int[digits.length+1];
        newNumber[0] = 1;
        return newNumber;
    }
}
```
