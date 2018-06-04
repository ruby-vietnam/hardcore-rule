/* 633. Sum of Square Numbers
 *
 * Status:
 *  ✔ Accepted
 *  ✔ 124/124 cases passed (4 ms)
 *  ✔ Your runtime beats 55 % of c submissions
 */
bool judgeSquareSum(int c) {
  if (sqrt(c) == (int)sqrt(c)) return true;
  for (int b = 1; b < sqrt(c); b++) {
    int a = c - (b * b);
    if (sqrt(a) == (int)sqrt(a)) {
      return true;
    }
  }
  return false;
}
