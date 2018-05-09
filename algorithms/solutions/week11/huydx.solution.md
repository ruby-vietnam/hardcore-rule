# Problem 1

```java
/**
 * Definition for singly-linked list.
 * class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) {
 *         val = x;
 *         next = null;
 *     }
 * }
 */
public class Solution {
    public boolean hasCycle(ListNode head) {
        ListNode slow = head;
        ListNode fast = head;
        while (true) {
            try {
                slow = slow.next;
                fast = fast.next.next;
                if (slow == fast) {
                    return true;
                }
            } catch (Exception ex) {
                // reach null
                return false;
            }
        }
    }
}
```

# Problem 2

```
class Solution {
    public void wiggleSort(int[] nums) {
        Arrays.sort(nums);
        int l = nums.length;
        int[] nums2 = new int[l];
        int left = (l-1)/2;
        int right = l-1;
        for (int i = 0; i < l; i++) {
            if ((i % 2) == 0) {
                nums2[i] = nums[left--];
            } else {
                nums2[i] = nums[right--];
            }
        }
        System.arraycopy(nums2, 0, nums, 0, l);
    }
}
```
