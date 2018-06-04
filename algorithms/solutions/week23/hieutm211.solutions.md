#problem 1

```cpp
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
      int szA, szB;

      szA = 0;
      ListNode *tmpA = headA;
      while(tmpA) {
        szA++;
        tmpA = tmpA->next;
      }
      szB = 0;
      ListNode *tmpB = headB;
      while(tmpB) {
        szB++;
        tmpB = tmpB->next;
      }

      if (szA >= szB) {
        while(szA - szB > 0) {
          headA = headA->next;
          szA--;
        }
      }
      else {
        while(szB - szA > 0) {
            headB = headB->next;
          szB--;
        }
      }

      while(headA && headB) {
        if(headA == headB) {
          return headA;
        }
        headA = headA->next;
        headB = headB->next;
      }
      return NULL;
    }
};
```