# Problem 1: Intersection of Two Linked Lists

https://leetcode.com/problems/intersection-of-two-linked-lists/description/

```
Runtime: 65 ms
Your runtime beats 6.56 % of cpp submissions.
```

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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
      int sizeA = 0;
      ListNode *tempA = headA;
      while(tempA) {
        sizeA++;
        tempA = tempA->next;
      }
      int sizeB = 0;
      ListNode *tempB = headB;
      while(tempB) {
        sizeB++;
        tempB = tempB->next;
      }
      if (sizeA >= sizeB) {
        while(sizeA - sizeB > 0) {
          headA = headA->next;
          sizeA--;
        }
      }
      else {
        while(sizeB - sizeA > 0) {
          headB = headB->next;
          sizeB--;
        }
      }
      while(headA && headB) {
        if(headA == headB) {
          return headA;
        }
        headA = headA->next;
        headB = headB->next;
      }
      return NULL;
    }
};
```

# Problem 2: Simplify Path

https://leetcode.com/problems/simplify-path/description/

```
Runtime: 44 ms
Your runtime beats 85.71 % of ruby submissions.
```

```ruby
# @param {String} path
# @return {String}
def simplify_path(path)
  path = path.split('/')
  i = 0
  while i < path.length
    if path[i] == '..'
      if i > 0
        path.delete_at(i - 1)
        i -= 1
      end
      path.delete_at(i)
    elsif path[i] == '.' || path[i] == ''
      path.delete_at(i)
    else
      i += 1
    end
  end
  '/' + path.select { |x| x }.join('/')
end
```
