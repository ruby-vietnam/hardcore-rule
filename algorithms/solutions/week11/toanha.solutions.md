## Problem 1

https://leetcode.com/problems/linked-list-cycle/description/

Dung 1 bien nhay 1 don vi va 1 bien nhay 2 don vi, neu nhu co loop thi 2 bien nay se gap nhau o dau do

```javascript
/**
 * Definition for singly-linked list.
 * function ListNode(val) {
 *     this.val = val;
 *     this.next = null;
 * }
 */

/**
 * @param {ListNode} head
 * @return {boolean}
 */
var hasCycle = function(head) {
    if (head === null) {
        return false;
    }

    var slow = head;
    var fast = head;

    while(true) {
        if (fast === null || fast.next === null) {
           return false;
        }
        slow = slow.next
        fast = fast.next.next
        if (fast === null) {
            return false;
        }

        if (slow === fast) {
            return true;
        }
    }

    return false;
};

```
