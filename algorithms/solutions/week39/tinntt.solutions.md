## Problem 1: [Reverse Integer](https://leetcode.com/problems/reverse-integer/description/)

 ```java
public int reverse(int x) {
    int reversedNumber = 0;
    boolean isNegative = x < 0;
    x = Math.abs(x);
    if (x < 0)
        return 0;
    do {
        try {
            reversedNumber = Math.multiplyExact(reversedNumber, 10);
            reversedNumber = Math.addExact(reversedNumber, x % 10);
        } catch (ArithmeticException e) {
            return 0;
        }
        x /= 10;
    } while (x > 0);
    return isNegative ? -reversedNumber : reversedNumber;
}
```