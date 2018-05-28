/*
 * [867] New 21 Game
 *
 * https://leetcode.com/problems/new-21-game/description/
 *
 * Status:
 *  ✔ Accepted
 *  ✔ 146/146 cases passed (8 ms)
 *
 * Explanation:
 *  The overlapped factor that determine the result of
 *  the game here is the score she get after each draw.
 *  Let call that score i. Let dp[i] be the probability
 *  of i be N or less.
 *  So, the edge case, if K <= i <= N, we probably have
 *  dp[i] = 1.0 (because we already stop playing at K).
 *  The second edge case, is when i > N, the probability
 *  will be dp[i] = 0.0 (obviously, right?).
 *  The recursive formular can be written as:
 *
 *           W
 *  dp[i] = (∑dp[i+j]) / W
 *          j=1
 */
#include <stdio.h>
#include <stdlib.h>

double new21Game(int N, int K, int W) {
  int size = N+W+2;
  double dp[size];
  double sum[size];
  memset(dp, 0.0, size * sizeof(double));
  memset(sum, 0.0, size * sizeof(double));
  for (int i = N+W; i >= 0; i--) {
    if (i > N) continue;
    if (i >= K) dp[i] = 1.0;
    else dp[i] = (sum[i+1] - sum[i+1+W]) / W;

    sum[i] = sum[i+1] + dp[i];

    printf("i=%d S=%f D=%f\n", i, sum[i], dp[i]);
  }
  return dp[0];
}

int main() {
  double result = new21Game(21, 17, 10);
  printf("Result: %f", result);
}
