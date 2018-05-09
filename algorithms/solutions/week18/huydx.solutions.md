# Problem 1

```java
class MinStack {
    Stack<Integer> data = new Stack<>();
    Stack<Integer> minUntil = new Stack<>(); // hold min value until push last item at `data` stack;
    
    /** initialize your data structure here. */
    public MinStack() {}
    
    public void push(int x) {
        data.push(x);
        if (minUntil.empty()) {
            minUntil.push(x);
        } else {
            minUntil.push(Math.min(minUntil.peek(), x));        
        }
    }
    
    public void pop() {
        if (data.empty()) { return; }
        data.pop();
        minUntil.pop();
    }
    
    public int top() {
        if (data.empty()) { throw new RuntimeException("data is empty"); }
        return data.peek();
    }
    
    public int getMin() {
        if (minUntil.empty()) { throw new RuntimeException("data is empty"); }
        return minUntil.peek();
    }
}

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */
 ```

# Problem 2

```java
class Solution {
    public List<String> restoreIpAddresses(String s) {
        return restoreIpAddressesN(s, 4);
    }
    
    public List<String> restoreIpAddressesN(String s, int n) {
        if (n == 1) {
            return validSubnet(s) ? Arrays.asList(s) : new ArrayList<>();
        }
        List<String> ret = new ArrayList<>();
        for (int i = 1; i <= 3; i++) {
            if (i > s.length()-1) {
                continue;
            }
            String sub = s.substring(0, i);
            if (validSubnet(sub)) {
                List<String> ls = restoreIpAddressesN(s.substring(i, s.length()), n-1); // check index  
                List<String> rs = ls.stream().map(l -> sub + '.' + l).collect(Collectors.toList());
                if (!rs.isEmpty()) {
                    ret.addAll(rs);
                }
            }
        }
        return ret;
    }
    
    public boolean validSubnet(String s) {
        if (s.length() == 0 || s.length() > 3) { return false; }
        if (s.length() > 1 && s.startsWith("0")) { return false; }
        return Integer.valueOf(s) >= 0 && Integer.valueOf(s) <= 255;
    }
}
```
