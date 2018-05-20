# Problem 1

```java
class Solution {
    /** naive
    public int majorityElement(int[] nums) {
        if (nums.length == 1) {
            return nums[0];
        }
        Map<Integer, Integer> counter = new HashMap<>();
        for (int i : nums) {
            Integer c = counter.get(i);
            if (c == null) {
                counter.put(i, 1);
            } else {
                if (c >= nums.length / 2) {
                    return i;
                }
                counter.put(i, c+1);
            }
        }
        throw new IllegalStateException("should not be here");
    }**/
    
    
    // boyer more algorithm
    public int majorityElement(int[] nums) {
        int m = -1;
        int counter = 0;
        for (int i : nums) {
            if (counter == 0) {
                m = i;
                counter = 1;
            } else if (m == i) {
                counter++;
            } else {
                counter--; 
            }
        }
        return m;
    }
}
```

# Problem 3
Idea: traverse both list while maintain a counter to see what current order of current element is. Stop when the counter reach middle of the list length.

```java
import static java.util.Arrays.*;

class Solution {
    class Node {
        int val;
        Node next;
        boolean end; // hate NPE so using end node
        Node(int v) {
            this.val = v;
        }
        boolean isEnd() {
            return this.end;
        }
        
        // for debug
        @Override
        public String toString() {
            StringBuilder sb = new StringBuilder();
            Node cur = this;
            while (cur != null) {
                sb.append("->");
                if (cur.isEnd()) { sb.append("end"); }
                else { sb.append(cur.val); }
                cur = cur.next;                
            }
            return sb.toString();
        }
    }
    
    public double findMedianSortedArrays(int[] nums1, int[] nums2) {
        Node node1 = buildLinkedList(nums1);
        Node node2 = buildLinkedList(nums2);
        Node cur = null;
        int counter = 1;
        int l = nums1.length + nums2.length;
        
        while (true) {
            if (l % 2 == 1 && counter == l/2+1) {
                return cur.val;
            } else if (l % 2 == 0 && counter == l/2) {
                if (node1.isEnd()) { return (cur.val + node2.next.val)/2; }
                if (node2.isEnd()) { return (cur.val + node1.next.val)/2; }
                else return node1.next.val <= node2.next.val ? 
                    (cur.val + node1.next.val)/2:
                    (cur.val + node2.next.val)/2;
            }
            if (node1 == null && node2 == null) {
                throw new IllegalStateException();
            } //no way both node is null;
            
            if (node1.isEnd()) {
                node2 = node2.next;
                cur = node2;
            } else if (node2.isEnd()) {
                node1 = node1.next;
                cur = node1;                
            } else if (node1.val >= node2.val) {
                node1 = node1.next;
                cur = node1;
            } else {
                node2 = node2.next;
                cur = node2;
            }
            counter++;
        }
    }
    
    public Node buildLinkedList(int[] nums) {   
        Node root = null;
        Node cur = null;
        for (int i = 0; i < nums.length; i++) {
            if (i == 0) {
                cur = new Node(nums[i]);
                root = cur;
            } else {
                cur.next = new Node(nums[i]);
                cur = cur.next;
            }
        }
        Node end = new Node(-1);
        end.end = true;
        cur.next = end;
        return root;
    }
    
  public static void debug(Object...os) {
		System.out.println(deepToString(os));
	}
}
```
