# Problem 1

```java
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) {
 *         val = x;
 *         next = null;
 *     }
 * }
 */
public class Solution {
    public ListNode getIntersectionNode(ListNode headA, ListNode headB) {
        int countA = 0;
        int countB = 0;
        ListNode cA = headA;
        ListNode cB = headB;
        if (headA == null || headB == null) {
            return null;
        }
        while (cA != null) {
            cA = cA.next;
            countA++;
        }
        while (cB != null) {
            cB = cB.next;
            countB++;
        }

        if (countA > countB) {
            return getIntersectionNode0(headA, countA, headB, countB);
        } else {
            return getIntersectionNode0(headB, countB, headA, countA);
        }
    }

    public ListNode getIntersectionNode0(ListNode h, int ch,
                                         ListNode l, int cl) {
        int diff = ch - cl;
        while (diff > 0) {
            h = h.next;
            diff--;
        }
        while (l != null && h != null) {
            if (l == h) {
                return l;
            }
            l = l.next;
            h = h.next;
        }
        return null;
    }
}
```

# Problem 2

```java
import java.util.*;

class Solution {
    public String simplifyPath(String path) {
        String[] ps = path.split("/");
        Deque<String> simplified = new LinkedList<>();
        for (String p : ps) {
            if (p.equals(".")) {
               // continue 
            } else if (p.equals("..")) {
                try {
                    simplified.pop(); 
                } catch (EmptyStackException | NoSuchElementException ignored) {
                }
            } else if (p.length() > 0) {
                simplified.push(p);
            }
        }
        StringBuilder bf = new StringBuilder();
        bf.append("/");
        boolean init = false;
        //System.out.println(simplified);
        
        while (!simplified.isEmpty()) {
            String b = simplified.removeLast();
            if (init) {
                bf.append('/');
            }
            init = true;
            bf.append(b);
        }
        return bf.toString();
    }
}
```
