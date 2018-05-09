/**
 * Let rabbit and turtle run together, rabbit move twice faster than turtle.
 * If rabbit meet turtle at some point in time => There's a cycle.
 * If we meet null => There's no cycle.
 */
/**
 * Definition for singly-linked list.
 * class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) {
 *         val = x;
 *         next = null;
 *     }
 * }
 */
public class Solution {
    public boolean hasCycle(ListNode head) {
        ListNode rabbit = head;
        ListNode turtle = head;
        while (rabbit != null && turtle != null) {
            rabbit = rabbit.next;
            if (rabbit == turtle) return true;
            if (rabbit == null) return false;
            rabbit = rabbit.next;
            if (rabbit == turtle) return true;
            turtle = turtle.next;
        }
        return false;
    }
}
