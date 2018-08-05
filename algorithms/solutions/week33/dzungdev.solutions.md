Problem1: https://leetcode.com/problems/middle-of-the-linked-list/description/

```java
public ListNode middleNode(ListNode head) {
        ListNode slower = head, faster = head;
    while (faster != null && faster.next != null) {
      slower = slower.next;
      faster = faster.next.next;
    }
    return slower;
    }
```
