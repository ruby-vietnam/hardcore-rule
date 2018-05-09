# Problem set 1

```js
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
    let slow, fast

    if(!head || !head.next) return false

    slow = head
    fast = head

    if(head.next === head) return true

    while(fast.next && fast.next.next) {
        slow = slow.next
        fast = fast.next.next

        if(slow === fast) return true
    }

    return false
};
```
