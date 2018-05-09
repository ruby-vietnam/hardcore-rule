# Bai 1: https://leetcode.com/problems/linked-list-cycle/description/
```
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode *slowptr;
        slowptr = head;
        while(slowptr && slowptr->next)
        {
            slowptr = slowptr->next->next;
            head = head->next;
            if(slowptr == head) return true;
        }
        return false;
    }
    
};
```

# Bai 2: https://leetcode.com/problems/wiggle-sort-ii/description/

# Bai 3: https://leetcode.com/problems/odd-even-linked-list/description

```
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
    ListNode* oddEvenList(ListNode* head) {
        if (!head) return head;

        ListNode *odd = head, *evenHead = head->next, *even = evenHead;
        while (even && even->next) {
            odd->next = even->next;
            odd = odd->next;
            even->next = odd->next;
            even = even->next;
        }
        odd->next = evenHead;
        return head;
    }
};
```

# Bonus: https://codefights.com/challenge/FRiBKtwBxvszGc7iE/solutions
Solution by KOV
```
/* The time complexity is O(n log n), sieve of Erathostenes and sort().
 * 
 * first check the basic sequence and try to find the pattern
 *   1 2 3 4 5 6 7 8 9 ...
 * 1 0 1 1 1 1 1 1 1 1
 * 2 0 0 2 2 2 2 2 2 2
 * 3 0 1 0 3 3 3 3 3 3
 * 4 0 0 1 0 4 4 4 4 4
 * 5 0 1 2 1 0 5 5 5 5
 * 6 0 0 0 2 1 0 6 6 6 
 * 7 0 1 1 3 2 1 0 7 7
 * 8 0 0 2 0 3 2 1 0 8
 * 9 0 1 0 1 4 3 2 1 0
 * ...
 * 
 * maybe this view is better:
 * 
 *  A = i % j                  B = j % i 
 *    1 2 3 4 5 6 7 8 9 ...      1 2 3 4 5 6 7 8 9 ... 
 * 1                                               
 * 2  0                   0      1                   1 
 * 3  0 1                 1      1 2                 3
 * 4  0 0 1               1      1 2 3               6
 * 5  0 1 2 1             4      1 2 3 4            10
 * 6  0 0 0 2 1           3      1 2 3 4 5          15
 * 7  0 1 1 3 2 1         8      1 2 3 4 5 6        21
 * 8  0 0 2 0 3 2 1       8      1 2 3 4 5 6 7      28
 * 9  0 1 0 1 4 3 2 1    12      1 2 3 4 5 6 7 8    36
 * ...
 * 
 * where: A(n) = A(n-1) + n - 1 - sum(divisors < n)
 *        B(n) = B(n-1) + n - 1
 * the result is sum(A[1..n]) + sum(B[1..n])
 * 
 * so I'm just use a loop 1..max by 1 to roll A and B values, 
 * and use an array for the sum of the divisors, using sieve of Erathostenes.
 */

tableOfRemainders = n => {
    n = n.sort((a, b) => a - b)
    len = n.length
    max = n[len - 1] + 1
    sum = 0                          // sum of the prev numbers
    mod = 0                          // modulo sum(i mod [1..i])
    ret = 0                          // return value
    p   = 0                          // position (or count of the prev numbers)
    a = new Uint32Array(max)         // modulo decrement values [1..max]

    for (i = 1; i < max; i++) {      // loop 1 to max by 1
        mod += p - a[i]              // calculate sum of i % j (A) at i 
        if (i < n[p]) continue       // if numbers has no i then go to the next        

        m = 0                        // count the similar numbers
        while (n[p] == i) {          
            ret += sum + mod         // result: add sum of prevs and sum mods in each
            m++
            p++
        }
        
        sum += m * i                 // sum of numbers (B): add i, m times
        for (j = i; j < max; ) {     // sieve: add i to divisors at multiplies of i
            j += i
            a[j] += m * i            // add i, m times
        }
    }
    return ret
}

```

