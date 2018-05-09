## Problem 1

https://leetcode.com/problems/linked-list-cycle/description/

- Old trick, 1 pointer 1 step jump and 1 pointer 2 steps jump

```C
bool hasCycle(struct ListNode *head) {
    if (head == NULL)
       return false;

    struct ListNode *slow = head;
    struct ListNode *fast = slow;

    while (true){
        slow = slow->next;
        if (fast->next != NULL) {
            fast = fast->next->next ;
        } else {
            return false ;
        }

        if (slow == NULL || fast == NULL) {
            return false ;
        }

        if (slow == fast) {
            return true ;
        }
    }

    return false;
}
```
