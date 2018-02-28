### Problem 3
https://leetcode.com/problems/odd-even-linked-list/description/

```C
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* oddEvenList(struct ListNode* head) {
    if (head == NULL || head->next == NULL) {
        return head;
    }
    struct ListNode *lastEven = head->next, *lastOdd = head;

    while (lastEven != NULL && lastEven->next != NULL) {
        // Get nextEven, may be NULL or NOT
        struct ListNode *nextEven = lastEven->next->next;

        // Move the next odd to be lastOdd
        lastEven->next->next = lastOdd->next;
        lastOdd->next = lastEven->next;
        lastOdd = lastEven->next;

        // point lastEven to nextEven
        lastEven->next = nextEven;
        lastEven = nextEven;
    }
    return head;
}
```
