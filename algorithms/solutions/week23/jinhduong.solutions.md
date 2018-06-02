# #1
```js
/**
 * @param {ListNode} headA
 * @param {ListNode} headB
 * @return {ListNode}
 */
const getIntersectionNode = function (headA, headB) {
    const len1 = len(headA);
    const len2 = len(headB);

    if (len1 === 0 || len2 === 0)
        return null;

    const isLonger = len1 > len2;
    const distance = Math.abs(len1 - len2);

    if (isLonger)
        headA = moveNode(headA, distance);
    else
        headB = moveNode(headB, distance);

    for (let i = 0; i < isLonger ? len1 - distance : len2 - distance; i++) {
        if (headA === headB) {
            return headA;
        }

        headA = headA.next;
        headB = headB.next;
    }

    return null;
};

/**
 * 
 * @param {ListNode} node 
 */
const len = function (node) {
    let len = 0;
    while (node != null) {
        len++;
        node = node.next;
    }
    return len;
}

/**
 * 
 * @param {ListNode} node 
 * @param {number} num 
 */
const moveNode = function (node, num) {
    while (num > 0) {
        node = node.next;
        num--;
    }
    return node;
}
```