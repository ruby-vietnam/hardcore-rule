Problem 1:

https://leetcode.com/problems/linked-list-cycle

```
    bool hasCycle(ListNode * head)
    {
        if(!head)
        {
            return false;
        }

        ListNode* mark = new ListNode(0);

        ListNode* curr = head;
        ListNode* next = head->next;
        while(next)
        {
            curr->next = mark;
            if(next == mark)
            {
                return true;
            }
            curr = next;
            next = curr->next;
        }

        return false;
    }
```

Problem 3:

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
