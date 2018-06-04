/*
 *
 * Link: https://leetcode.com/problems/intersection-of-two-linked-lists
 *
 * 42 / 42 test cases passed.
 * Status: Accepted
 * Runtime: 35 ms
 * Your runtime beats 98.66 % of cpp submissions.
 *
 */

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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int lengthA = getLength(headA);
        int lengthB = getLength(headB);

        if (lengthA < lengthB) {
            swap(lengthA, lengthB);
            swap(headA, headB);
        }

        int diff = lengthA - lengthB;
        while(diff--) {
            headA = headA->next;
        }

        while(headA != nullptr && headB != nullptr && headA->val != headB->val) {
            headA = headA->next;
            headB = headB->next;
        }

        return headA;
    }

private:
    int getLength(ListNode *p) {
        int length = 0;

        ListNode *clone = p;
        while(clone != nullptr) {
            length++;
            clone = clone->next;
        }

        return length;
    }
};
