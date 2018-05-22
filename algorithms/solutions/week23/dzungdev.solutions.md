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
