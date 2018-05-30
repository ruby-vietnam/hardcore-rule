/*
 *
 * Link: https://leetcode.com/problems/coin-change
 *
 * 182 / 182 test cases passed.
 * Status: Accepted
 * Runtime: 34 ms
 * Your runtime beats 46.56 % of cpp submissions.
 *
 */

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int Max = amount + 1;
        vector<int> dp(amount + 1, Max);
        dp[0] = 0;
        for (int i = 1; i <= amount; i++) {
            for (int j = 0; j < coins.size(); j++) {
                if (coins[j] <= i) {
                    dp[i] = min(dp[i], dp[i - coins[j]] + 1);
                }
            }
        }

        return dp[amount] > amount ? -1 : dp[amount];
    }
};
