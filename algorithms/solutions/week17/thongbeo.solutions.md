# Problem 1
``` java
class Solution {
    public boolean isIsomorphic(String s, String t) {
        if (s.length() != t.length()){
            return false;
        }
        
        char[] sChars = s.toCharArray();
        char[] tChars = t.toCharArray();
        
        HashMap<Character, Character> map = new HashMap<Character, Character>();
        for (int i = 0 ; i < s.length(); i++){
            if (map.get(sChars[i]) == null){
                if (map.containsValue(tChars[i])){
                    return false;
                }
                map.put(sChars[i], tChars[i]);
            } else {
                if (map.get(sChars[i]) != tChars[i]){
                    return false;
                }
            }
        }
        return true;
    }
}
```
# Problem 2
``` java
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
        if (head == null || head.next == null){
            return head;
        } 
        
        int length = getLength(head);
        if (k > length){
            k = k % length;
        }
        
        int count = 0;
        
        while(count < k){
            ListNode last = removeLast(head);
            if (last == null){
                return head;
            }
            head = addFirst(head, last);
            count++;
        }
        return head;
    }
    
    private ListNode removeLast(ListNode head){
        if (head != null){
            ListNode current = head;
            ListNode previous = current;
            while(current.next != null){
                previous = current;
                current = current.next;
            }
            previous.next = null;
            return current;
        }
        return null;
    }
    
    private ListNode addFirst(ListNode head, ListNode node){
        if (head == null){
            head = node;
        } else{
            node.next = head;
            head = node;
        }
        
        return head;
    }
    
    private int getLength(ListNode head){
        int count = 0;
        ListNode current = head;
        while(current != null){
            current = current.next;
            count++;
        }
        return count;
    }
}
```
