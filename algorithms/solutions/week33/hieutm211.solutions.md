##Problem 1

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
        ListNode* p;
        int n, cnt;
        
        for (p = head, n = 1; p != NULL; p = p->next) ++n;
        for (p = head, cnt = 1; cnt < (n+1)/2; ++cnt) p = p->next;
        
        return p;
    }
};
```
