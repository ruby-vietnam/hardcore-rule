Problem 1:

https://leetcode.com/problems/intersection-of-two-linked-lists/description/

```java
public class Solution {
    public ListNode getIntersectionNode(ListNode headA, ListNode headB) {
        if (headA == null || headB == null) return null;
        
        int numA = 0, numB = 0;
        ListNode nA = headA, nB = headB, longList = null, shortList = null, commonNode = null;
        while(nA != null){
            numA++;
            nA = nA.next;
        }
        while(nB != null){
            numB++;
            nB = nB.next;
        }

        longList = (numA >= numB ? headA : headB);
        shortList = (numA >= numB ? headB : headA);
        for (int i = 0; i < Math.abs(numA - numB); i++){
            longList = longList.next;
        }
        while(longList != null){
            if (commonNode == null && longList == shortList){
                commonNode = longList;
            }
            if (commonNode != null && longList != shortList)
                return null;
            longList = longList.next;
            shortList = shortList.next;
        }

        return commonNode;
    }
}
```

