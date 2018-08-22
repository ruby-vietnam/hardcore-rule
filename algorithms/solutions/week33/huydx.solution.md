# Problem 1
simply slow/fast pointer trick

```java
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public ListNode middleNode(ListNode head) {
        ListNode n1 = head;
        ListNode n2 = head;
        while (n2 != null && n2.next != null) {
            n1 = n1.next;
            n2 = n2.next.next;
        }
        return n1;
    } 
}
```

# Problem 2
priority queue and TreeSet both work, but I like TreeSet

```java

    static class Node {
        int idx;
        int val;

        public Node(int idx, int val) {
            this.idx = idx;
            this.val = val;
        }
    }

    static int SJF(int[] jobs, int index) {
        TreeSet<Node> nodes = new TreeSet<>((o1, o2) -> {
            if (o1.val == o2.val) {
                return Integer.compare(o1.idx, o2.idx);
            } else {
                return Integer.compare(o1.val, o2.val);
            }
        });
        for (int i = 0; i < jobs.length; i++) {
            nodes.add(new Node(i, jobs[i]));
        }
        int sum = 0;
        while (!nodes.isEmpty()) {
            if (nodes.first().idx == index) {
                return sum + nodes.first().val;
            } else {
                sum += nodes.first().val;
                nodes.remove(nodes.first());
            }
        }
        return sum;
    }

```
