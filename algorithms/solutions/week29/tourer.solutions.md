# Problem 1

## [Count and Say](https://leetcode.com/problems/count-and-say/description/)
```java
class Solution {
    public String countAndSay(int n) {
        if(n == 1) return "1";
        if(n == 2) return "11";
        String  prev = "11";
        for(int i = 3; i <= n; i++) {
            StringBuilder sb = new StringBuilder();
            int count = 1;
            for(int j = 1; j < prev.length(); j++) {
                if(prev.charAt(j) == prev.charAt(j-1)) {
                    ++count;
                } else {
                    sb.append(count);
                    sb.append(prev.charAt(j-1));
                    count = 1;
                }
            }
            sb.append(count);
            sb.append(prev.charAt(prev.length()-1));
            prev = sb.toString();
        }
        return prev;
    }
}
```
