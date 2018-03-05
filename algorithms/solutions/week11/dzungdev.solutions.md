Problem1:

We can have the Set to contain the visited Nodes in the linked list. So when we go to the cycle, we will meet the start node again.
For example the 3 will be start node of cycle and we will go through 3,4,5,6,3

For example: 1 -> 2 -> 3 -> 4
                       |    |                  |
                       6 <- 5
                       
Time Complexity is O(N) 
Space complexity is O(N)

```java
public boolean hasCycle(ListNode head) {
    Set<ListNode> visitedNodes = new HashSet<ListNode>();
    while (head != null) {
      if (visitedNodes.contains(head)) {
        return true;
      }
      visitedNodes.add(head);
      head = head.next;
    }
    return false;
  }
```
