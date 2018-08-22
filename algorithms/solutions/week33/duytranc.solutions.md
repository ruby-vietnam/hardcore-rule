# Problem 1
#### [Middle of the Linked List](https://leetcode.com/problems/middle-of-the-linked-list/description/)
```cs
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     public int val;
 *     public ListNode next;
 *     public ListNode(int x) { val = x; }
 * }
 */
public class Solution {
    public ListNode MiddleNode(ListNode head) {
        var arrs = new List<ListNode>();
        do{
            arrs.Add(head);
            head = head.next;
        }while(head != null);
        
        return arrs[arrs.Count >> 1];
    }
}
```


