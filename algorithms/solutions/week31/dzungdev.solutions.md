Problem1: http://codeforces.com/contest/550/problem/A

We can loop through each character of string, then check if it is start of AB or BA, then have min and max index of AB/BA. If the max index - 1 > min index then there is 2 substrings AB/BA which are not overlapse.

Time complexity is O(n)
Space complexity is O(1)

```java
public static void main(String[] args) {
    int max = Integer.MIN_VALUE;
    int min = Integer.MAX_VALUE;
    
    char[] chars = args[0].toCharArray();
    for (int i = 0; i < chars.length - 1; i++) {
      if ((chars[i] == 'A' && chars[i+1] == 'B') ||
            (chars[i] == 'B' && chars[i+1] == 'A')) {
        if (i > max) max = i;
        if (i < min) min = i;
      }
      i++;
    }
    System.out.print(max - 1 > min ? "YES" : "NO");
  }
```
