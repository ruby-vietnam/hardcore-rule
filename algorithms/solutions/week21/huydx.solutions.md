# Problem 1

```java
class Solution {
    public boolean isAnagram(String s, String t) {
        int[] ss = new int[29];
        int[] ts = new int[29];
        
        for (char sc : s.toCharArray()) {
            ss[sc-'a']++;
        }
        for (char tc : t.toCharArray()) {   
            ts[tc-'a']++;
        }
        for (int i=0; i<ss.length; i++) {
            if (ss[i] != ts[i]) {
                return false;
            }
        }
        return true;
    }
}
```

# Problem 3

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
    public ListNode mergeKLists(ListNode[] lists) {
        ListNode root = null;
        ListNode current = null;
        boolean rootSet = false;
        
        while (true) {
            int min = Integer.MAX_VALUE;
            int idx = -1;
            for (int i = 0; i < lists.length; i++) {
                ListNode node = lists[i];
                if (node == null) {
                    continue;
                }
                if (node.val < min) {
                    min = node.val;
                    idx = i;
                }
            }
                                
            // all nodes is null, break
            if (min == Integer.MAX_VALUE) {
                break;
            }

            // advance minNode
            lists[idx] = lists[idx].next;

            if (rootSet == false) {
                root = new ListNode(min);
                current = root;
                rootSet = !rootSet;
            } else {
                current.next = new ListNode(min);
                current = current.next;
            }

        }
        return root;
    }
}
```
