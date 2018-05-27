# Problem 1

```java
public class Solution {
    public ListNode getIntersectionNode(ListNode headA, ListNode headB) {
        if (headA == headB){
            return headA;
        }

        if (headA == null || headB == null) {
            return null;
        }

        Map<Integer, Integer> myMap = new HashMap<Integer, Integer>();

        while (headA != null) {
            myMap.put(headA.val, 1);
            headA = headA.next;
        }

        while (headB != null){
            if (myMap.get(headB.val) != null) {
                return headB;
            }
            headB = headB.next;
        }
        return null;
    }
}
```
