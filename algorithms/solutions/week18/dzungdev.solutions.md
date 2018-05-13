Problem1: https://leetcode.com/problems/min-stack/description/

```java
import java.util.EmptyStackException;

class MinStack {

    /** initialize your data structure here. */
   private static class StackNode {
    private int val;
    private StackNode next;
    
    public StackNode(int val) {
      this.val = val;
    }
  }
  
  private StackNode top;
  private int min = Integer.MAX_VALUE;
  
  public MinStack() {}
  
  public void push(int x) {
    StackNode newTop = new StackNode(x);
    newTop.next = top;
    top = newTop;
    if (x < min) min = x;
  }
  
  public void pop() {
    if (top == null) throw new EmptyStackException();
    if (top.val == min) {
      StackNode temp = top.next;
      min = Integer.MAX_VALUE;
      while (temp != null) {
        if (temp.val < min) min = temp.val;
        temp = temp.next;
      }
    }
    top = top.next;
  }
  
  public int top() {
    if (top == null) throw new EmptyStackException();
    return top.val;
  }
  
  public int getMin() {
    if (top == null) throw new EmptyStackException();
    return min; 
  }
}
```

Problem2: https://leetcode.com/problems/restore-ip-addresses/description/
We will use backtracking with DFS to do this problem. I am preparing the detail tree step with smaller example like: 12345 and each segment has 2 digit only
. E.g: 1.23.45 is valid or 12.3.45 is valid
I will upload it soon.

```java
import java.util.ArrayList;
import java.util.List;

class Solution {
    public List<String> restoreIpAddresses(String s) {
         List<String> results = new ArrayList<>();
    backtracking(s, 0, "", results);
    
    return results;
    }
  
  private void backtracking(String remainString, int level, String temp, List<String> results) {
    // System.out.println(generateTab(level) + "level: " + level + ", remainString: " + remainString);
    if (level == 4 && remainString.length() == 0) {
      results.add(temp.substring(0, temp.length()-1));
      return;
    }
    if (level == 4) return;
    
    int numToLoop = remainString.length() >= 3 ? 3 : remainString.length();
    for (int i = 1; i <= numToLoop;i++) {
      String newLetter = remainString.substring(0, i);
      // System.out.println(generateTab(level) + "level: " + level + ", newLetter: " + newLetter);
      if (isValidData(newLetter)) {
        temp += newLetter + ".";
        // System.out.println(generateTab(level) + "level: " + level + ", temp BEFORE bt: " + temp);
        // System.out.println(generateTab(level) + "level: " + level + ", remainString.substring(i): " + remainString.substring(i));
        backtracking(remainString.substring(i), level + 1, temp, results);
        temp = temp.substring(0, temp.lastIndexOf(newLetter));//backtracking to recover the temp before temp += newLetter + "."
      }
    }
      
  }
  
  private String generateTab(int level) {
    String tabs = "";
    for (int i = 0; i < level; i++) {
      tabs += "\t";
    }
    return tabs;
  }
  
  public boolean isValidData(String s){
    if(s.charAt(0)=='0')
      return s.length()==1;
    Integer result=Integer.parseInt(s);
    if(result>255)
      return false;
    return true;
  }
}
```
