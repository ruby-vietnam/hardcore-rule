# Problem 2

```java
import java.util.*;
import java.util.*;

public class DirReduction {

  public static String[] dirReduc(String[] arr) {
    debug("start");
  
    Deque<String> stack = new LinkedList<>();
    for (String d : arr) {
      if (!stack.isEmpty() && isRemovable(d, stack.peek())) {
        debug("reduce with", stack.peek(), d);
        stack.pop();
      } else {
        stack.push(d);
      }
    }
    
    debug(stack);
    int l = stack.size();
    String[] ret = new String[l];
    for (int i = 0; i < l; i++) {
      ret[i] = stack.removeLast();
    }
    debug("end");
    return ret;
  }
  
  private static boolean isRemovable(String c, String next) {
    if (c.equals("NORTH")) { return next.equals("SOUTH"); }
    if (c.equals("SOUTH")) { return next.equals("NORTH"); }
    if (c.equals("EAST")) { return next.equals("WEST"); }
    if (c.equals("WEST")) { return next.equals("EAST"); }
    return false;
  }
  
  private static void debug(Object ...objects) {
    if (false) {
      System.out.println(Arrays.deepToString(objects));  
    }
  }
}
```
