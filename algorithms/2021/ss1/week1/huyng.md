## 1. Palindrome Linked List
### 1.1. Summary
Split the linked list into two half then reverse the second half.
The given linked list is palindrome when each node in two half
completely identity.

### 1.2. Solution summary
| Runtime  | Faster than | Memory   | Less than |
| :----:   | :----:      | :----:   | :----:    |
| 180ms    | 71.72%      | 114.1 MB | 64.86%    |

### 1.3. Source code
```cpp
class Solution {
public:
  bool isPalindrome(ListNode* head) {
    int nElement = 0;
    for (ListNode* cur = head; cur != NULL; cur = cur->next, nElement++) {}

    if (nElement <= 1) {
      return true;
    }

    ListNode* secondHead = head;
    for (int i = nElement / 2 + (nElement&1); i >= 1; i--) {
      secondHead = secondHead->next;
    }

    // Reverse the second chain
    {
      ListNode* prevNode = NULL;
      ListNode* nextNode = NULL;
      while (secondHead != NULL) {
        nextNode = secondHead->next;
        secondHead->next = prevNode;
        prevNode = secondHead;
        secondHead = nextNode;
      }
      secondHead = prevNode;
    }

    for (int i = 1; i <= nElement / 2; i++) {
      if (head->val != secondHead->val) {
        return false;
      }
      head = head->next;
      secondHead = secondHead->next;
    }

    return true;
  }
};
```
