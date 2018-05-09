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

    /*
     *
     * use O(1) additional memory space
     * still got Accepted with 563 ms runtime
     *
     */
    ListNode* memoryOptimizedMergeKLists(vector<ListNode*>& lists) {
        pair<int, int> minMark = minStream(lists);

        int minIdx = minMark.first;
        int minVal = minMark.second;
        if (minIdx == -1) return NULL;

        ListNode* result = new ListNode(minVal);
        lists[minIdx] = lists[minIdx]->next;

        ListNode* tail;
        tail = result;
        while (true) {
            pair<int, int> minMark = minStream(lists);
            int minIdx = minMark.first;
            int minVal = minMark.second;

            if(minIdx == -1) break;

            tail->next = new ListNode(minVal);
            tail = tail->next;
            lists[minIdx] = lists[minIdx]->next;
        }

        return result;
    }

private:
    pair<int, int> minStream(vector<ListNode*>& lists) {
        int minVal = numeric_limits<int>::max();
        int minIdx = -1;

        for(int i = 0; i < lists.size(); i++) {
            if(lists[i] == NULL) continue;

            int currentVal = lists[i]->val;

            if(currentVal < minVal) {
                minVal = currentVal;
                minIdx = i;
            }
        }

        return make_pair(minIdx, minVal);
    }
};
