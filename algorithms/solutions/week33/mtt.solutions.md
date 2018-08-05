## Problem 1

```c++
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
    int count = 0;
    ListNode* result = head;
    while (head != NULL) {
      count++;
      head = head->next;
      if (count % 2 == 0) result = result->next;
    }
    return result;
  }
};
```

## Problem 2
```c++
int SJF(std::vector <int> jobs, int index) {
  long long int sum = 0;
  for (int i = 0; i < jobs.size(); ++i) {
    if (jobs[i] < jobs[index]) sum += jobs[i];
    if (jobs[i] == jobs[index] && i <= index) sum += jobs[i];
  }
  return sum;
}
```
