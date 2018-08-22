# Problem 1

## [Middle of the Linked List](https://leetcode.com/problems/middle-of-the-linked-list/description/)
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
    public ListNode middleNode(ListNode head) {
        int size = getListSize(head);
        return get(head, size/2);
    }
    
    private int getListSize(ListNode head) {
        int size = 0;
        while(head != null) {
            ++size;
            head = head.next;
        }
        return size;
    }
    
    private ListNode get(ListNode head, int index) {
        int i = 0;
        while(head != null) {
            if(i == index) {
                return head;
            }
            head = head.next;
            i++;
        }
        
        return null;
    }
}
```
