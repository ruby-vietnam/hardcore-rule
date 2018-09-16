# Problem 1: 
https://leetcode.com/problems/reverse-integer/description/

```java
public int reverse(int x) {
    long ret = 0;
    do {
        ret = ret * 10 + x % 10;
        System.out.println(ret);
    } while ((x /= 10) != 0);
    
    if (ret != (int) ret) {
        return 0;
    }
    
    return (int)ret;
}
```