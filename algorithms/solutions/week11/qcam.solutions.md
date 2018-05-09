# Problem 1

[Floyd's cycle detection](https://en.wikipedia.org/wiki/Cycle_detection#Floyd's_Tortoise_and_Hare).

```java
public class Solution {
  public boolean hasCycle(ListNode head) {
    ListNode tortoise = head;
    ListNode hare = head;

    while (hare != null && hare.next != null) {
      tortoise = tortoise.next;
      hare = hare.next.next; // increase step every time

      if (tortoise == hare) {
        return true;
      }
    }

    return false;
  }
}
```
