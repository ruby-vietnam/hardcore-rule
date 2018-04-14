# Problem 1

```java
class Solution {
    public boolean isIsomorphic(String s, String t) {
        char base = ' '; //space is first ascii character
        int l = s.length();
        int[] map = new int[200];
        int[] reversemap = new int[200];
        for (int i = 0; i < 200; i++) { 
            map[i] = -1; 
            reversemap[i] = -1;
        }
        
        if (s.length() != t.length()) { return false; }
        
        for (int i = 0; i < s.length(); i++) {
            int sc = s.charAt(i) - base;
            int tc = t.charAt(i) - base;

            if (map[sc] == -1) { 
                map[sc] = tc;
                // check for 2 char could not be mapped into same one
                if (reversemap[tc] != -1 && reversemap[tc] != sc) {
                    return false;
                } else {
                    reversemap[tc] = sc;
                }
            } else {
                // check already map character
                if (map[sc] != tc) {
                    return false;
                }
            }
        }
        return true;
    }
}
```

# Problem 2

```java
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public ListNode rotateRight(ListNode head, int k) {
        if (head == null) { return null; }

        int count = 0;
        ListNode tmp = head;
        while (tmp != null) {
            tmp = tmp.next;
            count++;
        }
        
        k = k % count;
        if (k == 0) { return head; }

        ListNode h = head;
        ListNode hk = head;
        ListNode hk1 = head;
        
        // paralleling move 2 pointers
        for (int i = 0; i < k-1; i++) {
            hk1 = hk1.next;
        }
        hk = hk1.next;
        
        // find end of linked list
        while (hk.next != null) {
            h = h.next;
            hk = hk.next;
            hk1 = hk1.next;
        }
        ListNode newHead = h.next;
        
        
        hk.next = head;
        h.next = null;
        return newHead;
    }
}
```

# Problem 3

```java
import static java.util.Arrays.*;

class Solution {
    public int trap(int[] height) {
        int[] peakLeftIdx = new int[height.length];
        int[] peakRightIdx = new int[height.length];
        
        int peakLeft = 0;
        int peakRight = 0;
        int water = 0;

        for (int i = 1; i < height.length; i++) {
            if (height[i-1] > peakLeft) {
                peakLeftIdx[i] = height[i-1];
                peakLeft = height[i-1];
            } else {
                peakLeftIdx[i] = peakLeftIdx[i-1];
            }
        }
        
        for (int i = height.length-2; i >=0 ; i--) {
            if (height[i+1] > peakRight) {
                peakRightIdx[i] = height[i+1];
                peakRight = height[i+1];
            } else {
                peakRightIdx[i] = peakRightIdx[i+1];
            }
        }

        for (int i = 0; i < height.length; i++) {
            int m = Math.min(peakLeftIdx[i], peakRightIdx[i]);
            if (height[i] < m) {
                water += m - height[i];            
            }
        }
        
        return water;
    }
    
    public static void debug(Object...os) {
        System.out.println(deepToString(os));
    }
}
```
