Problem1: https://leetcode.com/problems/intersection-of-two-linked-lists/description/

We loop through 2 list to know the tail and size of each list first. If 2 list has intersection, then the tail should be same.
If tail same and the lenghth of 2 list are different, then we find the kth node of longer list, from that we can start running to find the first node of intestion node.

Time complexity is O(n)
Space complexity is O(1)

```java
public class Solution {
  
  private class TailAndSize {
    public ListNode tail;
    public int size;
    
    public TailAndSize(ListNode tail, int size) {
      this.tail = tail;
      this.size = size;
    }
  }
  
  private TailAndSize getTailAndSize(ListNode head) {
    ListNode t = head;
    ListNode tail = null;
    int size = 0;
    while (t != null) {
      size++;
      if (t.next == null) tail = t;
      t = t.next;
    }
    return new TailAndSize(tail, size);
  }
  
  private ListNode getKthNode(ListNode head, int k) {
    ListNode t = head;
    while (k > 0) {
      k--;
      t = t.next;
    }
    return t;
  } 
  
  public ListNode getIntersectionNode(ListNode headA, ListNode headB) {
    TailAndSize tailSize1 = getTailAndSize(headA);
    TailAndSize tailSize2 = getTailAndSize(headB);
    //if tail is different, then we return null
    if (tailSize1.tail != tailSize2.tail) return null;
    
    ListNode longer = tailSize1.size >= tailSize2.size ? headA : headB;
    ListNode shorter = tailSize1.size >= tailSize2.size ? headB : headA;
    
    longer = getKthNode(longer, Math.abs(tailSize1.size - tailSize2.size));
    while (longer != shorter) {
      longer = longer.next;
      shorter = shorter.next;
    }
    
    return longer;
  }
}
```

Problem2: https://leetcode.com/problems/simplify-path/description/

We can use Stack to store the path. Firstly we split the string to string array, the delimiter is "/". 

1. Then we loop through the String array
2. If element is ".." and queue is not empty then we pop()
3. If element is not "..", "." and not blank, then push to stack

After we have stack, then join "/" for stack.

Time Complexity is O(n) and Space complexity is O(n)

```java
public String simplifyPath(String path) {
    Stack<String> stack = new Stack<>();
    String[] files = path.split("/");
    for (String file: files) {
      if (file.equals("..") && !stack.isEmpty()) {
        stack.pop();
      } else if (!file.equals("..") && file.length() > 0 && !file.equals(".")) {
        stack.push(file);
      }
    }
    return "/".concat(String.join("/", stack));
  }
```

Problem3: https://leetcode.com/problems/new-21-game/description/

This is dynamic programming and the most important formula is: f(x)= 1/W * (f(x+1) + f(x+2) + ... + f(x+W-1) + f(x+W) (This formula I only saw it in Solution part of problem and assume it is correct). f(x) is probabilty (percentage) you will have when u have x points. E.g: N = 21 and the problem require u have less than or equal 21, so if u have 19, f(19) = 1 (100%)

so for example: N = 21, K = 17, W = 10
then f(17), f(18), f(19), f(20), f(21) are all 1.0 and f(22) above is 0.0 (As you have 0% to make the point less than or equal 21)
Based on this, we just loop K-1 -> 0 and calculate f(16) = 1/10(f(17) + f(18) + f(19)+ ... + f(17+10))  (17 + 10 because x + W, x = 17 here)

Time complexity is O(n) and space complexity is O()

```java
public double new21Game(int N, int K, int W) {
    double[] f = new double[K+W+1];
    double sum = 0;
    for (int i = K+W; i >= K;i--) {
      f[i] = (i > N) ? 0.0 : 1.0;
      sum += f[i];
    }
    for (int i = K-1;i >= 0; i--) {
      f[i] = sum / W;
      sum += f[i] - f[i+W];
    }
    return f[0];
  }
```

