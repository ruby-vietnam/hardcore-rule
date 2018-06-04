# Problem 1

## [Intersection of Two Linked Lists](https://leetcode.com/problems/intersection-of-two-linked-lists)
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
        int s1 = getListSize(headA);
        int s2 = getListSize(headB);
        int d = Math.abs(s1-s2);
        if(s1 > s2) {
            headA = moveHead(headA, d);
        } else {
            headB = moveHead(headB, d);
        }
        while(headA != null && headB != null && headA.val != headB.val) {
            headA = headA.next;
            headB = headB.next;
        }
        
        return headA;
    }
    
    private ListNode moveHead(ListNode head, int step) {
        while(step > 0) {
            step--;
            head = head.next;
        }
        return head;
    }
    
    private int getListSize(ListNode head) {
        int size = 0;
        while(head != null) {
            ++size;
            head = head.next;
        }
        return size;
    }
}
```
