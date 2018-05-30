/*
 *
 * Link: https://leetcode.com/problems/sum-of-square-numbers
 *
 * 124 / 124 test cases passed.
 * Status: Accepted
 * Runtime: 4 ms
 * Your runtime beats 100.00 % of c submissions.
 *
 */

bool judgeSquareSum(int c) {
    int b = 0, temp = (int)sqrt(c);

    while(b <= temp) {
        long sum = b * b + temp * temp;
        if (sum == c) {
            return true;
        } else if (sum >= c) {
            temp--;
        } else {
            b++;
        }
    }

    return false;
}
