### Problem 1: https://leetcode.com/problems/middle-of-the-linked-list/description/

```C++
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode *tmp = head;
        while (tmp != NULL) {
            tmp = tmp -> next;
            if (tmp == NULL) break;
            head = head -> next;            
            tmp = tmp -> next;
        };
        return head;
    }
};
```
