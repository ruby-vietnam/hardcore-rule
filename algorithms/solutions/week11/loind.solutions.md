# Problem 1

```java
public class Solution {
    public boolean hasCycle(ListNode head) {
        if ( head == null || head.next == null ) return false;
        ListNode prevNode = null;
        ListNode currNode = head;
        ListNode nextNode;
        while( currNode != null ) {
            nextNode = currNode.next;
            currNode.next = prevNode;
            prevNode = currNode;
            currNode = nextNode;
        }
        return ( head == prevNode);
    }
}
```
