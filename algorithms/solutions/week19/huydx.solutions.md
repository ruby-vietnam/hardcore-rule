# Problem 1

```java
class Solution {
    public int hammingDistance(int x, int y) {
        int z = x ^ y;
        return Integer.bitCount(z);
    }
}
```

# Problem 2

```java
class Solution {
    public List<String> removeInvalidParentheses(String s) {
        List<String> ret = new ArrayList<>();
        Queue<String> toVisit = new LinkedList<>();
        Set<String> visited = new HashSet<>();
        int maxLenOfValid = 0;
        
        toVisit.add(s);
        
        while(true) {
            if (toVisit.isEmpty()) { 
                log("empty, return");
                return ret; 
            }
            String c = toVisit.poll();
            if (c.length() < maxLenOfValid) { 
                log("len < valid, return");
                return ret; 
            }
            if (isValid(c)) {
                ret.add(c);
                maxLenOfValid = c.length();
                continue;
            }
            // visit all sub string of s
            for (int i = 0; i < c.length(); i++) {
                if (c.charAt(i) != '(' && c.charAt(i) != ')') { // just skip character
                    continue;
                }
                String n = replaceAt(c, i);
                if (!visited.contains(n)) {
                    log("add : " + n + " to queue");
                    toVisit.add(n);
                    visited.add(n);
                }
            }
        }
    }
    
    public boolean isValid(String s) {
        log("isValid: s:" + s);
        int stack = 0;
        for (int i = 0; i < s.length(); i++) {
            if (stack < 0) {  // in case )(
                return false; 
            }
            if (s.charAt(i) == '(') {
                stack++;
            } else if (s.charAt(i) == ')') {
                stack--;
            }
        }
        return stack == 0;
    }
    
    public String replaceAt(String s, int i) {
        String sub = s.substring(0, i) + s.substring(i+1);
        log("  replace s: "+s+",i:"+i+",sub:"+sub);
        return sub;
    }
    
    public void log(Object x) {
        if (false) {
            System.out.println(x);
        }
    }
}
```
