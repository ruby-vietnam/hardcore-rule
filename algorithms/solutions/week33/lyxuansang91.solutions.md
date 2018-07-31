## Problem 1 - [Middle of the Linked List](https://leetcode.com/problems/middle-of-the-linked-list)

We can use once, twice pointer to traverse the list.

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
        ListNode* once = head;
        ListNode* twice = head;
        while (twice != NULL && twice->next != NULL) {
            once = once->next;
            twice = twice->next->next;
        }
        return once;
    }
};
```

## Problem 2 - [Scheduling (Shortest Job First or SJF)](https://www.codewars.com/kata/scheduling-shortest-job-first-or-sjf)

We can find all elements jobs[i] less than jobs[index] (if jobs[i] equal to jobs[index] we compare i less than index).

Time complexity: O(N)

```cpp
int SJF(std::vector <int> jobs, int index){
  // your code here..
  int sum = 0;
  for (int i = 0; i < jobs.size(); ++i) {
    if (jobs[i] < jobs[index] || jobs[i] == jobs[index] && i <= index) 
      sum += jobs[i];
  }
  return sum;
}
```