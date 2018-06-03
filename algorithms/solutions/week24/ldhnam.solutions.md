# Problem 1
```java
public boolean judgeSquareSum(int c) {
        if (c == 0) return true;
        for (int i = 1; i <= Math.sqrt(c); i++) {
            double res = Math.sqrt(c - i * i);
            if (res % 1 == 0) {
                return true;
            }
        }

        return false;
    }
```
