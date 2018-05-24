var getIntersectionNode = function(headA, headB) {
  var startA = headA;
  var startB = headB;
  var lenA = countList(headA, 0);
  var lenB = countList(headB, 0);

  if (lenA > lenB) {
    startA = moveList(headA, lenA - lenB);
  } else {
    startB = moveList(headB, lenB - lenA);
  }

  return findIntersection(startA, startB);
};

var countList = function(head, count) {
  if (!head) {
    return count;
  } else {
    return countList(head.next, count + 1);
  }
};

var moveList = function(head, step) {
  if (step > 0) {
    return moveList(head.next, step - 1);
  } else {
    return head;
  }
};

var findIntersection = function(nodeA, nodeB) {
  if (nodeA == null) {
    return null;
  } else if (nodeA == nodeB) {
    return nodeA;
  } else {
    return findIntersection(nodeA.next, nodeB.next);
  }
};
