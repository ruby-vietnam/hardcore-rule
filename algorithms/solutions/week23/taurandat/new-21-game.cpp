/*
 *
 * Link: https://leetcode.com/problems/new-21-game
 *
 * 146 / 146 test cases passed.
 * Status: Accepted
 * Runtime: 10 ms
 * Sorry. We do not have enough accepted submissions to show runtime distribution chart.
 *
 */

class Solution {
public:
    double new21Game(int N, int K, int W) {
        if (K == 0 || N >= K + W) {
            return 1.0;
        }

        vector<double> dp(N + 1);

        dp[0] = 1.0;
        double Wsum = 1.0, res = 0.0;
        for (int i = 1; i <= N; i++) {
            dp[i] = Wsum / W;

            if (i < K) {
                Wsum += dp[i];
            } else {
                res += dp[i];
            }

            if (i >= W) {
                Wsum -= dp[i - W];
            }
        }

        return res;
    }
};