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
 * @param {ListNode} head
 * @return {ListNode}
 */
var middleNode = function(head) {
    let low = head
    let fast = head
    while (fast && fast.next) {
        low = low.next
        fast = fast.next.next
    }
    
    return low
};
```
