/**
 * Problem 1: Intersection of Two Linked Lists
 * https://leetcode.com/problems/intersection-of-two-linked-lists/description/
 */

/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) {
 *         val = x;
 *         next = null;
 *     }
 * }
 */

public class Solution {
  static final ListNode NOT_FOUND = null;
  static final ListNode BLANK = null;

  public ListNode getIntersectionNode(ListNode headA, ListNode headB) {
    if(isBlank(headA) || isBlank(headB)) return NOT_FOUND;

    int lengthA = getListLength(headA);
    int lengthB = getListLength(headB);

    ListNode nextA = headA;
    ListNode nextB = headB;

    if(lengthA > lengthB){
      nextA = skipAndMove(headA, lengthA - lengthB);
    }else{
      nextB = skipAndMove(headB, lengthB - lengthA);
    }

    return findIntersection(nextA, nextB);
  }

  private boolean isIntersectionAt(ListNode nodeA, ListNode nodeB) { return nodeA == nodeB; }
  private boolean isBlank(ListNode node) { return node == BLANK; }

  private int getListLength(ListNode node){
    int listLength = 0;

    while(!isBlank(node)) {
      listLength++;
      node = node.next;
    }

    return listLength;
  }

  private ListNode findIntersection(ListNode startA, ListNode startB){
    while (!isBlank(startA) && !isBlank(startB)){
      if(isIntersectionAt(startA, startB)) return startA;
      startA = startA.next;
      startB = startB.next;
    }

    return NOT_FOUND;
  }

  private ListNode skipAndMove(ListNode head, int numberOfSkipNodes){
    ListNode node = head;

    while(numberOfSkipNodes > 0){
      numberOfSkipNodes--;
      node = node.next;
    }

    return node;
  }
}