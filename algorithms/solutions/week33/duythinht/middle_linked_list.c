/*
* Definition for singly-linked list.
*/
struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* middleNode(struct ListNode* head) {
    struct ListNode *mid = head;
    while (head && head->next) {
        head = head->next->next;
        mid = mid->next;
    }
    return mid;
}
