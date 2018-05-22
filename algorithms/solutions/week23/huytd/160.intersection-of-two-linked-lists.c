#include <stdio.h>
#include <stdlib.h>
/*
 * [160] Intersection of Two Linked Lists
 *
 * https://leetcode.com/problems/intersection-of-two-linked-lists/description/
 *
 * Status:
 *  ✔ Accepted
 *  ✔ 42/42 cases passed (28 ms)
 *  ✔ Your runtime beats 44.74 % of c submissions
 */

/*
typedef struct ListNode {
  int val;
  struct ListNode *next;
} Node;
*/

struct ListNode *skip_nodes(struct ListNode* node, int count) {
  for (int i = 0; i < count; i++) {
    node = node->next;
  }
  return node;
}

int count_nodes(struct ListNode* node) {
  int c = 0;
  while (node) {
    node = node->next;
    c++;
  }
  return c;
}

struct ListNode *getIntersectionNode(struct ListNode *a, struct ListNode *b) {
  struct ListNode *x = a, *y = b;
  int na = count_nodes(x), nb = count_nodes(y);
  if (na > nb) {
    x = skip_nodes(x, na - nb);
  } else if (na < nb) {
    y = skip_nodes(y, nb - na);
  }
  while (x != y) {
    x = x->next;
    y = y->next;
  }
  return x;
}
