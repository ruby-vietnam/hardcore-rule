Problem1: https://leetcode.com/problems/plus-one/description/

We loop through all the digit in array and have the variable which is quotient to plus with the number in left if quotient is 1. In the case all the digit is 9, then we need to create new array with length is n+1.

Time complexity is O(n), space complexity is O(n) in worse case as we need to create new array.

```java
public int[] plusOne(int[] digits) {
    int quotient = 0;
    int plusOne = digits[digits.length -1] + 1;
    if (plusOne < 10) {
      digits[digits.length - 1] = plusOne;
      return digits;  
    } else {
      digits[digits.length-1] = plusOne % 10;
      quotient = plusOne / 10;
      for (int i = digits.length - 2; i >= 0; i--) {
        plusOne = digits[i] + quotient;
        if (plusOne == 10) {
          digits[i] = 0; quotient = 1;
        } else {
          digits[i] = plusOne;
          break;
        }
      }
      if (quotient == 1 && digits[0] == 0) {// e.g: [9,9] => [1,0,0]
        int[] result = new int[digits.length+1];
        result[0] = 1;
        for (int i = 1; i < digits.length+1;i++) {
          result[i] = digits[i-1];
        }
        return result;
      } else {
        return digits;
      }
    }
  }
```

Problem2: https://leetcode.com/problems/string-to-integer-atoi/description/

We can do with the step below:
1. Removing the blankspace first
2. check the sign of number is positive or negative
3. Loop through the remaining characters which are after the sign, check if it is not the digit 0 < x < 9, then just break the loop as we don't need to check anymore
4. While we loop, need to check the result >= Integer.MAX_VALUE then return Integer.MAX_VALUE, if it is smaller than Integer.MIN_VALUE, then return Integer.MIN_VALUE

```java
  public int myAtoi(String str) {
    if (str == null || str.isEmpty())
      return 0;
    int index = 0, sign = 1, len = str.length(), result = 0;
    // remove all space
    while (index < len && str.charAt(index) == ' ') {
      index++;
    }
    
    //check sign
    if (index < len && (str.charAt(index) == '-' || str.charAt(index) == '+')) {
      sign = str.charAt(index) == '+' ? 1 : -1;
      index++;
    }

    //loop through the characters which is after sign: -/+
    for (; index < len; index++) {
      int c = str.charAt(index) - '0';
      if (c < 0 || c > 9)
        break;// if it is character which is not digit, then don't need to check the remaining characters
      if (result > Integer.MAX_VALUE / 10 ||
            (result == Integer.MAX_VALUE / 10 && Integer.MAX_VALUE % 10 < c)) {
        return sign == 1 ? Integer.MAX_VALUE : Integer.MIN_VALUE;
      }
      result = result * 10 + c;
    }
    
    return sign * result;
  }
```
