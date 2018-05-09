# Problem 1


```java
class Solution {
    public int[] plusOne(int[] digits) {
        int len = digits.length;
        int rem = 0;
        for (int i = len-1; i >= 0; i--) {
            int c = digits[i];
            int n = i == len-1 ? c+1 : c+rem;
            if (n < 10) {
                digits[i] = n;
                return digits;
            } else {
                rem = 1;
                digits[i] = 0;
                if (i == 0) {
                    //need return new array
                    int[] newDigits = new int[len+1];
                    newDigits[0]=1;
                    System.arraycopy(digits, 0, newDigits, 1, len);
                    return newDigits;
                }
            }
        }
        throw new IllegalStateException("should not be here");
    }
}
```
