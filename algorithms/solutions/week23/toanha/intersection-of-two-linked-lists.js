/**
 * Definition for singly-linked list.
 * function ListNode(val) {
 *     this.val = val;
 *     this.next = null;
 * }
 */

/**
 * @param {ListNode} headA
 * @return {int}
 */
function getLen(head) {
  var l = 0;
  while (head != null) {
    head = head.next;
    l++;
  }
  return l
}

/**
 * @param {ListNode} headA
 * @param {ListNode} headB
 * @return {ListNode}
 */
var getIntersectionNode = function(headA, headB) {
  var lenA = getLen(headA);
  var lenB = getLen(headB);
  
  var delta = lenA - lenB;
  var longList = headA;
  var shortList = headB;
  if (delta < 0) {
    delta = -delta;
    longList = headB;
    shortList = headA;
  }

  while (longList != null) {
    if (delta > 0) {
      longList = longList.next;
      delta--;
    } else {
      if (longList == shortList) {
        return longList;
      } else {
        longList = longList.next;
        shortList = shortList.next;
      }
    }
  }
  
  return null;
};
