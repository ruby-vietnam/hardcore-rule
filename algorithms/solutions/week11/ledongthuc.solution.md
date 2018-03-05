Problem 1:

https://leetcode.com/problems/odd-even-linked-list

```
    ListNode* oddEvenList(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode* odd = head, *even = head->next, *evenHead = even;
        while(even && even->next){
            odd = odd->next = odd->next->next;
            even = even->next = even->next->next;
        }
        odd->next = evenHead;
        return head;
    }
```
