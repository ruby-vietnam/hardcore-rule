## 234. Palindrome Linked List (Easy)

> Given the head of a singly linked list, return true if it is a palindrome.


### Approach

After reading the problem statement, as the first thought, we need to divide the linked list into a smaller list and make the compare by pair.

But the hard thing with the linked list is we can only traverse through it step by step, and if we can NOT count the length of it, we can not determine the center of the list (sure, you can but we should make an extra step to count the number of nodes).

Luckily, we can use 2 pointers, `fast` and `slow`. The strategy is the `slow` pointer traverse the list step by step, one node per jump, the `fast` pointer goes faster (absolutely), two nodes per jump.

```java
slower = slow.next;

faster = faster.next.next;
```
For each step the `slow` pointer makes, we save the value of the passed node into a Stack, it will be very useful to compare the value.

Once the `fast` reach to the end of the list, the `slow` pointer is exactly at the center of the list.

There are two cases here, about the length of the list:

1. It's an even
In this case, the `fast` pointer is `NULL`, and the `slow` pointer is on the right part of the list. 

2. It's an odd
the `faster` pointer is not `NULL`, and the `slow` pointer is exactly the center of the list, we should move it one more step to be on the right side.

At this point, we can easily compare the top of the Stack and `slow` pointer value, if has any mismatch value, we instantly return `FALSE`. And so on, until the Stack is empty, so, we can draw a conclustion that the list is palindrome.

### Submission

```java
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public boolean isPalindrome(ListNode head) {
       Stack<Integer> s = new Stack<>();
        ListNode fast = head;
        ListNode slow = head;

        if (head.next == null) {
            return true;
        }

        while (fast != null && fast.next != null) {
            s.push(slow.val);
            slow = slow.next;
            fast = fast.next.next;
        }

        if (fast != null) {
            slow = slow.next;
        }

        while(!s.isEmpty()) { // even number of nodes
            int top = s.pop();
            if (top != slow.val) {
                return false;
            }

            slow = slow.next;
        }

        return true;
    }
}
```

### Submission detail
```
85 / 85 test cases passed.
Runtime: 7 ms
Memory Usage: 52.7 MB
```

### Complexity
- Time Complexity: O(n)
- Space Complexity: O(n)

## 46. Permutations (Medium)

> Given an array nums of distinct integers, return all the possible permutations. You can return the answer in any order.

### Approach

This problem is kind of most popular in backtracking strategy.

The idea is loop through the array and check whether the nums is already in a temporary array `tmp`. After adding the number to `tmp`, just do the backtrack and select others number.

Whenever the `tmp` is full, add it into the result

### Submission

```java
class Solution {
    public List<List<Integer>> permute(int[] nums) {
        List<List<Integer>> result = new ArrayList<>();
        List<Integer> tmp = new ArrayList<>();

        backtrack(nums, result, tmp);

        return result;
    }

    public void backtrack(int[] nums, List<List<Integer>> result, List<Integer> tmp) {
        if (tmp.size()== nums.length) {
            result.add(new ArrayList<>(tmp));
        } else {
            for (int num : nums) {
                if (tmp.contains(num)) continue;

                tmp.add(num);
                backtrack(nums, result, tmp);
                tmp.remove(tmp.size() - 1);
            }
        }
    }
}
```

### Submission detail

```
25 / 25 test cases passed.
Runtime: 2 ms
Memory Usage: 39.1 MB
```

### Complexity
- Time Complexity: O(n!)
- Space Compexity: O(n)
