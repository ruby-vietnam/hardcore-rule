## Problem 1 - [Middle of the Linked List](https://leetcode.com/problems/middle-of-the-linked-list)

We can use once, twice pointer to traverse the list.

```cpp
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* once = head;
        ListNode* twice = head;
        while (twice != NULL && twice->next != NULL) {
            once = once->next;
            twice = twice->next->next;
        }
        return once;
    }
};
```