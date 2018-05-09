/*
 *
 * Link: https://leetcode.com/problems/merge-k-sorted-lists
 *
 * 131 / 131 test cases passed.
 * Status: Accepted
 * Runtime: 29 ms
 * Your runtime beats 92.26 % of cpp submissions.
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
        ListNode* result = new ListNode(0);

        auto cmp = [](const pair<int, int>& lhs, const pair<int, int>& rhs) {
            return lhs.second > rhs.second;
        };

        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> q(cmp);

        for(int i = 0; i < lists.size(); i++) {
            if(lists[i] != nullptr) {
                int val = lists[i]->val;
                q.push(make_pair(i, val));
                lists[i] = lists[i]->next;
            }
        }

        ListNode* tail = result;
        while(!q.empty()) {
            int idx = q.top().first;
            int val = q.top().second;

            tail->next = new ListNode(val);
            tail = tail->next;

            q.pop();

            if (lists[idx] != nullptr) {
                int val = lists[idx]->val;
                q.push(make_pair(idx, val));
                lists[idx] = lists[idx]->next;
            }
        }

        return result->next;
    }
};
