/*
 *
 * Link: https://leetcode.com/problems/longest-increasing-path-in-a-matrix/
 *
 * 137 / 137 test cases passed.
 * Status: Accepted
 * Runtime: 40 ms
 * Your runtime beats 54.93 % of cpp submissions.
 *
 */

class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        if (!rows) return 0;
        int cols = matrix[0].size();

        vector<vector<int>> dirs = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};

        vector<vector<int>> dp(rows, vector<int>(cols, 0));
        std::function<int(int, int)> dfs = [&] (int x, int y) {
            if (dp[x][y]) {
                return dp[x][y];
            }
            for (auto& dir: dirs) {
                int newX = x + dir[0], newY = y + dir[1];
                if (newX < 0 || newX >= rows || newY < 0 || newY >= cols) {
                    continue;
                }
                if (matrix[newX][newY] <= matrix[x][y]) {
                    continue;
                }
                dp[x][y] = max(dp[x][y], dfs(newX, newY));
            }
            return ++dp[x][y];
        };

        int ret = 0;
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                ret = max(ret, dfs(i, j));
            }
        }

        return ret;
    }
};