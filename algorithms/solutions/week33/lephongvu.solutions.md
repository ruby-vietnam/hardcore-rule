#Bai 1: https://leetcode.com/problems/middle-of-the-linked-list/description/#_=_

```
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        
        while (fast && fast->next)
        {
            slow = slow->next;
            fast =fast->next->next;
        }
        return slow;
    }
};
```

#Bai 2: https://www.codewars.com/kata/scheduling-shortest-job-first-or-sjf/train/cpp

```
int SJF(std::vector <int> jobs, int index){
  // your code here..
  
  int sum = 0;
  for(int i = 0 ; i < jobs.size(); i++)
  {
    if(jobs[i] < jobs[index]  || (jobs[i] == jobs[index] && i <= index))
      sum += jobs[i];
  }
  
  return sum;
}
```


#Bai 4: https://www.codewars.com/kata/twice-linear/train/cpp 

```
#include <queue>
#include <vector>
#include <algorithm>


class DoubleLinear
{
public:
    static int dblLinear(int n)
    {
      std::priority_queue<int, std::vector<int>, greater<int>> mQ;
      mQ.push(1);
      while(n--)
      {
        int a = mQ.top();
        while (!mQ.empty() && a == mQ.top())
        {
          mQ.pop();
        }
        mQ.push(a*2+1);
        mQ.push(a*3+1);
      }
      return mQ.top();
     }
    
};


