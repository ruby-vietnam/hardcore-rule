# #1 Middle of the Linked List
``` csharp
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     public int val;
 *     public ListNode next;
 *     public ListNode(int x) { val = x; }
 * }
 */
public class Solution {
        public ListNode MiddleNode(ListNode head)
        {
            var mid = Len(head) / 2;
            return StartFrom(head, mid);
        }

        public int Len(ListNode root)
        {
            var count = 0;
            var cur = root;
            while (cur != null)
            {
                count++;
                cur = cur.next;
            }
            return count;
        }

        public ListNode StartFrom(ListNode root, int index)
        {
            var count = 0;
            var cur = root;
            while (cur != null && count < index)
            {
                count++;
                cur = cur.next;
            }
            return cur;
        }
}
```