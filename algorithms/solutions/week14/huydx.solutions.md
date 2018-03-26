# Problem 1

```
class Solution {
    public boolean isPowerOfFour(int num) {
        if (num == 4) { return true; } 
        if (num == 1) { return true; }
        if (num % 4 != 0) { return false; }
        if (num > 4) { return isPowerOfFour(num/4); }
        return false;
    }
}
```
