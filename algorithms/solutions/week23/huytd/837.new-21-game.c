/*
 * [867] New 21 Game
 *
 * https://leetcode.com/problems/new-21-game/description/
 *
 * Status:
 *  ✔ Accepted
 *  ✔ 146/146 cases passed (8 ms)
 *
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
  }
  return dp[0];
}

