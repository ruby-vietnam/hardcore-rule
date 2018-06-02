# Problem 1

```js
/**
 * Definition for singly-linked list.
 * function ListNode(val) {
 *     this.val = val;
 *     this.next = null;
 * }
 */

/**
 * @param {ListNode} headA
 * @param {ListNode} headB
 * @return {ListNode}
 */
var getIntersectionNode = function(ah, bh) {
    let a = ah
    let b = bh
    
    while (a !== b) {
        a = a ? a.next : bh
        b = b ? b.next : ah
    }
    
    return a
};
```
