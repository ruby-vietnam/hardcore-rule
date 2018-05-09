/*
 *
 * Link: https://leetcode.com/problems/merge-k-sorted-lists
 *
 * 131 / 131 test cases passed.
 * Status: Accepted
 * Runtime: 31 ms
 * Your runtime beats 66.84 % of cpp submissions.
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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<int, std::vector<int>, std::greater<int>> q;

        for(auto list: lists) {
            while(list != NULL) {
                q.push(list->val);
                list = list->next;
            }
        }

        if(q.empty()) return NULL;

        ListNode* tail;
        ListNode* result = new ListNode(q.top()); q.pop();
        tail = result;
        while(!q.empty()) {
            tail->next = new ListNode(q.top());
            tail = tail->next;
            q.pop();
        }

        return result;
    }
};
