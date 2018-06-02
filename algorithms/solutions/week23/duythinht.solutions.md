### Problem 1

https://leetcode.com/problems/intersection-of-two-linked-lists

Explain the solution:

I = Intersection

A = X + I

B = Y + I

A + B = X + I + Y + I = (X + I + Y) + I

B + A = Y + I + X + I = (Y + I + X) + I

```C
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *getIntersectionNode(struct ListNode *a, struct ListNode *b) {
    struct ListNode *x = a, *y = b;
    
    while (x != y) {
        x = x? x->next: b;
        y = y? y->next: a;
    }
    return x;
}

```
