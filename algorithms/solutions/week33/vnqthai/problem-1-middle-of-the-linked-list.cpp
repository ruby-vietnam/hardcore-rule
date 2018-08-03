/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
  const int MAX = 100;
  public:
  ListNode* middleNode(ListNode* head) {
    ListNode* a[MAX];
    ListNode* p = head;
    int i = 0;
    while (p != nullptr) {
      a[i++] = p;
      p = p->next;
    }

    return a[i/2];
  }
};
